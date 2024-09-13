#include<stdio.h>
#include <ctype.h>

void lowtoup(char *text){
  int count = 0;
  while(text[count] != '\0'){
    if(text[count] >= 'a' && text[count] <= 'z'){
      text[count] = text[count] - 32;
    }
    ++count;
  }
  return;
}

void uptolow(char *text){
  int count = 0;
  while(text[count] != '\0'){
    if(text[count] >= 'A' && text[count] <= 'Z'){
      text[count] = text[count] + 32;
    }
    ++count;
  }
  return;
}