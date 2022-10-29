#include <iostream>
#include "lab1.h"

using namespace Lab1;



int main() {

    std::cout << "Lab1" << std::endl;
    try{
        int kik = 0;
        int &amount = kik;
        Matrix *mat = input(amount);
        Matrix *new_mat = nullptr;
        output(mat);
        if(amount != 0)
            new_mat = work_with_matrix(mat,amount);
        else
            std::cout << "Matrix cannot be built, no repeating elements!" << std::endl;
        erase(mat);
        if(new_mat != nullptr)
            erase(new_mat);
    }
    catch (const std::bad_exception &p) {

        std::cout << p.what()  << std::endl;

    }

    return 0;
}
