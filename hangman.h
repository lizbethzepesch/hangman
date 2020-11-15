#ifndef HANGMAN_H
#define HANGMAN_H

#include "stdio.h"
#include <stdlib.h>

char* get_word(char secret[]);

int is_word_guessed(const char secret[], const char letters_guessed[]); 
//с помощью данной функции можно будет узнать, угадано ли слово (незаглавные буквы).

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]);
//обновит выписываемое слово так, что на неотгаданных позициях будет находиться символ '_', 
//а на уже отгаданных - конкретные буквы.

void get_available_letters(const char letters_guessed[], char available_letters[]);
// обновит список букв, которые ещё не были использованы для отгадавания.

void hangman(const char secret[]);
// содержит в себе функционал самой игры.

//Все 5 функций (4, которые вам предстоит написать, и функция get_word(), которая уже готова) 
//будут находиться в файле hangman.c. Их декларации находятся в файле hangman.h. 
//Сама программа будет находиться в файле main.c, 
//которая считает случайное слово из словаря с помощью функции get_word() и отдаст на вход функции hangman().

#endif
