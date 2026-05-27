#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> convert(const std::string& word)
{
        std::vector<std::string> result;

        int combinations = 1 << word.length(); // 2^length

        for (int mask = 0; mask < combinations; mask++)
        {
                std::string temp = word;

                for (int i = 0; i < word.length(); i++)
                {
                        if (mask & (1 << i))
                                temp[i] = std::toupper(temp[i]);
                        else
                                temp[i] = std::tolower(temp[i]);
                }

                result.push_back(temp);
        }

        return result;
}

int main()
{
        std::vector<std::string> words = convert("apple");

        for (const auto& w : words)
                std::cout << w << '\n';
}
