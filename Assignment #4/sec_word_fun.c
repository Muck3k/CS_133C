#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_for_bad_word(char *word);

int main(void) {
  //char no[] = "n";
  char yes_no;
  //int guess_length = 1;
  char player_one_guess[1];
  int max_length = 45;
  char secret_word[max_length];
  int x = 0;
  int y = 100;
  int player_one_guesses = 10;
  int player_one_final = 0;
  int end_game = 0;
  bool word_match;

 // while(end_game == 0){ //was going to use this but...
    //PARTIALLY FROM LECTURE:
    bool bad_word = true;
    //START BY ASKING FOR THE SECRET WORD.
    while(bad_word){
    printf("Enter a lowercase secret word to be guessed: ");
	  fgets(secret_word, max_length, stdin);
	  int secret_length = strlen(secret_word);
	  secret_word[secret_length - 1] = '\0';

     bad_word = check_for_bad_word(secret_word);
    }
  int the_word [strlen(secret_word)];

  printf("SERCRET WORD: \n");
  for(int i = 0; i < strlen(secret_word); i++){
    the_word[i] = '_';
    printf("%c",the_word[i]);
    printf(" ");
  }
  printf("\n");

    //Guessing Game:
    while(player_one_guesses != 0){
      printf("Player one: You have %d", player_one_guesses);
      printf(" guesses.\n");
      bad_word = true;
      while(bad_word){
        printf("Player one: Guess a lowercase letter: ");
       // scanf("%c", &player_one_guess[1]);
        fgets(player_one_guess, max_length, stdin);
	      int guess_length = strlen(player_one_guess);
	      player_one_guess[guess_length - 1] = '\0';

        bad_word = check_for_bad_word(player_one_guess);
        /*for(int i = 0; i < strlen(secret_word); i++){
          if(secret_word[i] == player_one_guess[0]){
            printf("+");
          }
        }*/ // This was for testing...
        for(int i = 0; i < strlen(secret_word); i++){
          if(secret_word[i] == player_one_guess[0]){
            the_word[i] = secret_word[i];
          }
          printf("%c",the_word[i]);
          printf(" ");
        }
        printf("\n");

        for(int i = 0; i < strlen(secret_word); i++){
          word_match = true;
          if(the_word[i] == '_'){
            word_match = false;
            i = strlen(secret_word);
          }
        }
        if(word_match == true){
          printf("\nYOU GUESSED THE SECRET WORD CORRECTLY YOU WIN!\n");
          player_one_guesses = 1;
        }
        if(word_match == false && player_one_guesses == 1){
          printf("\nOUT OF GUESSES. YOU LOSE!\n");
        }

        if(bad_word == false){
          player_one_guesses--;
        }

        //for BEGIN TEST HERE!!!!!!!!!!!!!
      }
    
        /*if(player_one_guess[i] > secret_word[i]){
          y = player_one_guess;
        }else{
          x = player_one_guess;
        }
        if(player_one_guess[i] == secret_word[i]){
          printf("Player one guessed the number with %d", player_one_guesses);
          printf(" guesses left.\n");
          player_one_final = player_one_guesses;
          player_one_guesses = 1;
        }
        player_one_guesses--;
      }*/
    }
    //RESET GAME
    

    //FULL RESET OF GAME:
    player_one_guesses = 10;


    //ASK IF PLAYERS WANT TO PLAY AGAIN:
    /* Decided not to use this.
    printf("Do you want to play word guessing game?(Y/N)\n");
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
    }*/
    //printf("%c \n", yes_no); //thsi was a test for myself.
}








//Took this dirctly from a lecture: (It's used to check if the letters that are input are between lowercase a and lowercase z. I decided to only use lowercase for this because it made more sensee to me for a guessing game.)
bool check_for_bad_word(char *word)
{
	int length = strlen(word);
	
//	printf("word entered: %s\n", word);
	//do some stuff fix word
	for(int i = 0; i < length; ++i)
	{
	//	printf("word[%d]: %c(%d)\n", i, word[i], word[i]);
		//detect bad characters
		bool low_bad = word[i] < 'a';
		bool high_bad = word[i] > 'z';
		if(low_bad || high_bad)
		{
			printf("invalid character detected (%c).\n", word[i]);
			return true;
		}
	}
	
	return false;
}
///This code was really messsy ):