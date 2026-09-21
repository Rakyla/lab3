#ifndef BULLS_COWS_H
#define BULLS_COWS_H

#include <string>

// Генерирует случайное 4-значное число с различными цифрами
std::string generateSecretNumber();

// Проверяет корректность ввода: 4 символа, только цифры, без повторов
bool isValidGuess(const std::string& dogad);

// Считает количество быков (цифра на своём месте)
int countBulls(const std::string& secret, const std::string& dogad);

// Считает количество коров (цифра угадана, но не на своём месте)
int countCows(const std::string& secret, const std::string& dogad);

// Основной игровой цикл
void playGame();

#endif
