#include<iostream>
#include<string>

void drawboard(char *spaces, int sz)
{
    std::cout << "\n";
    std::cout << "*******************************************************\n";
    std::cout << " " << spaces[0] << " " << "|" << " " << spaces[1] << " " << "|" << " " << spaces[2] << " " << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << spaces[3] << " " << "|" << " " << spaces[4] << " " << "|" << " " << spaces[5] << " " << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << spaces[6] << " " << "|" << " " << spaces[7] << " " << "|" << " " << spaces[8] << " " << "\n";
    std::cout << "\n";
}

void computerPos(char *spaces, char token)
{
    srand(time(NULL));
    int pos = rand() % 9;
    while(spaces[pos] != ' ')
    { 
        pos = rand() % 9;
        //std::cout << pos << "\n\n";
    }
    spaces[pos] = token;
}

void playerPos(char *spaces, char token, int pos)
{

    std::cout << "Enter a postion you want to place your token: (1-9)";
    std::cin >> pos;

    if(pos < 1 || pos > 9)
    {
        std::cout << "Invalid position entered try again!!\n\n";
        playerPos(spaces, token, pos);
    }        
    pos--;
    
    if(spaces[pos] != ' ')
    {
        std::cout << "Space is already taken !! \n";
        playerPos(spaces, token, pos);
    }
    else
    {
        spaces[pos] = token;
    }
}

void checkwinner(char *spaces , char pltoken, char compToken, bool *win)
{
    if((spaces[0] == pltoken) && (spaces[4] == pltoken) && (spaces[8] == pltoken))//player diagonal win
    {
        std::cout << "You won !!\n\n";
        *win = true;
    }
    if((spaces[2] == pltoken) && (spaces[4] == pltoken) && (spaces[6] == pltoken))
    {
        std::cout << "You won !!\n\n";
        *win = true;
    }

    for(int i = 0, j = i + 3, k = i + 6; i < 3; i += 1, j += 1, k += 1)//player column win
    {
        if((spaces[i] == pltoken) && (spaces[j] == pltoken) && (spaces[k] == pltoken))
        {
            std::cout << "You won !!\n\n";
            *win = true;
        }
    }
    for(int i = 0, j = i + 1, k = i + 2; i < 7; i += 3, j += 3, k += 3)//player row win
    {
        if((spaces[i] == pltoken) && (spaces[j] == pltoken) && (spaces[k] == pltoken))
        {
            std::cout << "You won !!\n\n";
            *win = true;
        }
    }
    


    if((spaces[0] == compToken) && (spaces[4] == compToken) && (spaces[8] == compToken))//computer diagonal win
    {
        std:: cout << "\n\nComputer diagonal win\n\n";
        std::cout << "You Lose !!\n\n";
        *win = true;
    }
    if((spaces[2] == compToken) && (spaces[4] == compToken) && (spaces[6] == compToken))
    {
        std:: cout << "\n\nComputer diagonal win\n\n";
        std::cout << "You Lose !!\n\n";
        *win = true;
    }

    for(int i = 0, j = i + 1, k = i + 2; i < 7; i += 3, j += 3, k += 3)//computer row win 
    {
        //printf("\n\n\ni = %d, j = %d, k = %d\n\n", i, j, k);
        if((spaces[i] == compToken) && (spaces[j] == compToken) && (spaces[k] == compToken))
        {
            std:: cout << "\n\nComputer row win\n\n";
            std::cout << "You Lose !!\n\n";
            *win = true;
        }
    }
    for(int i = 0, j = i + 3, k = i + 6; i < 3; i += 1, j += 1, k += 1)//computer column win
    {
        //printf("\n\n\ni = %d, j = %d, k = %d\n\n", i, j, k);
        if((spaces[i] == compToken) && (spaces[j] == compToken) && (spaces[k] == compToken))
        {
            std:: cout << "\n\nComputer column win\n\n";
            std::cout << "You Lose !!\n\n";
            *win = true;
        }
    }

}

void checkTie(char *spaces, bool *tie)
{
    bool full = false;
    for(int i = 0; i < 9; i++)
    {
        if( isblank(spaces[i]) == 0)
        {
            full = true;
        }
        else
        {
            full = false;
            break;
        }
    }

    if(full == true)
    {
        *tie = true;
        return;
    }
    else
    {
        *tie = false;
        return;
    }

}

int main()
{
    char ch[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char con = 'n';
    char playerToken = 'X';
    char compToken = 'O';
    bool win = false;
    bool tie = false;
    int pos = 0;
    
    std::cout << "ROCK PAPER SCISSORS !!!!!!!!!!!!!!!\n";
    drawboard(ch, sizeof(ch));

    std::cout << "What token will you play with? ('X' or 'O'): ";
    std::cin >> playerToken;
    
    if(playerToken != 'x' && playerToken != 'X' && playerToken != 'o' && playerToken != 'O')
    {
        while(playerToken != 'x' && playerToken != 'X' && playerToken != 'o' && playerToken != 'O')
        {
            std::cout << "Invalid entry!! Enter only 'x' or 'o'";
            std::cout << "\n---->  ";
            std::cin >> playerToken;
        }
    }
    
    do
    {
        if(playerToken == 'X' || playerToken == 'x')
        {
            compToken == 'O';
        }
        else
        {
            compToken = 'X';
        }

        
        while(win != 1)
        {
            checkwinner(ch, playerToken, compToken, &win);
            if(win == 1)
            {
                drawboard(ch, sizeof(ch));
                break;
            }
            checkTie(ch, &tie);
            if(tie == 1 && win == 0)
            {
                drawboard(ch, sizeof(ch));
                std:: cout << "Game has tied !! \n\n";
                break;
            }
            playerPos(ch, playerToken, pos); 

            checkwinner(ch, playerToken, compToken, &win);
            if(win == 1)
            {
                drawboard(ch, sizeof(ch));
                break;
            }
            checkTie(ch, &tie);
            if(tie == 1 && win == 0)
            {
                drawboard(ch, sizeof(ch));
                std:: cout << "Game has tied !! \n\n";
                break;
            }

            computerPos(ch, compToken);
            drawboard(ch, sizeof(ch));
        }

        std::cout << "Do you wish to play again ? (Y/N): ";
        std::cin >> con;

        if(con != 'n' && con != 'N')
        {
            win = false; 
            tie = false;
            for(int i = 0; i < 9; i++)
            {
                ch[i] = ' ';
            }
            drawboard(ch, sizeof(ch));
        }
    } while (con != 'n' && 'N');
    return 0; 
}