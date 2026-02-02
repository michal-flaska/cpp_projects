#include <iostream>
#include <iostream>

std::string xor_strings(const std::string &text, const std::string &key)
{
        std::string result = text;

        for (size_t i = 0; i < text.length(); i++)
        {
                result[i] = text[i] ^ key[i % key.length()];

                // im using modulo (% key.length()) to repeat the key if its shorter than the text

                // the `% key.length()` makes it work even if the key is shorter. it wraps around

                // example:
                // - text: "hello world" (11 chars)
                // - key: "abc" (3 chars)

                // it does:
                // - h ^ a (i=0, 0%3=0)
                // - e ^ b (i=1, 1%3=1)
                // - l ^ c (i=2, 2%3=2)
                // - l ^ a (i=3, 3%3=0) <- wraps back to start
                // - o ^ b (i=4, 4%3=1)
                // - etc.

                // the key just repeats until it covers the whole text. that's standard for XOR encryption.
        }

        return result;
}

// -------------------------------------------------------------------------------------

int main()
{
        int a = 5;     // 0101 in binary
        int b = 3;     // 0011 in binary
        int c = a ^ b; // 0110 = 6

        // Bit by bit:
        // 0^0=0, 1^0=1, 0^1=1, 1^1=0

        // xor table, i guess
        //      0 ^ 0 = 0
        //      0 ^ 1 = 1
        //      1 ^ 0 = 1
        //      1 ^ 1 = 0

        std::cout << "a: " << a << '\n'
                  << "b: " << b << '\n'
                  << "c: " << c << '\n'
                  << '\n';

        // -----------------------------------------------------------------------------
        // unfortunately, you can not xor strings so easily like you can string integers
        // -----------------------------------------------------------------------------

        std::string x = "hello world";
        std::string key = "abc";

        std::string encrypted = xor_strings(x, key);
        std::string decrypted = xor_strings(encrypted, key);

        std::cout << "encrypted string: " << encrypted << '\n';
        std::cout << "decrypted string: " << decrypted;
}
