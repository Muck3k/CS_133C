#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 10
#define NUMBER_OF_MINES 15

//This is my struct in a struct.
struct city{
  char city_name[50];
  int city_population;
};
struct person{
  char name[50];
  int age;
  int favorite_number;
  struct city city_data;
}person_data;

char board[BOARD_SIZE][BOARD_SIZE];
char mine_board [BOARD_SIZE][BOARD_SIZE];
bool lose = false;
bool win = false;
int touching_mines;

void print_board();
void initialize_board();
void initialize_mines();
void display_mines();
void check_hit_mine(int row_choice, int column_choice);
int findtouchingmines(int, int);
void flood_fill(int row, int col);
void check_win();
void automated_test();
void switch_test(int n, int row, int col);



int main(int argc, char *argv[])
{
  struct person person_data = {"Matthew", 20, 3, "Ashland",21117};
  //File IO
  FILE *description;
  //Also this is an array of strings I think.
  char sdescription[500];
  //Just to be sure:
  char array_of_strings[3][100] = 
  {
    "Array ", "of ", "strings "
  };


  //Here is an array of pointers:
  char *array_of_pointers[3] = 
  {
    "Array","of","pointers"
  };
  //Example print:
  //printf("%s %s %s", array_of_pointers[0], array_of_pointers[1],array_of_pointers[2]);

  description = fopen("description.txt", "r");
  fgets(sdescription, 500, (FILE*)description);

  int minimum = 1;
  int maximum = 10;
  int row_choice;
  int column_choice; 

  srand(time(0));
  initialize_board();
  initialize_mines();
  //print_board();
  //Here is me showing the struct in a struct:
  //printf("Hello my name is %s. " ,person_data.name);
  //printf("I am %d years old and I grew up in %s, Oregon with a population of %d. ",person_data.age, person_data.city_data.city_name,person_data.city_data.city_population);
  printf("\n");
  printf("%s",sdescription);
  printf("\n\n");
  //display_mines();

  //automated_test();

  //LETS START THE GAME:
  while(lose == false && win == false){
    //RESET CHIOCES:
    row_choice = -1;
    column_choice = -1;
    print_board();
    //display_mines();
    while(row_choice < minimum || row_choice > maximum){
      printf("Choose a row(1-10): ");
      scanf("%d",&row_choice);
    }

    while(column_choice < minimum || column_choice > maximum){
    printf("Choose a column(1-10): "); 
    scanf("%d", &column_choice);
    }
    row_choice = row_choice - 1;
    column_choice = column_choice - 1;

    check_hit_mine(row_choice,column_choice);
    flood_fill(row_choice,column_choice);
    check_win();
    //automated_test();
  }
}

void print_board(){
  //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("BOARD: \n");
  printf("                 COLUMNS\n");
  printf("        1  2  3  4  5  6  7  8  9  10");
  for(int row = 0; row < BOARD_SIZE; ++row)
	{
    if(row % 4 == 0 && row / 4 == 1){
      printf("\nROWS  %d " , row + 1);
    }else if(row / 9 == 1){
      printf("\n     %d " , row + 1);
    }else{
      printf("\n      %d " , row + 1);
    }
		for(int col = 0; col < BOARD_SIZE; ++col)
		{
      printf("%c  ", board[row][col]);
		}
	}

  printf("\n\n");

}
void initialize_board(){
  for(int row = 0; row < BOARD_SIZE; ++row){
    
	  for(int col = 0; col < BOARD_SIZE; ++col)
		{
      for(int i = 0 ; i < NUMBER_OF_MINES; i++ ) {
        board[row][col] = '-';
      }
    }
	}
}

void initialize_mines(){
  int random_num;
  int random_num2;

  for (int i = 0; i < NUMBER_OF_MINES; i++)
  {
    random_num = rand() % (BOARD_SIZE);
    random_num2 = rand() % (BOARD_SIZE);

    if(mine_board[random_num][i] != '*'){
      mine_board[random_num][i] = '*';
    }else if(mine_board[random_num2][i] != '*'){
      mine_board[random_num2][i] = '*';
    }else{
      i--;
      i--;
    }
  }
}

void display_mines(){
  printf("BOARD: \n");
  printf("                 COLUMNS\n");
  printf("        1  2  3  4  5  6  7  8  9  10");
  for(int row = 0; row < BOARD_SIZE; ++row)
	{
    if(row % 4 == 0 && row / 4 == 1){
      printf("\nROWS  %d " , row + 1);
    }else if(row / 9 == 1){
      printf("\n     %d " , row + 1);
    }else{
      printf("\n      %d " , row + 1);
    }
		for(int col = 0; col < BOARD_SIZE; ++col)
		{
      if(mine_board[row][col] == '*'){
        printf("%c  ", mine_board[row][col]);
      }else{
        printf("%c  ", board[row][col]);
      }
		}
	}

  printf("\n\n");
}

void check_hit_mine(int row_choice, int column_choice){
  if(mine_board[row_choice][column_choice] == '*')
    {
        printf("\nYou've hit a mine! You lose!\n");
        lose = true;
        display_mines();
    }
}

int findtouchingmines(int row, int col)
{
  int number_of_mines = 0;
  
  // Check up
  if(row != 0){
    if(mine_board[row - 1][col] == '*'){
      number_of_mines++;
    }
  }
  //Check down
  if(row != BOARD_SIZE - 1){
    if(mine_board[row + 1][col] == '*'){
      number_of_mines++;
    }
  }
  //Check Left
  if(col != 0){
    if(mine_board[row][col - 1] == '*'){
      number_of_mines++;
    }
  }
  //Check right
  if(col != BOARD_SIZE - 1){
    if(mine_board[row][col + 1] == '*'){
      number_of_mines++;
    }
  }

  // Check up/right
  if(row != 0 && col != BOARD_SIZE - 1){
    if(mine_board[row - 1][col + 1] == '*'){
      number_of_mines++;
    }
  }
  //Check up/left
  if(row != 0 && col != 0){
    if(mine_board[row - 1][col - 1] == '*'){
      number_of_mines++;
    }
  }
  //Check down/right
  if(row != BOARD_SIZE - 1 && col != BOARD_SIZE - 1){
    if(mine_board[row + 1][col + 1] == '*'){
      number_of_mines++;
    }
  }
  //Check down/left
  if(row != BOARD_SIZE - 1 && col != 0){
    if(mine_board[row + 1][col - 1] == '*'){
      number_of_mines++;
    }
  }
  return number_of_mines;
}

void check_win(){
  int num = 0;
 for(int row = 0; row < BOARD_SIZE; ++row){
    
	  for(int col = 0; col < BOARD_SIZE; ++col)
		{
      for(int i = 0 ; i < NUMBER_OF_MINES; i++ ) {
        if(board[row][col] != '-' || mine_board[row][col] == '*'){
          
        }else{
          num++;
        }
      }
    }
	}
  if(num == 0){
    printf("You win!\n");
    display_mines();
    win = true;
  }
}

void automated_test(){
  for(int row = 0; row < BOARD_SIZE; ++row){
    for(int col = 0; col < BOARD_SIZE; ++col)
		{
      if(mine_board[row][col] != '*'){
        touching_mines = findtouchingmines(row, col);
        board[row][col] = (char)(((int)'0') + touching_mines);
      }
    }
  }
}


void flood_fill(int row, int col){
  int num_bomb1a = 0;
  int num_bomb2a = 0;
  int num_bomb3a = 0;
  int num_bomb4a = 0;
  int num_bomb1 = 0;
  int num_bomb2 = 0;
  int num_bomb3 = 0;
  int num_bomb4 = 0;
  int i = 0;
  if(findtouchingmines(row, col) == 0){
    switch_test(1,row,col); //UP
    switch_test(2,row,col); //DOWN
    switch_test(3,row,col); //LEFT
    switch_test(4,row,col); //RIGHT
    switch_test(5,row,col); //UP-RIGHT
    switch_test(6,row,col); //UP-LEFT
    switch_test(7,row,col); //DOWN-RIGHT
    switch_test(8,row,col); //DOWN-LEFT
  }else{
    touching_mines = findtouchingmines(row, col);
    board[row][col] = (char)(((int)'0') + touching_mines);
  }
  //for(int i = 0; i < BOARD_SIZE; i++){
  while((num_bomb1a == 0 || num_bomb2a == 0 || num_bomb3a == 0 || num_bomb4a == 0 || num_bomb1 == 0 || num_bomb2 == 0 || num_bomb3 == 0 || num_bomb4 == 0) && i < 40){
    //printf("%d \n", i);
    //Right
    if(findtouchingmines(row, col + i) == 0 && col != BOARD_SIZE - 1){
      if(num_bomb4a < 1){
        switch_test(5,row,col + i); //UP-RIGHT
        switch_test(6,row,col + i); //UP-LEFT
        switch_test(7,row,col + i); //DOWN-RIGHT
        switch_test(8,row,col + i); //DOWN-LEFT
        switch_test(1,row,col + i); //UP
        switch_test(2,row,col + i); //DOWN
        switch_test(3,row,col + i); //LEFT
        switch_test(4,row,col + i); //RIGHT
        }
    }else{
      num_bomb4a++;
    }
    //LEFT
    if(findtouchingmines(row, col - i) == 0 && col != 0){
      if(num_bomb3a < 1){
        switch_test(5,row,col - i); //UP-RIGHT
        switch_test(6,row,col - i); //UP-LEFT
        switch_test(7,row,col - i); //DOWN-RIGHT
        switch_test(8,row,col - i); //DOWN-LEFT
        switch_test(1,row,col - i); //UP
        switch_test(2,row,col - i); //DOWN
        switch_test(3,row,col - i); //LEFT
        switch_test(4,row,col - i); //RIGHT
        }
    }else{
      num_bomb3a++;
    }
    //DOWN
    if(findtouchingmines(row + i, col) == 0 && row != BOARD_SIZE - 1 ){
      if(num_bomb2a < 1){
        switch_test(5,row + i,col); //UP-RIGHT
        switch_test(6,row + i,col); //UP-LEFT
        switch_test(7,row + i,col); //DOWN-RIGHT
        switch_test(8,row + i,col); //DOWN-LEFT
        switch_test(1,row + i,col); //UP
        switch_test(2,row + i,col); //DOWN
        switch_test(3,row + i,col); //LEFT
        switch_test(4,row + i,col); //RIGHT
      }
    }else{
      num_bomb2a++;
    }
    //UP
    if(findtouchingmines(row - i, col) == 0 && row != 0 ){
      if(num_bomb1a < 1){
        switch_test(5,row - i,col); //UP-RIGHT
        switch_test(6,row - i,col); //UP-LEFT
        switch_test(7,row - i,col); //DOWN-RIGHT
        switch_test(8,row - i,col); //DOWN-LEFT
        switch_test(1,row - i,col); //UP
        switch_test(2,row - i,col); //DOWN
        switch_test(3,row - i,col); //LEFT
        switch_test(4,row - i,col); //RIGHT
      }
    }else{
      num_bomb1a++;
    }
    //UP-RIGHT
    if(findtouchingmines(row - i, col + i) == 0 && row != 0 && col != BOARD_SIZE - 1){
      if(num_bomb1 < 1){
        switch_test(5,row - i,col + i); //UP-RIGHT
        switch_test(6,row - i,col + i); //UP-LEFT
        switch_test(7,row - i,col + i); //DOWN-RIGHT
        switch_test(8,row - i,col + i); //DOWN-LEFT
        switch_test(1,row - i,col + i); //UP
        switch_test(2,row - i,col + i); //DOWN
        switch_test(3,row - i,col + i); //LEFT
        switch_test(4,row - i,col + i); //RIGHT
      }
    }else{
      num_bomb1++;
    }
  //DOWN-RIGHT
    if(findtouchingmines(row + i, col + i) == 0 && row != BOARD_SIZE - 1 && col != BOARD_SIZE - 1){
      if(num_bomb2 < 1){
        switch_test(5,row + i, col + i); //UP-RIGHT
        switch_test(6,row + i, col + i); //UP-LEFT
        switch_test(7,row + i, col + i); //DOWN-RIGHT
        switch_test(8,row + i, col + i); //DOWN-LEFT
        switch_test(1,row + i, col + i); //UP
        switch_test(2,row + i, col + i); //DOWN
        switch_test(3,row + i, col + i); //LEFT
        switch_test(4,row + i, col + i); //RIGHT
      }
    }else{
      num_bomb2++;
    }
  //UP-LEFT
    if(findtouchingmines(row - i, col - i) == 0 && row != 0 && col != 0){
      if(num_bomb3 < 1){
        switch_test(5,row - i, col - i); //UP-RIGHT
        switch_test(6,row - i, col - i); //UP-LEFT
        switch_test(7,row - i, col - i); //DOWN-RIGHT
        switch_test(8,row - i, col - i); //DOWN-LEFT
        switch_test(1,row - i, col - i); //UP
        switch_test(2,row - i, col - i); //DOWN
        switch_test(3,row - i, col - i); //LEFT
        switch_test(4,row - i, col - i); //RIGHT
      }
    }else{
      num_bomb3++;
    }
  //DOWN_LEFT
    if(findtouchingmines(row + i, col - i) == 0 && col > 0 && row < BOARD_SIZE - 1){
      if(num_bomb4 < 1){
        switch_test(5,row + i, col - i); //UP-RIGHT
        switch_test(6,row + i, col - i); //UP-LEFT
        switch_test(7,row + i, col - i); //DOWN-RIGHT
        switch_test(8,row + i, col - i); //DOWN-LEFT
        switch_test(1,row + i, col - i); //UP
        switch_test(2,row + i, col - i); //DOWN
        switch_test(3,row + i, col - i); //LEFT
        switch_test(4,row + i, col - i); //RIGHT
      }
    }else{
      num_bomb4++;
      //printf("%d \n", i);
    }
    i++;
  }
}


void switch_test(int n, int row, int col){
  int touching_mines = 0;
  int i = 0;
 
  switch (n){
    case 1: // Checking nearby mines going up
      while(touching_mines < 1 && row - i >= 0)
      {
          touching_mines = findtouchingmines(row - i, col);
          if(board[row - i][col] == '-' && mine_board[row - i][col] != '*'){ //These if statements fixed my major segmentation error.
            board[row - i][col] = (char)(((int)'0') + touching_mines); // I had to look this like up to figure out how to turn an int into a char.
          }
          i++;
      }
    i = 0;
    case 2: // Checking nearby mines going down
      while(touching_mines < 1 && row + i < BOARD_SIZE)
      {
          touching_mines = findtouchingmines(row + i, col);
          if(board[row + i][col] == '-' && mine_board[row + i][col] != '*'){
            board[row + i][col] = (char)(((int)'0') + touching_mines);
          }
          i++;
      }
    i = 0;
    case 3: // Checking nearby mines going left
      while(touching_mines < 1 && col - i >= 0)
      {
        touching_mines = findtouchingmines(row, col - i);
        if(board[row][col - i] == '-' && mine_board[row][col - i] != '*'){
          board[row][col - i] = (char)(((int)'0') + touching_mines);
        }
        i++;
      }
    i = 0;
    case 4: // Checking nearby mines going right
      while(touching_mines < 1 && col + i < BOARD_SIZE - 1)
      {
        touching_mines = findtouchingmines(row, col + i);
        if(board[row][col + i] == '-' && mine_board[row][col + i] != '*'){
          board[row][col + i] = (char)(((int)'0') + touching_mines);
        }
        i++;
      }
    i = 0;
    case 5: // Checking nearby mines going up/right
      while(touching_mines < 1 && col + i < BOARD_SIZE  - 1 && row - i >= 0)
      {
        touching_mines = findtouchingmines(row - i, col + i);
        if(board[row - i][col + i] == '-' && mine_board[row - i][col + i] != '*'){
        board[row - i][col + i] = (char)(((int)'0') + touching_mines);
        }
        i++;
      }
    i = 0;
    case 6: // Checking nearby mines going up/left
      while(touching_mines < 1 && row - i >= 0 && col - i >= 0)
      {
        touching_mines = findtouchingmines(row - i, col - i);
        if(board[row - i][col - i] == '-' && mine_board[row - i][col - i] != '*'){
          board[row - i][col - i] = (char)(((int)'0') + touching_mines);
        }
        i++;
      }
    i = 0;
    case 7: // Checking nearby mines going down/right
    while(touching_mines < 1 && row + i < BOARD_SIZE && col + i < BOARD_SIZE  - 1)
      {
        touching_mines = findtouchingmines(row + i, col + i);
        if(board[row + i][col + i] == '-' && mine_board[row + i][col + i] != '*'){
          board[row + i][col + i] = (char)(((int)'0') + touching_mines);
        }
        i++;
      }
    i = 0;
    case 8: // Checking nearby mines going down/left
      while(touching_mines < 1 && row + i < BOARD_SIZE && col - i >= 0)
      {
        touching_mines = findtouchingmines(row + i, col - i);
        if(board[row + i][col - i] == '-' && mine_board[row + i][col - i] != '*'){
          board[row + i][col - i] = (char)(((int)'0') + touching_mines);
        }
      i++;
      }
    i = 0;
  }
}