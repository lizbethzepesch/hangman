#include "hangman.h"


int mx_strlen(const char *s) {
    int i = 0;
    
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}


int mx_strchr(const char *s, int c){
  do {
    if (*s == c)
        return 1;
  } while (*s++);
  return 0;
}

int get_word(char secret[]){

}

int is_word_guessed(const char secret[], const char letters_guessed[]){
        while(*secret && (*secret == *letters_guessed)){
        secret++;
        letters_guessed++;
    }
    return *(unsigned const char *)secret - *(unsigned const char *)letters_guessed;
}


void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){

}
