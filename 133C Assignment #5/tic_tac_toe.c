#include <stdio.h>
#include <stdbool.h>


int main(void) {
//Values:
  int n = 9;
  char board[n];
  int player_guess = -1;
  int x = 1;
  int y = 9;
  bool x_wins;
  bool o_wins;
  bool draw;
  int size = 1;
  int used_numbers[1000];

  ////////////////////////////////////////////////////
  //PRINT GAME BOARD:
  printf("BOARD:");
    for(int i = 0; i < n; ++i){
      board[i] = '_';
      if (i % 3 == 0){
        printf("\n");
      }
      printf("%d " ,i + 1);
      printf("%c",board[i]);
      printf(" ");
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
    player_guess = -1;

    while(player_guess < x || player_guess > y){
      printf("Player one, where do you want to play? (1-9)");
      scanf("%d", &player_guess);
      for(int i = 1; i < n; i++){
        if(used_numbers[i] == player_guess){
          printf("This spot has already been played on.\n");
          player_guess = -1;
        }
      }
    }     
    used_numbers[size] = player_guess;
    player_guess = player_guess - 1;
    board[player_guess] = 'X';


    printf("\nBOARD:");
    for(int i = 0; i < n; i++){
      if(board[i] != 'X' && board[i] != 'O' && board[i] != '_'){
        board[i] = '_';
      }
      if (i % 3 == 0){
        printf("\n");
      }
      printf("%d " , i + 1);
      printf("%c " , board[i]);

    }
    printf("\n");
    //END PLAYER ONE
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if X wins:
    if(
    (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
    (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
    (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
    (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
    (board[6] == 'X' && board[3] == 'X' && board[0] == 'X') ||
    (board[7] == 'X' && board[4] == 'X' && board[1] == 'X') || 
    (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || 
    (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')){
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
    (board[0] != '_') &&
    (board[1] != '_') &&
    (board[2] != '_') && 
    (board[3] != '_') && 
    (board[4] != '_') && 
    (board[5] != '_') && 
    (board[6] != '_') && 
    (board[7] != '_') && 
    (board[8] != '_')){
    bool draw = true;
    printf("It's a tie!\n");
    break;
    }
    ////////////////////////////////////////////////////

    size++;
    ////////////////////////////////////////////////////
    //PLAYER TWO:
    //RESET:
    player_guess = -1;

    while(player_guess < x || player_guess > y){
      printf("Player two, where do you want to play? (1-9)");
      scanf("%d", &player_guess);
      for(int i = 1; i < n; i++){
        if(used_numbers[i] == player_guess){
          printf("This spot has already been played on.\n");
          player_guess = -1;
        }
      }
    }
    used_numbers[size] = player_guess;
    player_guess = player_guess - 1;
    board[player_guess] = 'O';


    printf("\nBOARD:");
    for(int i = 0; i < n; i++){
      if(board[i] != 'X' && board[i] != 'O' && board[i] != '_'){
        board[i] = '_';
      }
      if (i % 3 == 0){
        printf("\n");
      }
      printf("%d " , i + 1);
      printf("%c " , board[i]);

    }
    printf("\n");
    //END PLAYER 2
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if O wins:
    if(
    (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
    (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
    (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
    (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
    (board[6] == 'O' && board[3] == 'O' && board[0] == 'O') ||
    (board[7] == 'O' && board[4] == 'O' && board[1] == 'O') ||
    (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
    (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')){
    o_wins = true;
    printf("Three in a row for O!\n");
    printf("Player two wins!");
    break;
    } 
  ////////////////////////////////////////////////////
  }
}