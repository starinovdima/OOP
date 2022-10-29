#include "dialog.h"
#include <iostream>


namespace Dialog {

    void dialog() {
        Lab2::Archimedes Circle;
        int c, error,n;
        double rad = 0, step,r1,r2;
        do {
            Instruments::output_menu();
            c = Instruments::choose_answer();
            const char *mes = "";
            switch (c) {
                case 0:
                    std::cout << "***\n--Goodbye!--\n***" << std::endl;
                    break;
                case 1:

                    std::cout << "***\n--Put step--\n***" << std::endl;

                    std::cout << "Please, enter step -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(step);

                    }while(error < 0 );
                    Circle.setA(step);
                    std::cout << "Your step is -> " << Circle.getA() << std::endl;

                    break;
                case 2:
                    std::cout << "***\n--Distance to center--\n***" << std::endl;
                    std::cout << "Please,enter the angle in radians -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(rad);

                    }while(error < 0 );
                    std::cout << "Distance to center -> " << Circle.distance(rad) << std::endl;
                    break;
                case 3:
                    std::cout << "***\n--Sector area--\n***" << std::endl;
                    std::cout << "Enter the first bounding radius -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(r1);

                    }while(error < 0 );

                    std::cout << "Enter the second bounding radius -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(r2);

                    }while(error < 0 );
                    std::cout << "The sector area is -> " << Circle.sector_area(r1,r2) << std::endl;
                    break;
                case 4:
                    std::cout << "***\n--Loop area--\n***" << std::endl;
                    std::cout << "Enter the coil turn number n (n > 0) -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(n);

                    }while(error < 0 || n <= 0);
                    std::cout << "The area of the figure is -> " << Circle.figure_area(n) << std::endl;
                    break;
                case 5:
                    std::cout << "***\n--Area of the n'th ring--\n***" << std::endl;
                    std::cout << "Enter the ring number n (n > 0) -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(n);

                    }while(error < 0 || n <= 0);
                    std::cout << "The area of the n-th ring of the spiral is -> " << Circle.ring_area(n) << std::endl;
                    break;
                case 6:
                    std::cout << "***\n--Spiral arc length--\n***" << std::endl;
                    std::cout << "Please,enter the angle in radians -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(rad);

                    }while(error < 0);
                    std::cout << "The spiral arc length is -> " << Circle.arc_length(rad) << std::endl;
                    break;
                case 7:
                    std::cout << "***\n--Spiral radius of curvature--\n***" << std::endl;
                    std::cout << "Please,enter the angle in radians -> ";
                    do{

                        std::cout << mes;
                        mes = "Invalid value! Repeat please -> ";
                        error = Instruments::getNumber(rad);

                    }while(error < 0);
                    std::cout << "The radius of curvature of the spiral is -> " << Circle.radius_of_curvature(rad) << std::endl;
                    break;
            }
        } while (c != 0);
    }
}



namespace Instruments {

    int choose_answer() {
        const char *mes1 = "";
        int choice, instr;
        do {
            std::cout << mes1;
            std::cout << "Make your choice: ";
            mes1 = "Invalid value! ";
            instr = Instruments::getNumber(choice);
            if(instr == 0)
                choice = 0;

        } while (choice < 0 || choice > 7 || instr < 0);
        return choice;
    }

    void output_menu(){
        const char *MSGS[] = {"0. Quit","1. Put step","2. Distance to center", "3. Sector area",
                              "4. Loop area","5. Area of the n'th ring","6. Spiral arc length",
                              "7. Spiral radius of curvature"};
        for (auto  i : MSGS) {
            std::cout << i << std::endl;
        }
    }
}

