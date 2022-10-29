#ifndef LABA2_DIALOG_H
#define LABA2_DIALOG_H
#include <iostream>
#include "library.h"
namespace Instruments{

    template <typename X>

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
        }while(right == 1);
        return num;
    }

    int choose_answer();
    void output_menu();
    void answer_(char &answer,const char one,const char two);
}


namespace Dialog{

    using namespace Laba3;

    void dialog();
    void Constant_Signal_Initialization(Binary_signal &signal);
    void Initialization_from_string(Binary_signal &signal);
    void Add_signal(Binary_signal &signal);
    void Signal_output(Binary_signal &signal);
    void Signal_completion(Binary_signal &signal);
    void Insert_in_time(Binary_signal &signal);
    void Cooping(Binary_signal &signal);
    void Removing_fragment(Binary_signal &signal);

}
#endif