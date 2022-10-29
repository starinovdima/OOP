#include <iostream>
#include "lab1.h"


namespace Lab1{

    using std::cin;
    using std::cout;
    using std::endl;



    Matrix *input(int &amount){

        const char *mes1 = "Please number of rows --> ";
        const char *mes2 = "Please number of lines -->";

        int height = get_num(mes1,1);
        int width = get_num(mes2,1);

        int *all;

        try{
            all = new int[height*width]();

        }
        catch (const std::bad_alloc &bd) {

            cout << bd.what() << endl;
            return nullptr;
        }

        cout << "Please, enter value for matrix :" << endl;
        const char *mes3 = "";

        for(int i = 0;i < height*width; i++){
            all[i] = get_num(mes3,0);
            if(all[i] != 0)
                amount ++;
        }
        Matrix *matrix ;
        matrix = add_memory(amount);
        if(matrix == nullptr || matrix->point == nullptr)
            return nullptr;

        matrix->height = height;
        matrix->width = width;


        int number = 0;
        for (int i = 0;i < height*width;i++){
            if(all[i] != 0){
                matrix->point[number].value = all[i];
                int j = i % width;
                int k = i / width;
                matrix->point[number].x = j;
                matrix->point[number].y = k;

                number++;

            }
        }
        delete [] all;

        return matrix;
    }

    void output(Matrix *mat){
        int count = 0;
        for(int i = 0; i < mat->width*mat->height; i++){
            if(i % mat->width == 0)
                cout << endl;
            if(mat->point[count].x + mat->point[count].y * mat->width == i){
                cout << mat->point[count].value << " ";
                count ++;
            }else
                cout << "0" << " ";
        }
        cout << "\n" << endl;

    }


    Matrix *add_memory(int amount){

        Matrix *matrix;
        try{
            matrix = new Matrix;
        }
        catch (const std::bad_alloc &x) {


            cout << x.what() << endl;
            return nullptr;

        }
         try {
             matrix->point = new Point[amount];
         }
         catch (const std::bad_alloc &p) {

             cout << p.what() << endl;
             delete matrix;
             return nullptr;

        }

        return matrix;

    }
 Analyze->Run Code
    int get_num(const char *say, int limit){
        int num;
        const char *mes1 = "";
        do {
            cout << mes1;
            cout << say;
            mes1 = "\nInvalid value!\n";
            if(getInt(num)<0 || std::cin.peek() != '\n'){
                cin.clear();
                cin.ignore(500, '\n');
                num = -1;
            }
        }while(num < limit);

        return num;

    }

    void erase(Matrix *mat){
        delete [] mat->point;
        delete mat;
    }

    Matrix *work_with_matrix(Matrix *mat,int amount){
        int old_size = 0, for_mas = 0;
        Matrix *new_mat = nullptr;
        int *how, *check = nullptr;
        try{
            how = new int[mat->height]();

        }
        catch (std::bad_alloc &pp) {
            cout << pp.what() << endl;
            return nullptr;
        }

        int n = 0, i = 0;
        while (n < mat->height){
            int x = 0;
            while(mat->point[i].y == n && i/mat->width < mat->width){
                int j = i + 1;
                int pr = 0;
                if(j > (amount - 2))
                    break;
                while(mat->point[j].y == n && j/mat->width < mat->width){
                    if(mat->point[i].value == mat->point[j].value){
                        if(pr == 0){
                            if(new_mat == nullptr)
                                new_mat = add_memory(old_size);
                            if(check_for_availability(mat->point[i].value,check,for_mas))
                                break;
                            check = realloc(check,for_mas,1);
                            check = add_to_mas(check,for_mas,mat->point[i].value);
                            new_mat->point = realloc(new_mat->point,old_size,2);
                            new_mat->point[old_size] = {mat->point[i].value,x,n};
                            new_mat->point[old_size+1] = {mat->point[j].value,x+1,n};
                            old_size += 2;
                            for_mas += 1;
                            x += 2;
                            pr = 1;
                            if(how[n] < 1)
                                how[n] = 2;
                            else
                                how[n]= how[n] + 2;
                        } else{
                            if(new_mat == nullptr)
                                new_mat = add_memory(old_size);
                            new_mat->point = realloc(new_mat->point,old_size,1);
                            new_mat->point[old_size] = {mat->point[j].value,x,n};
                            old_size ++;
                            x++;
                            how[n] += 1;
                        }
                    }
                    j++;

                }
                i++;
                if(i > (amount - 1))
                    break;
            }

            clean_mas(check);
            check = nullptr;
            for_mas = 0;
            n++;
        }

        if(new_mat == nullptr)
            cout << "Matrix cannot be built, no repeating elements!" << endl;
        else
            output_new(new_mat,how,mat->height);
        return new_mat;
    }

    void output_new(Matrix *mat, const int *how_it_input,int height){

        int k = 0;
        for(int i = 0; i < height; i++){
            for(int j = 0;j < how_it_input[i]; j++){
                cout  << mat->point[k].value<< " ";
                k++;
            }
            if(how_it_input[i] != 0)
                cout << endl;
        }
        delete [] how_it_input;
    }

    int *add_to_mas(int *mas,int old_size,int num){
        mas[old_size] = num;
        return mas;
    }

    bool check_for_availability(int number,const int *mas_pr, int old_size){
        for(int i = 0; i < old_size; i ++){
            if(mas_pr[i] == number)
                return true;
        }
        return false;

    }
    void clean_mas(const int *mas){
        delete [] mas;
    }


}