// Copyright 2022 Filatov Maxim
#ifndef INCLUDE_COLOR_H_
#define INCLUDE_COLOR_H_

#include <iostream>
#include <windows.h>
#include <conio.h>
/// <summary>Перечисление цветов: white, yellow, azure, red, blue, violet, green, violet_dark, blue_dark, gray_dark</summary>
enum colors {
    white,
    yellow,
    azure,
    red,
    blue,
    violet,
    green,
    violet_dark,
    blue_dark,
    gray_dark,
};

/// <summary>Класс цвтов в консоли </summary>
class color {
private:
    colors type;

public:
    color() : type(colors::white) {};
    color(colors _type) : type(_type) {};
    friend std::ostream& operator << (std::ostream& os, const color& color) {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        color.type == white ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) :
            color.type == yellow ? SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY) :
            color.type == azure ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY) :
            color.type == red ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY) :
            color.type == blue ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY) :
            color.type == violet ? SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE) :
            color.type == green ? SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY) :
            color.type == violet_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE) :
            color.type == blue_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN) :
            color.type == gray_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY) :
            NULL;
        return os;
    }

    /// <summary>Функция выводацветной фразы</summary>
    /// <returns>std::string - "" (ничего)</returns>
    std::string print(std::string word) {
        std::cout << color(type) << word << color();
        return "";
    }
};

#endif  // INCLUDE_STACK_H_
