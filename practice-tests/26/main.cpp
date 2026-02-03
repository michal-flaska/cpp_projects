// Write a function that converts a decimal number to binary and returns it as a string.

// Examples:
// - 5 → "101"
// - 10 → "1010"
// - 0 → "0"
// - 255 → "11111111"

// Function: std::string toBinary(int n)

// Hints:
// - Repeatedly divide by 2
// - The remainders (n % 2) give you the binary digits, but in reverse order
// - Keep dividing until n becomes 0
// - Reverse the result at the end (or build it from the front)

// Example with 10:
// - 10 / 2 = 5, remainder 0
// - 5 / 2 = 2, remainder 1
// - 2 / 2 = 1, remainder 0
// - 1 / 2 = 0, remainder 1
// - Read remainders backwards: 1010

#include <iostream>
#include <vector>

void reverseVector(std::vector<int> &v) {        // https://www.wscubetech.com/resources/cpp/programs/reverse-array
                                                // because im a dumb fuck and i always forget how to reverse an array

        int size = v.size();

        for (int i = 0; i < size / 2; i++) {
                int temp = v[i];
                v[i] = v[size - 1 - i];
                v[size - 1 - i] = temp;
        }
}

std::vector<int> convertToBinary(int n){

        std::vector<int> partialResult = {};

        int remainder;

        while(n != 0){
                remainder = n % 2;
                n = n / 2;
                partialResult.push_back(remainder);
        }

        return partialResult;
}

int main(){

        int n = 10; // 1010

        std::vector<int> partialBinaryNumber = convertToBinary(n);

        reverseVector(partialBinaryNumber);

        for(int i = 0; i < partialBinaryNumber.size(); i++){
                std::cout << partialBinaryNumber[i];
        }

        return 0;
}
