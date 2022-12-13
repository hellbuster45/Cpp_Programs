#include <iostream>

int main()
{
    srand(time(NULL));
    int num = 0, count = 1;
    int rnum = ((rand() % 20) + 1);

    do
    {
        std::cout << "Enter any number (1-20)\n";
        std::cin >> num;

        if(num < rnum)
        {
            count++;
            std::cout << "Number is higher!! Try again!\n";
            continue;
        }
        else if(num > rnum)
        {
            count++;
            std::cout << "Number is lower!! Try again!\n";
            continue;
        }
        else
        {
            break;
        }
    }while(num != rnum || count != 10);

    if(count == 10)
    {
        std::cout << "You've lost the game!!\n";
    }
    else
    {
        std::cout << "You've guessed the number in " << count << " tries!!\n";
    }
}