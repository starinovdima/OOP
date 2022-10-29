#ifndef LABA1_LAB1_H
#define LABA1_LAB1_H

namespace Lab1{

    struct Point{
        int value;
        int x;
        int y;
    };

    struct Matrix{

        int height;
        int width;

        Point *point;
    };


    template <typename X>

    int getInt(X &num){
        std::cin >> num;
        if(!std::cin.good())
            return -1;
        return 1;
    }

    template <typename Y>

    Y *realloc(Y *old,int old_size,int how_much){
        Y *new_mas;
        try{
            new_mas  = new Y[old_size+how_much]();
        }
        catch (const std::bad_alloc &bd) {

            std::cout << bd.what() << std::endl;
            return nullptr;
        }

        for(int i = 0;i < old_size;i++){
            new_mas[i] = old[i];
        }
        delete [] old;
        return new_mas;
    }



    Matrix *input(int &);
    void output(Matrix *mat);
    void erase(Matrix *mat);
    Matrix *work_with_matrix(Matrix *mat, int);
    int get_num(const char *say,int limit);
    Matrix *add_memory(int amount);
    void output_new(Matrix *mat, const int *how_it_input, int height);
    bool check_for_availability(int number,const int *mas_pr, int old_size);
    int *add_to_mas(int *mas,int old_size,int num);
    void clean_mas(const int *mas);
}

#endif //LABA1_LAB1_H
