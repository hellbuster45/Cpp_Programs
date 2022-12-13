#include <iostream>
#include <string>

double balance = 0;

double getBalance()
{
    return balance;
}

void addBalance()
{
    double amt;
    std::cout << "Enter amount to be deposited : ";
    std::cin >> amt;
    balance += amt;
    std::cout << "Amount deposited successfully !! \n New Balance is: " << balance << "\n\n";
}

void withdrawBalance()
{
    double amt;
    std::cout << "Enter amount to be withdrawn : ";
    std::cin >> amt;
    
    if(amt < balance)
    {
        balance -= amt;
        std::cout << "Amount withdrawn successfully !! \n New Balance is: " << balance << "\n\n";
    }
    else
    {
        std::cout << "You don't even have that much money bruh -_- poor ass lol\n\n";
    }
}


void createAccount()
{
    double amt;
    std::cout << "Enter initial amount to be deposited (Minimum  amount required: 2000/-): ";
    std::cin >> amt;
                
    if(amt > 2000)
    {
        balance += amt;
        std::cout << "Your account has been created :D !! with initial balance of:" << balance << "\n\n";
    }
    else
    {
        std::cout <<"Minimum amount of atleast 2000/- is required !! \n\n";
    }
}

int main()
{
    int choice;

    std:: cout << "Welcome to Banking!!\n\n What would you like to do?\n";
    do
    {
        std::cout << "1--> Create Account\n2--> Deposit Money\n3--> Withdraw Money\n4--> See Available Balance\n0--> Exit\n\nEnter your choice: ";
        std::cin >> choice;
        switch(choice)
        {
            case 1: 
            {
                createAccount();
                break;
            }

            case 2:
            {
                addBalance();
                break;
            }

            case 3:
            {
                withdrawBalance();
                break;
            }

            case 4:
            {
                std::cout << "Available Balance is: " << getBalance() << " !!\n";
                break;
            }

            case 0:
            {
                break;
            }

            default:
            {
                std::cout << "Can't you read bitch?! Enter a valid choice >:( !!\n\n";
                break;
            }
        }
    }while(choice != 0);

    std::cout << "Thanks for using our Banking service !!\n";

    return 0;
}