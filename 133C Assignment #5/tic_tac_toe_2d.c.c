#include <stdio.h>
#include <stdbool.h>

#define NUM_ROWS 3
#define NUM_COLUMNS 3

int main(void) {
//Values:

  char board[NUM_ROWS][NUM_COLUMNS];
  int player_column = -1;
  int player_row = -1;
  int x = 1;
  int y = 3;
  bool x_wins;
  bool o_wins;
  bool draw;
  int size = 1;
  int used_row[1000];
  int used_col[1000];

  ////////////////////////////////////////////////////
  //PRINT GAME BOARD:
  printf("BOARD: \n");
  printf("        COLUMNS\n");
  printf("        1  2  3");
  for(int row = 0; row < NUM_ROWS; ++row)
	{
    if(row % 2 == 0){
      printf("\n      %d " , row + 1);
    }else{
      printf("\nROWS  %d " , row + 1);
    }
		for(int col = 0; col < NUM_COLUMNS; ++col)
		{
			board[row][col] = '-';
      printf("%c  ", board[row][col]);
		}
	}

  printf("\n\n");
    ////////////////////////////////////////////////////

  ////////////////////////////////////////////////////
  //Start game:
  while(x_wins == false && o_wins == false && draw == false){
    size++;
    ////////////////////////////////////////////////////
    //PLAYER ONE:
    //RESET:
    player_row = -1;
    player_column = -1;

    while(
    (player_column < x || player_column > y) ||
    (player_row < x || player_row > y)){
      printf("Player one, which column do you want to play? (1-3)");
      scanf("%d", &player_column);
      printf("Player one, which row do you want to play? (1-3)");
      scanf("%d", &player_row);
      for(int i = 1; i < size; i++){
          if(used_row[i] == player_row && used_col[i] == player_column){
            printf("This spot has already been played on.\n");
            player_column = -1;
            player_row = -1;
        }
      }
    } 

    used_row[size] = player_row;
    used_col[size] = player_column;
    
    player_column = player_column - 1;
    player_row = player_row - 1;
    board[player_row][player_column] = 'X';





  ////////////////////////////////////////////////////
  //PRINT GAME BOARD:
  printf("BOARD: \n");
  printf("        COLUMNS\n");
  printf("        1  2  3");
  for(int row = 0; row < NUM_ROWS; ++row)
	{
    if(row % 2 == 0){
      printf("\n      %d " , row + 1);
    }else{
      printf("\nROWS  %d " , row + 1);
    }
		for(int col = 0; col < NUM_COLUMNS; ++col)
		{
      printf("%c  ", board[row][col]);
		}
	}

  printf("\n\n");
    ////////////////////////////////////////////////////
    //END PLAYER ONE
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if X wins:
    if(
    (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
    (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
    (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
    (board[1][1] == 'X' && board[2][0] == 'X' && board[0][2] == 'X') ||
    (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
    (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || 
    (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || 
    (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')){
      x_wins = true;
      printf("Three in a row for X!\n");
      printf("Player one wins!");
      break;
    }
    //END X CHECK
    ////////////////////////////////////////////////////
      
    //Check draw:
    ////////////////////////////////////////////////////
    if(
    (board[0][0] != '-') &&
    (board[1][0] != '-') &&
    (board[2][0] != '-') && 
    (board[0][1] != '-') && 
    (board[1][1] != '-') && 
    (board[2][1] != '-') && 
    (board[0][2] != '-') && 
    (board[1][2] != '-') && 
    (board[2][2] != '-')){
    bool draw = true;
    printf("It's a tie!\n");
    break;
    }
    ////////////////////////////////////////////////////

    size++;
        ////////////////////////////////////////////////////
    //PLAYER TWO:
    //RESET:
    player_row = -1;
    player_column = -1;

    while(
    (player_column < x || player_column > y) ||
    (player_row < x || player_row > y)){
      printf("Player two, which column do you want to play? (1-3)");
      scanf("%d", &player_column);
      printf("Player two, which row do you want to play? (1-3)");
      scanf("%d", &player_row);
      for(int i = 1; i < size; i++){
          if(used_row[i] == player_row && used_col[i] == player_column){
            printf("This spot has already been played on.\n");
            player_column = -1;
            player_row = -1;
        }
      }
    }  

    used_row[size] = player_row;
    used_col[size] = player_column;

    player_column = player_column - 1;
    player_row = player_row - 1;
    board[player_row][player_column] = 'O';





  ////////////////////////////////////////////////////
  //PRINT GAME BOARD:
  printf("BOARD: \n");
  printf("        COLUMNS\n");
  printf("        1  2  3");
  for(int row = 0; row < NUM_ROWS; ++row)
	{
    if(row % 2 == 0){
      printf("\n      %d " , row + 1);
    }else{
      printf("\nROWS  %d " , row + 1);
    }
		for(int col = 0; col < NUM_COLUMNS; ++col)
		{
      printf("%c  ", board[row][col]);
		}
	}

  printf("\n\n");
    ////////////////////////////////////////////////////
    //END PLAYER TWO
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if O wins:
    if(
    (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
    (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
    (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
    (board[1][1] == 'O' && board[2][0] == 'O' && board[0][2] == 'O') ||
    (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
    (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || 
    (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || 
    (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')){
    o_wins = true;
    printf("Three in a row for O!\n");
    printf("Player two wins!");
    break;
    }
  ////////////////////////////////////////////////////
  }
}