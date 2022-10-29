#ifndef LABA2_DIALOG_H
#define LABA2_DIALOG_H
#include <iostream>
#include "../lab/laba2.h"

namespace Instruments{

    template <typename X>

    int getNumber(X &num) {
        std::cin >> num;
        if(std::cin.eof())
            return 0;
        if (!std::cin.good() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        return 1;
    }

    int choose_answer();
    void output_menu();
}

namespace Dialog{

    void dialog();

}
#endif //LABA2_DIALOG_H