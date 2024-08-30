/* shooting craps game */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SEED 12345

int throw_dice(void);
void play_game(void);

int main(){
  srand(SEED);

  char answer;

  printf("\nWELCOME to shooting craps game\n");
  printf("To the throw dice please press the 'Enter' button\n");

  do{
    play_game();
    printf("Do you want to play this game?(y/n): ");
    scanf("%c", &answer);
  }while(toupper(answer) != 'N');

  printf("\n GOOD BYE...\n");

  return 0;
}

int throw_dice(void){
  float x1, x2;
  int num1, num2;

  x1 = rand() / 32768.0;
  x2 = rand() / 32768.0;

  num1 = 1 + (int) (6 * x1);
  num2 = 1 + (int) (6 * x2);

  return num1 + num2;
}

void play_game(void){
  int score1, score2;
  char dummy;

  printf("\n.... please throw your dice ....\n");
  scanf("%c", &dummy);

  score1 = throw_dice();
  printf("score %d - ", score1);

  switch (score1){
    case 7:
    case 11:
      printf("!! CONGRATULATIONS !! you won the game on first throw\n");
      break;
    case 2:
    case 3:
    case 12:
      printf("!! SORRY !! you lose the game on first throw\n");
      break;
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
      do{

        printf(".... throw the dice again ....\n");
        scanf("%c", &dummy);
        score2 = throw_dice();
        printf("score %d - ", score2);
      } while(score2 != score1 && score2 != 7);

      if(score2 == score1)
        printf("!! YOU WIN !! for matching the first score\n");
      else
        printf("!! YOU LOSE !! for not matching with first score\n");
      break;
  }

  return;
}
