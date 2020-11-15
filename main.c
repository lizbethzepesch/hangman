#include "hangman.h"

int main(){
    char secret[15];
    hangman(get_word(secret));
    return 0;
}
