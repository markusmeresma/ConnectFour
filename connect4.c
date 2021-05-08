#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
char game_board[ROWS][COLS];
char header[] = "  1   2   3   4   5   6   7";
char row[] = "+---+---+---+---+---+---+---+";
int game_status = 1; // set game status 0 in check methods if somebody won

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
        add_disc(player_B);
        print_board();
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

    printf("Enter your move player %c: \n", player);
    scanf("%d", &move);

    switch (move)
    {
        case 1:
            insert(0, player);
            break;
        case 2:
            insert(1, player);
            break;
        case 3:
            insert(2, player);
            break;
        case 4:
            insert(3, player);
            break;
        case 5:
            insert(4, player);
            break;
        case 6:
            insert(5, player);
            break;
        case 7:
            insert(6, player);
            break;
            
        default:
            printf("Invalid input!\n");
        }
}

// Method to print welcome message
void print_welcome_message()
{
    printf(" *******************\n");
    printf("Welcome to Connect 4!\n");
    printf(" *******************\n\n");
}

int check_board(char player)
{
    // Add checking functionality here
    return 0;
}