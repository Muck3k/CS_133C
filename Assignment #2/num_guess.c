#include <stdio.h>

int main(void) {
  //char no[] = "n";
  char yes_no;
  int player_one_guess;
  int player_two_guess;
  int secret_number_creation = -1;
  int secret_number = 42; // Had it set as a constant to make sure the game ran before asking the user for a random number.
  int x = 0;
  int y = 100;
  int player_one_guesses = 3;
  int player_two_guesses = 3;
  int player_one_final = 0;
  int player_two_final = 0;
  int end_game = 0;

  while(end_game == 0){

    //RESET:
    secret_number_creation = -1;
    //START BY ASKING FOR THE SECRET NUMBER.
    while(secret_number_creation < x || secret_number_creation > y){
      printf("Enter a secret number between 0 and 100\n");
      scanf("%d", &secret_number_creation);
      secret_number = secret_number_creation; // I know this is a little extra but it makes sense to me for testing purposes.
    }
    
    ////////////////////////////////////////////////
    //Game Code//

    //Player One Game:
    while(player_one_guesses != 0){
      player_one_guess = -1;
      printf("Player one: You have %d", player_one_guesses);
      printf(" guesses.\n");
      while(player_one_guess < x || player_one_guess > y){
        printf("Player one: Guess a number between %d",x);
        printf(" and %d",y);
        printf(": ");
        scanf("%d", &player_one_guess);
      }

      if(player_one_guess > secret_number){
        y = player_one_guess;
      }else{
        x = player_one_guess;
      }
      if(player_one_guess == secret_number){
        printf("Player one guessed the number with %d", player_one_guesses);
        printf(" guesses left.\n");
        player_one_final = player_one_guesses;
        player_one_guesses = 1;
      }
      player_one_guesses--;
    }
    //RESET GAME
    x = 0;
    y = 100;

    //Player Two Game: (I realized after coding this that you only wanted player one to pick the number and player two to guess the number but I already coded this and I'm not changing it. Plus this version would be cooler anyway because you could set a random number and the two players could conmpete.)
    while(player_two_guesses != 0){
      player_two_guess = -1;
      printf("Player two: You have %d", player_two_guesses);
      printf(" guesses.\n");
      while(player_two_guess < x || player_two_guess > y){
        printf("Player two: Guess a number between %d",x);
        printf(" and %d",y);
        printf(": ");
        scanf("%d", &player_two_guess);
      }

      if(player_two_guess > secret_number){
        y = player_two_guess;
      }else{
        x = player_two_guess;
      }
      if(player_two_guess == secret_number){
        printf("Player two guessed the number with %d", player_two_guesses);
        printf(" guesses left.\n");
        player_two_final = player_two_guesses;
        player_two_guesses = 1;
      }
      player_two_guesses--; 
    }
    //RESET GAME
    x = 0;
    y = 100;

    //Let's find out who won!
    if(player_one_final == player_two_final){
      printf("It's a tie!\n");
    }else if(player_two_final < player_one_final){
      printf("Player one wins!\n");
    }else{
      printf("Player two wins!\n");
    }

    /*
    printf("Player one: Guess a number between %d",x);
    printf(" and %d",y);
    printf(": ");*/
    //extra code that I didn't need.

    ////////////////////////////////////////////////

  // while(yes_no == 'y') /*|| (yes_no == 'Y')*/{
      //printf("\nDo you want to play again?");
      //scanf("%c", &yes_no);
      /*if(yes_no == 'n'){
        break;
      }*/
      //return 0;
    // }//else{
    // break;
    //}

    //FULL RESET OF GAME:
    player_one_guesses = 3;
    player_two_guesses = 3;


    //ASK IF PLAYERS WANT TO PLAY AGAIN:
    printf("Do you want to play a two player guessing game?(Y/N)\n");
    scanf(" %c", &yes_no);
    if(yes_no == 'n'){
      end_game = 1;
    }else if(yes_no == 'N'){
      end_game = 1;
    }else if(yes_no == 'y'){
      end_game = 0;
    }else if(yes_no == 'Y'){
      end_game = 0;
    }else{
      end_game = 0;
    }
    //printf("%c \n", yes_no); //thsi was a test for myself.
  }
}