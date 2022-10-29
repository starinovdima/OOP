#include "dialog.h"
#include "instruments.h"


namespace Dialog {

    void dialog() {
        int c;
        do {
            Instruments::output_menu();
            c = Instruments::choose_answer();
            const char *mes = "";
            switch (c) {
                case 0:
                    std::cout << "***\n--Goodbye!--\n***" << std::endl;
                    break;
                case 1:

                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 2:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 3:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 4:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 5:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 6:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
                case 7:
                    std::cout << "***\n--  --\n***" << std::endl;

                    break;
            }
        } while (c != 0);
    }
}

void Hotel_room::show_info() const {

    cout << "\n**********SHOW INFORMATION ABOUT ROOM**********" << endl;
    cout << "Room number " << number << " ";
    if (busy)
        cout << "busy" << endl;
    else
        cout << "free" << endl;
    cout << "Type is ";
    switch (type) {
        case 1:
            cout << "Lux" << endl;
            break;
        case 2:
            cout << "Multi room" << endl;
            break;
        case 3:
            cout << "Single room" << endl;
            break;
    }
    cout << "Daily rate of accommodation $" << rate << endl;

}
void Lux::show_info() const {
    Hotel_room::show_info();
    cout << "This hotel room has " << num_rooms << " rooms" << endl;
    cout << nums_persons << " people live here" << endl;
    cout << " *Information about guests* \n" << endl;
    for(int i = 0; i < nums_persons; i++){
        cout << i + 1 << "Guest" << endl;
        cout << "Registration date: " << person[i].getDay() << ".";
        cout << person[i].getMonth() << ".";
        cout << person[i].getYear() << endl;
        cout << "Number of days of stay " << person[i].getTime() << "\n" <<endl;
    }
}
void Single_room::show_info() const {
    Hotel_room::show_info();
    cout << "One guest lives here" << endl;
    cout << "Registration date: " << person.getDay() << ".";
    cout << person.getMonth() << ".";
    cout << person.getYear() << endl;
    cout << "Number of days of stay " << person.getTime() << "\n" <<endl;
}
void Multi_room::show_info() const {
    Hotel_room::show_info();
    cout << "This hotel room has " << num_seats << " seats" << endl;
    cout << nums_persons << " people live here" << endl;
    cout << " *Information about guests* \n" << endl;
    for(int i = 0; i < nums_persons; i++){
        cout << i + 1 << "Guest" << endl;
        cout << "Registration date: " << person[i].getDay() << ".";
        cout << person[i].getMonth() << ".";
        cout << person[i].getYear() << endl;
        cout << "Number of days of stay " << person[i].getTime() << "\n" <<endl;
    }
}


