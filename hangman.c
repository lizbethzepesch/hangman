#include "hangman.h"

int mx_strlen(const char *s) {
    int i = 0;
    
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

int get_word(char secret[]){
    return secret;
}

int mx_strchr(const char *s, int c){
    do {
        if (*s == c)
            return 1;
    } while (*s++);
    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
    for (int i = 0; i < mx_strlen(secret); i++) 
        if (!mx_strchr(letters_guessed, secret[i]))
            return 0;
    
    return 1;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    for (int i = 0; secret[i]; i++)
        if (mx_strchr(letters_guessed, secret[i]))
            guessed_word[i] = secret[i];
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
    for (int i = 0; letters_guessed[i]; i++) {

    }
    
        
}

void hangman(const char secret[]){
    int tries = 8;
    char letter = ' ';

    char guessed_word[15];
    char letters_guessed[8];
    char available_letters[26];

    for (int j = 65, i = 0; j < 91; j++, i++)
        available_letters[i] = j;

    for (int i = 0; i < mx_strlen(secret); i++)
        guessed_word[i] = '_';
    

    get_guessed_word(secret, letters_guessed, guessed_word);
    
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", mx_strlen(secret));

    for (; tries > 0; tries--) {
                
        printf("-------------\n");
        printf("You have %d guesses left.\n", tries);
        printf("Available letters:");
        get_available_letters(letters_guessed, available_letters);
        printf(available_letters);
        
        scanf("%c", &letter);
    }   
    
}
