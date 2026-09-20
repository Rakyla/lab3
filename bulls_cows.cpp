#include "bulls_cows.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



//  Генерация секретного числа
void generateSecret(char secret[5]) {
    bool used[10] = {false};   // массив-флаги: использована ли цифра
    int i = 0;                 // текущая позиция в secret

    while (i < 4) {
        int d = rand() % 10;   // случайная цифра 0..9

        // Первая цифра не должна быть нулём
        if (i == 0 && d == 0) continue;

        // Если цифра уже использовалась — пропускаем
        if (used[d]) continue;

        used[d] = true;        // помечаем цифру как использованную
        secret[i] = '0' + d;   // превращаем цифру в символ и пишем в массив
        i++;                   // переходим к следующей позиции
    }

    secret[4] = '\0';          // завершаем строку нулевым символом
}

//  Подсчёт быков
int countBulls(const char secret[5], const char guess[5]) {
    int bulls = 0;

    for (int i = 0; i < 4; i++) {
        // Если символ на позиции i совпал — это бык
        if (secret[i] == guess[i]) {
            bulls++;
        }
    }

    return bulls;
}


//  Подсчёт коров
int countCows(const char secret[5], const char guess[5]) {
    int cows = 0;

    for (int i = 0; i < 4; i++) {
        // Если это бык — не считаем как корову
        if (secret[i] == guess[i]) continue;

        // Ищем цифру guess[i] в секрете на любой позиции
        for (int j = 0; j < 4; j++) {
            if (guess[i] == secret[j]) {
                cows++;
                break; // нашли одну корову — дальше искать не нужно
            }
        }
    }

    return cows;
}


//  Игровой цикл
void playGame() {
    srand(time(0));            // инициализация генератора случайных чисел
    char secret[5];            // массив для секретного числа
    generateSecret(secret);    // генерируем секрет

    // Cообщение о старте игры
    cout << "Start" << endl;

    int attempts = 0;          // счётчик попыток

    while (true) {
        char guess[10];        // буфер для ввода (с запасом)
        cout << "> ";          // приглашение к вводу
        cin >> guess;

        // Длина ввода
        int len = 0;
        while (guess[len] != '\0') len++;   // считаем длину строки вручную

        if (len != 4) {
            cout << "4 sifri" << endl;
            continue;          // возвращаемся к началу цикла
        }

        attempts++;            // увеличиваем число попыток

        //Подсчёт быков и коров
        int bulls = countBulls(secret, guess);
        int cows  = countCows(secret, guess);

        // Вывод результата
        // B быков, K коров
        cout << bulls << "B " << cows << "K" << endl;

        //Проверка победы
        if (bulls == 4) {
            cout << "Win! Attempts: " << attempts << endl;
            break;             // выходим из цикла
        }
    }
}
