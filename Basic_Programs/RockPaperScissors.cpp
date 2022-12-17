#include <iostream>
#include <string>

char genPlayer_choice()
{
    char choice;

    std:: cout << "----> ";
    std:: cin >> choice; 

    if((choice != 'r' && choice != 'R') && (choice != 's' && choice != 'S') && (choice != 'p' && choice != 'P'))
    {
        std :: cout << "Invalid choice entered !! Enter again :\n";
        genPlayer_choice();
    }
    return choice;
}

char genComp_choice()
{
    srand(time(NULL));
    int choice = (rand() % 3) + 1;

    switch(choice)
    {
        case 1:
        {
            return 'R';
        }

        case 2:
        {
            return 'P';
        }

        case 3:
        {
            return 'S';
        }
    }
    return '0';
}

int compChoices(char P, char C)
{
    P = toupper(P);
    if(P == C)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void winner(char P, char C, int tie)
{
    P = toupper(P);
    if(tie == 1)
    {
        std :: cout << "You both Tied !! Try again !\n";
    }
    else if((P == 'R' && C == 'P') && (P == 'S' && C == 'P') && (P == 'R' && C == 'S'))
    {
        std :: cout << "You won !! You chose " << P << " and the Computer chose " << C << "\n\n";
    }
    else
    {
        std :: cout << "You Lose !! You chose " << P << " and the Computer chose " << C << "\n\n";
    }
}

int main()
{
    char player;
    char computer;
    char ch;
    do
    {
        std::cout << "\n**********ROCK PAPER SCISSORS !!!**********\n\n Enter R for ROCK, P for PAPER or S for SCISSORS: ";
        player  = genPlayer_choice();

        computer = genComp_choice();

        int t = compChoices(player, computer);
        
        winner(player , computer, t);
        
        std::cout << "Wanna play again? (Y/N) : " << "\n";
        std::cin >> ch;
    }while(ch != 'n' && ch != 'N');
    
    std::cout << "\n\nThanks for playing !!\n\n";

    return 0;
}