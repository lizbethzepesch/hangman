#include "hangman.h"

int main(){
    char secret[15] = "purples";
    hangman(get_word(secret));
    return 0;
}
