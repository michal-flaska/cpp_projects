#include <iostream>

float calc(int num1, int num2, char op){
        switch(op){
                case '+': return num1 + num2;
                case '-': return num1 - num2;
                case '*': return num1 * num2;
                case '/': return (float)num1 / num2;
        }

        std::cout << "invalid op\n";

        return 0;
}

void ask(int &num1, int &num2, char &op){
        std::cout << "enter number 1: ";
        std::cin >> num1;

        std::cout << "enter number 2: ";
        std::cin >> num2;

        std::cout << "enter operator (+ - * /): ";
        std::cin >> op;

        while(op != '+' && op != '-' && op != '*' && op != '/'){

                std::cout << "Wrong operator, only +, -, *, / are available" << '\n';
                std::cout << "please enter operator again: ";
                std::cin >> op;
        }

        while(op == '/' && num2 == 0){
                std::cout << "cant divide by 0, enter number 2 again: ";
                std::cin >> num2;
        }
}

int main()
{
        int num1 = 0;
        int num2 = 0;

        char op = ' ';
        float result = 0;

        char calcAgainAnswer = 'y';

        while(calcAgainAnswer == 'y')
        {
                ask(num1, num2, op);

                std::cout << "result: " << (result = calc(num1, num2, op)) << '\n' << '\n';
                std::cout << "want to calculate again? (y/n): ";
                std::cin >> calcAgainAnswer;

                while(calcAgainAnswer != 'y' && calcAgainAnswer != 'n'){
                        std::cout << "y or n: ";
                        std::cin >> calcAgainAnswer;
                }
        }

        return 0;
}

/*
must have
input: number operator number
example: 5 + 3
support:
+
-
*
/
print result
*/
