#include <iostream>
#include <cmath>

int main()
{
    float num1, num2;
    int choice = 0;

    std::cout << "\n\nSimple 2 number calculator!!\n\n";
    
    do
    {
        std::cout << "1--> Addition\n2--> Subtraction\n3--> Multiplication\n4--> Division\n5--> Find remainder(Decimal numbers not supported!!)\n6--> Find (number) raise to power (number)\n7--> Find Square root\n0--> Exit program\n\nEnter your choice: ";
        std::cin >> choice;

        switch(choice)
        {
            case 1:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Addition of %.2f and %.2f is: %.2f\n\n", num1, num2, (num1 + num2));
                break;
            }    

            case 2:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Subtraction of %.2f and %.2f is: %.2f\n\n", num1, num2, (num1 - num2));
                break;
            }

            case 3:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Multiplication of %.2f and %.2f is: %.2f\n\n", num1, num2, (num1 * num2));
                break;
            }

            case 4:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Division of %.2f and %.2f is: %.2f\n\n", num1, num2, (num1 / num2));
                break;
            }

            case 5: 
            {
                int num1, num2;
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Remainder after dividing %d and %d is: %d\n\n", num1, num2, (num1 % num2));
                break;
            }

            case 6:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("%.2f raised to power %.2f is: %.2f\n\n", num1, num2, pow(num1, num2));
                break;
            }

            case 7:
            {
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                printf("Square root of %.2f is: %.2f\nSquare root of  %.2f is: %.2f\n\n", num1, sqrt(num1), num2, sqrt(num2));
                break;
            }

            case 0:
            {
                std::cout << "You have exited the program!!\n\n";
                break;
            }

            default:
            {
                std::cout << "Invalid choice entered!!\n\n";
            }
        }
    }while(choice != 0);

    
    
    return 0; 
}