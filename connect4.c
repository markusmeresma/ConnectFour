#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define FOUR 4
char game_board[ROWS][COLS];
char header[] = "  1   2   3   4   5   6   7";
char row[] = "+---+---+---+---+---+---+---+";
int game_status = 1;

void print_board();
void init_game_board();
void insert(int pos, char disc);
void add_disc(char player);
void print_welcome_message();
int check_board(char player);

int main(void)
{
    system("clear");

    char player_A = 'X';
    char player_B = 'O';

    // Start game
    print_welcome_message();
    init_game_board();
    print_board();

    
    // Game engine
    while(game_status)
    {
        add_disc(player_A);
        print_board();
        
        // Check if A is a winner
        if(check_board(player_A))
        {
            printf("Player X won!\n");
            game_status = 0;
            break;
        }

        add_disc(player_B);
        print_board();

        // Check if B is a winner
        if(check_board(player_B))
        {
            printf("Player O won!\n");
            game_status = 0;
            break;
        }
        
    }
    

    return 0;
}

// Method for initialising the game board
void init_game_board()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j=0; j < COLS; j++)
        {
            game_board[i][j] = ' ';
        }
    }
}

// Method for showing the game board
void print_board()
{
    int i, j;

    // Print column numbers
    printf("%s\n", header);

    for(i = 0; i < ROWS; i++)
    {
        printf("%s\n", row);
        for(j = 0; j < COLS; j++)
        {
            printf("| %c ", game_board[i][j]);
            if(j == ROWS)
            {
                printf("|");
                printf("\n");
            }
        }
    }
    printf("%s\n", row);
}

// Method for inserting discs to the board
void insert(int pos, char disc)
{
    int i;

    for(i = ROWS - 1; i >= 0; i--)
    {
        // If the spot is empty then add the disc
        if(game_board[i][pos] == ' ')
        {
            game_board[i][pos] = disc;
            break;
        }
    }
}

// Method for choosing a move
void add_disc(char player)
{
    int move;
    int input_flag = 1;

    do
    {
        printf("Enter your move player %c: \n", player);
        scanf("%d", &move);

        switch (move)
        {
            case 1:
                insert(0, player);
                input_flag = 0;
                break;
            case 2:
                insert(1, player);
                input_flag = 0;
                break;
            case 3:
                insert(2, player);
                input_flag = 0;
                break;
            case 4:
                insert(3, player);
                input_flag = 0;
                break;
            case 5:
                insert(4, player);
                input_flag = 0;
                break;
            case 6:
                insert(5, player);
                input_flag = 0;
                break;
            case 7:
                insert(6, player);
                input_flag = 0;
                break;
                
            default:
                printf("Invalid input!\n");
        }

    } while (input_flag);
    
    
}

// Method to print welcome message
void print_welcome_message()
{
    printf(" *******************\n");
    printf("Welcome to Connect 4!\n");
    printf(" *******************\n\n");
}

// Method to check the state of the game
int check_board(char player)
{
    int i, j;
    int count;

    // Check 4 in a row
    for(i = 0; i < ROWS; i++)
    {
        count = 0;
        for(j = 0; j < COLS; j++)
        {
            if(game_board[i][j] == player)
            {
                count++;
                if(count == FOUR)
                {
                    return 1;
                }
            }
        }
    }

    // Check 4 in a column
    for(i = 0; i < COLS; i++)
    {
        count = 0;
        for(j = 0; j < ROWS; j++)
        {
            if(game_board[j][i] == player)
            {
                count++;
                if(count == FOUR)
                {
                    return 1;
                }
            }
        }
    }


    return 0;
}