#include "dialog.h"
#include <iostream>


namespace Dialog {

    void dialog() {
        int c;
        double duration;
        Binary_signal signal;

        std::cout << "\n--Hello, you are using the Binary Signal software." << std::endl;
        std::cout << "At the moment, " << Binary_signal::get_SZ() << " signal states are defined." << std::endl;
        std::cout << "If you want to change this values, go to the library and do it manually.\n" << std::endl;
        std::cout << "Please set max_duration - > ";
        Instruments::getAll(duration);
        signal.setMax_duration(duration);
        std::cout << "\nMaximum signal duration -> " << signal.getDuration() << std::endl;

        do {
            Instruments::output_menu();
            c = Instruments::choose_answer();
            switch (c) {
                case 0:
                    std::cout << "***\n--Goodbye!--\n***" << std::endl;
                    break;
                case 1:
                    std::cout << "***\n-- Constant Signal Initialization (1 or 0) --\n***" << std::endl;
                    Constant_Signal_Initialization(signal);
                    break;
                case 2:
                    std::cout << "***\n-- Initialization from a string --\n***" << std::endl;
                    Initialization_from_string(signal);
                    break;
                case 3:
                    std::cout << "***\n-- Add state signal to free space --\n***" << std::endl;
                    Add_signal(signal);
                    break;
                case 4:
                    std::cout << "***\n-- Signal output --\n***" << std::endl;
                    Signal_output(signal);
                    break;
                case 5:
                    std::cout << "***\n-- Invert signal --\n***" << std::endl;
                    signal = ~signal;
                    std::cout << "\nSignal inversion completed!\n" << std::endl;
                    break;
                case 6:
                    std::cout << "***\n-- Signal completion --\n***" << std::endl;
                    Signal_completion(signal);
                    break;
                case 7:
                    std::cout << "***\n-- Insert at a specific point in time --\n***" << std::endl;
                    Insert_in_time(signal);
                    break;
                case 8:
                    std::cout << "***\n-- Copying a signal a certain number of times --\n***" << std::endl;
                    Cooping(signal);
                    break;
                case 9:
                    std::cout << "***\n-- Removing a fragment --\n***" << std::endl;
                    Removing_fragment(signal);
                    break;
                case 10:
                    std::cout << "***\n-- Remove all signal --\n***" << std::endl;
                    signal.cleaning_all();
                    std::cout << "\n The cleaning is over! " << std::endl;
                    break;
            }
        } while (c != 0);


    }

    void Constant_Signal_Initialization(Binary_signal &signal){
        char answer_num, answer;

        std::cout << "\nDo you understand that your current signal will change completely, continue?" << std::endl;
        std::cout << "Enter y/n (yes or not) -> ";
        Instruments::answer_(answer,'y','n');
        if(answer == 'n')
            return;
        std::cout << "\nWhat signal do you want to send? (1 or 0)" << std::endl;
        std::cout << "Press 1 or 0  ->  " ;
        Instruments::answer_(answer_num,'1','0');
        Binary_signal signal1(answer_num,signal.getDuration());
        signal = signal1;
        std::cout << "\nSignal set!" << std::endl;


    }

    void Initialization_from_string(Binary_signal &signal){

        char answer;
        std::cout << "\nDo you understand that your current signal will change completely, continue?" << std::endl;
        std::cout << "Enter y/n (yes or not) -> ";
        Instruments::answer_(answer,'y','n');
        if(answer == 'n')
            return;
        std::cout << "Please enter in order:\n"
                     "Maximum signal duration .....\\n\n"
                     "Signal value ...\\n\n"
                     "Duration of value ...\\n" << std::endl;
        try{
            std::cin >> signal;
            if(std::cin.fail())
                throw std::invalid_argument("Incorrect enter!");
            std::cout << "\nSignal set!" << std::endl;

        } catch (std::exception &er) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr<< er.what() << std::endl;
            std::cout << "Signal didn't set...";
        }


    }

    void Signal_output(Binary_signal &signal){

        std::cout << "\n\nSignal ->  ";
        std::cout << signal;
        std::cout << "\nSignal duration is " << signal.time_check() << std::endl;

    }

    void Add_signal(Binary_signal &signal){
        char symbol;
        double time;
        std::cout << "\nEnter the signal state value (one symbol) -> " ;
        Instruments::getAll(symbol);
        std::cout << "Enter the duration of the state -> ";
        Instruments::getAll(time);
        try{
            signal.add_signal_to_end(symbol,time);
            std::cout << "\n`Signal set!" << std::endl;

        }
        catch (const std::exception &mes) {
            std::cerr << mes.what() << std::endl;
        }


    }

    void Signal_completion(Binary_signal &signal){

        std::cout << "Please enter the signal you want to add to the existing one" << std::endl;

        try{
            Binary_signal signal1;
            std::cin >> signal1;
            if(std::cin.fail())
                throw std::invalid_argument("Incorrect enter!");
            signal += signal1;
            std::cout << "\nSignal added!" << std::endl;

        } catch (std::exception &er) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << er.what() << std::endl;
            std::cout << "Signal didn't set...";
        }

    }

    void Cooping(Binary_signal &signal){
        int n;

        std::cout << "Enter how many times do you want to copy the current signal?" << std::endl;
        std::cout << "Enter - > ";
        Instruments::getAll(n);
        try{
            signal *= n;
            std::cout << "Signal copied " << n << " times" << std::endl;
        }catch(std::exception &er){
            std::cerr << er.what() << std::endl;
        }

    }

    void Insert_in_time(Binary_signal &signal){
        double time_del, how_much;
        unsigned char answer;

        std::cout << "Enter the time at which you want to insert signal status" << std::endl;
        std::cout << "Enter -> ";
        Instruments::getAll(time_del);
        std::cout << "\nWhat signal do you want to send? (1 or 0)" << std::endl;
        std::cout << "Press 1 or 0  ->  " ;
        Instruments::getAll(answer);
        std::cout << "How much time should be allocated for the signal?" << std::endl;
        std::cout << "Enter - > ";
        Instruments::getAll(how_much);
        try{
            signal.insert_to_time(how_much,answer,time_del);
            std::cout << "Signal status added!" << std::endl;
        } catch (std::exception &er) {
            std::cerr << er.what() << std::endl;
        }

    }

    void Removing_fragment(Binary_signal &signal){
        double time_del, how_much;
        char answer;

        std::cout << "Enter the time at which you want to delete signal status" << std::endl;
        std::cout << "Enter -> ";
        Instruments::getAll(time_del);
        int ind  = signal.find_signal(time_del);
        if(ind == -1){
            std::cout << "Signal didn't find!" << std::endl;
            return;
        }
        std::cout << "This signal is " << signal.getValue(ind) << " his time is "<< signal.getseconds(ind) << std::endl;
        std::cout << "Do you want to remove the signal status completely?" << std::endl;
        std::cout << "Enter y/n (yes or not) -> ";
        Instruments::answer_(answer,'y','n');
        if(answer == 'y'){
            try {
                signal.delete_to_time(time_del, -1);
                std::cout << "Signal status completely removed!" << std::endl;
            }catch (std::exception &er){
                std::cerr << er.what() << std::endl;
            }
        }else{
            std::cout << "How much to reduce the signal? Less than " << signal.getseconds(ind) << std::endl;
            std::cout << "Enter - > ";
            Instruments::getAll(how_much);
            try{
                signal.delete_to_time(time_del,how_much);
                std::cout << "Signal status сut" << std::endl;

            }catch (std::exception &er){
                std::cerr << er.what() << std::endl;
            }
        }
    }

}



namespace Instruments {

    int choose_answer() {
        int choice;
        do {

            std::cout << "Make your choice: ";
            Instruments::getAll(choice);

        } while (choice < 0 || choice > 10);
        return choice;
    }

    void output_menu(){
        const char *MSGS[] = {"\n0. Quit (0 or Ctrl+d)","1. Constant Signal Initialization(1 or 0) ",
                              "2. Initialization from a string", "3. Signal input", "4. Signal output",
                              "5. Invert signal","6. Signal completion", "7. Insert at a specific point in time",
                              "8. Copying a signal a certain number of times", "9. Removing a fragment",
                                "10. Remove all signal"};
        for (auto  i : MSGS) {
            std::cout << i << std::endl;
        }
    }

    void answer_(char &answer,const char one,const char two){

        const char *mes = "";

        do {
            std::cout << mes;
            mes = "Invalid value! Repeat please -> ";
            Instruments::getAll(answer);

        }while (answer != one && answer != two);
    }


}

