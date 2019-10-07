#include <stdio.h>

int data_types(void) {
  //I'm going to just try a bunch of differnet variables.
  int favorite_number = 3;
  short first_name = 9999;
  long full_name = 999999999999999999;
  char name[] = "Matthew O'Donnell";
  float my_test_deicimal = 33.29224573453457;
  double my_short_decimal = 33.333333;
  long double just_a_test = 33.29224573453457234234;
  char favorite_letter[] = "X";


  printf("Test\n %f\n %F\n %Le\n", my_short_decimal, my_test_deicimal,just_a_test);
  printf("%s\n", name);
  //printf("%c",favorite_letter);
  //I was expecting that to work but for some reason the %c identifier didn't work for a character.
  return 0;
}