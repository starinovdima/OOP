#ifndef LABA4_HOTEL_INSTRUMENTS_H
#define LABA4_HOTEL_INSTRUMENTS_H
#pragma once
#include <iostream>
#include <random>
#include <functional>

namespace Instruments {

    template<typename X>

    int getAll(X &num) {
        int right;
        const char *mes1 = "";
        do {
            std::cout << mes1;
            mes1 = "Invalid value! Repeat please -> ";
            right = 0;
            std::cin >> num;
            if (std::cin.eof()) {
                num = 0;
                return 0;
            }
            if (!std::cin.good() || std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                right = 1;
            }
        } while (right == 1);
        return num;
    }

    int GetRandomNumber(int from, int to);
    int choose_answer();
    void output_menu();
}
#endif //LABA4_HOTEL_INSTRUMENTS_H
