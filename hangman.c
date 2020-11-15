#include "hangman.h"

int mx_strlen(const char *s) {
    int i = 0;
    
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

char* get_word(char secret[]){
    secret = "purples";
    return secret;
}

int mx_strchr(const char *s, int c){
    for (int i = 0; i < mx_strlen(s); i++)
        if(s[i] == c)
            return 1;
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
    for (int i = 0; letters_guessed[i]; i++) 
        if (mx_strchr(available_letters, letters_guessed[i])) 

            for (int j = 0; j < mx_strlen(available_letters); j++) {
                if (j == mx_strlen(available_letters))
                    available_letters[j] = (0);
                else
                    available_letters[j] = available_letters[j + 1];
            }
}

void hangman(const char secret[]){
    int tries = 8;
    char letter;

    char guessed_word[15];
    char letters_guessed[8];
    char available_letters[26];

    for (int j = 97, i = 0; j < 123; j++, i++)
        available_letters[i] = j;

    for (int i = 0; i < mx_strlen(secret); i++)
        guessed_word[i] = '_';
    

    get_guessed_word(secret, letters_guessed, guessed_word);
    
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", mx_strlen(secret));

    for (; tries > 0;) {
                
        printf("-------------\n");
        printf("You have %d guesses left.\n", tries);
        printf("Available letters: ");
        get_available_letters(letters_guessed, available_letters);

        for (int j = 0; available_letters[j] != '\0'; j++)
            printf("%c", available_letters[j]);

        printf("%c", '\n');

        printf("Please guess a letter: ");
        scanf("%c", &letter);
        letters_guessed[8 - tries] = letter;
        if (is_word_guessed(secret, letters_guessed)) {
            get_guessed_word(secret, letters_guessed, guessed_word);
            printf("Good guess:");
            for (int j = 0; guessed_word[j] != '\0'; j++)
                printf(" %c", guessed_word[j]);
            printf("%c", '\n');
        } 
        else {
            printf("Oops! That letter is not in my word:");
            tries--;
            for (int j = 0; guessed_word[j] != '\0'; j++)
                printf(" %c", guessed_word[j]);
            printf("%c", '\n');
        }
            
        
        if(!mx_strchr(guessed_word, '_')){
            printf("-------------\nCongratulations, you won!");
            return;
        }
    }   
    printf("Sorry, you ran out of guesses. The word was ");
    for (int i = 0; secret[i]; i++)
        printf("%c", secret[i]);
    printf("%c", '.');
    
}
