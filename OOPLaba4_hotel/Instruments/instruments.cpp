#include "instruments.h"

namespace Instruments {

    int GetRandomNumber(int from, int to) {
        std::random_device rd;

        return std::bind(
                std::uniform_int_distribution<int>{from, to + 1},
                std::default_random_engine{rd()})();
    }

    int choose_answer() {
        int choice;
        do {

            std::cout << "Make your choice: ";
            Instruments::getAll(choice);

        } while (choice < 0 || choice > 7);
        return choice;
    }

    void output_menu() {
        const char *MSGS[] = {"0. Quit", "1. ", "2. ", "3. ",
                              "4. ", "5. ", "6. ",
                              "7. "};
        for (auto i: MSGS) {
            std::cout << i << std::endl;
        }
    }

}