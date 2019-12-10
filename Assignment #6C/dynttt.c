/* This assignment seemed a little too simple.
All I did was take my 1D code for tic tac toe
and replaced the array used for the board with
a dynamic array. This could have been a lot more
complicated but I believe this meets the requirements
of the assignment and shows that I know how to
use dynamic arrays.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void) {
//Values:
  int n = 9;
  int player_guess = -1;
  int x = 1;
  int y = 9;
  bool x_wins;
  bool o_wins;
  bool draw;
  int size = 1;
  int used_numbers[1000];
  char *dynamic_board;
  dynamic_board = calloc(n, sizeof(char));

  ////////////////////////////////////////////////////
  //Initialize dynamic array game board:
  printf("BOARD:");
  for(int i = 0; i < n; i++){
    *(dynamic_board + i) = '_';
    if (i % 3 == 0){
      printf("\n");
    }
    printf("%d %c ", i, *(dynamic_board+i) );
  }
  ////////////////////////////////////////////////////
  printf("\n");

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
    dynamic_board[player_guess] = 'X';


    printf("\nBOARD:");
    for(int i = 0; i < n; i++){
      if(dynamic_board[i] != 'X' && dynamic_board[i] != 'O' && dynamic_board[i] != '_'){
        dynamic_board[i] = '_';
      }
      if (i % 3 == 0){
        printf("\n");
      }
      printf("%d " , i + 1);
      printf("%c " , dynamic_board[i]);

    }
    printf("\n");
    //END PLAYER ONE
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if X wins:
    if(
    (dynamic_board[0] == 'X' && dynamic_board[1] == 'X' && dynamic_board[2] == 'X') ||
    (dynamic_board[3] == 'X' && dynamic_board[4] == 'X' && dynamic_board[5] == 'X') ||
    (dynamic_board[6] == 'X' && dynamic_board[7] == 'X' && dynamic_board[8] == 'X') ||
    (dynamic_board[2] == 'X' && dynamic_board[5] == 'X' && dynamic_board[8] == 'X') ||
    (dynamic_board[6] == 'X' && dynamic_board[3] == 'X' && dynamic_board[0] == 'X') ||
    (dynamic_board[7] == 'X' && dynamic_board[4] == 'X' && dynamic_board[1] == 'X') || 
    (dynamic_board[0] == 'X' && dynamic_board[4] == 'X' && dynamic_board[8] == 'X') || 
    (dynamic_board[2] == 'X' && dynamic_board[4] == 'X' && dynamic_board[6] == 'X')){
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
    (dynamic_board[0] != '_') &&
    (dynamic_board[1] != '_') &&
    (dynamic_board[2] != '_') && 
    (dynamic_board[3] != '_') && 
    (dynamic_board[4] != '_') && 
    (dynamic_board[5] != '_') && 
    (dynamic_board[6] != '_') && 
    (dynamic_board[7] != '_') && 
    (dynamic_board[8] != '_')){
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
    dynamic_board[player_guess] = 'O';


    printf("\nBOARD:");
    for(int i = 0; i < n; i++){
      if(dynamic_board[i] != 'X' && dynamic_board[i] != 'O' && dynamic_board[i] != '_'){
        dynamic_board[i] = '_';
      }
      if (i % 3 == 0){
        printf("\n");
      }
      printf("%d " , i + 1);
      printf("%c " , dynamic_board[i]);

    }
    printf("\n");
    //END PLAYER 2
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    //Check if O wins:
    if(
    (dynamic_board[0] == 'O' && dynamic_board[1] == 'O' && dynamic_board[2] == 'O') ||
    (dynamic_board[3] == 'O' && dynamic_board[4] == 'O' && dynamic_board[5] == 'O') ||
    (dynamic_board[6] == 'O' && dynamic_board[7] == 'O' && dynamic_board[8] == 'O') ||
    (dynamic_board[2] == 'O' && dynamic_board[5] == 'O' && dynamic_board[8] == 'O') ||
    (dynamic_board[6] == 'O' && dynamic_board[3] == 'O' && dynamic_board[0] == 'O') ||
    (dynamic_board[7] == 'O' && dynamic_board[4] == 'O' && dynamic_board[1] == 'O') ||
    (dynamic_board[0] == 'O' && dynamic_board[4] == 'O' && dynamic_board[8] == 'O') ||
    (dynamic_board[2] == 'O' && dynamic_board[4] == 'O' && dynamic_board[6] == 'O')){
    o_wins = true;
    printf("Three in a row for O!\n");
    printf("Player two wins!");
    break;
    } 
  ////////////////////////////////////////////////////
  }
}