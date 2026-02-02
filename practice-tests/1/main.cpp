/*
Write a function that takes a vector of integers and returns the sum of all even
numbers in it.

Input: {1, 2, 3, 4, 5, 6}
Output: 12 (because 2+4+6=12)
*/

#include <iostream>
#include <vector>

int main() {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
        std::vector<int> temp = {};
        int temp1 = 0;

        for (int i = 0; i < numbers.size(); i++) {
                if (numbers[i] % 2 == 0) {
                        temp.push_back(numbers[i]);
                }
        }

        for (int i = 0; i < temp.size(); i++) {
                temp1 += temp[i];
        }

        std::cout << temp1 << '\n';

        return 0;
}

// std::vector<int> numbers = {1, 2, 3};        - creates vector with 3 ints
// numbers.size()                               - gets length
// numbers[i]                                   - access element at index i
// (like arrays) numbers.push_back(5)                         - adds element to
// end
