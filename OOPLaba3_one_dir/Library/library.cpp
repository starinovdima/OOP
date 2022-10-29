#include "library.h"


namespace Laba3{


    Binary_signal::Binary_signal(unsigned char num, double duration) : max_duration(duration){
        status[0].value = num;
        status[0].seconds = max_duration;
    }

    Binary_signal::Binary_signal(const unsigned char *string,double time,int sum,double duration) : max_duration(duration)
    {
        if(time > max_duration)
            throw std::invalid_argument("Error with time");
        double seconds = time / (double) sum;
        for(int i = 0; i < SZ; i++){
            if(string[i] == '\0')
                break;
            if(string[i] != '0' && string[i] != '1')
                throw std::invalid_argument("Incorrect value!");
            status[i].value = string[i];
            status[i].seconds = seconds;
        }
    }

    std::ostream & operator << (std::ostream & s,const Binary_signal &signal){

        for (int i = 0; i < Binary_signal::get_SZ(); i++) {
            if (signal.status[i].seconds != 0) {
                s << signal.status[i].value;
            }
        }
        return s;

    }

    std::istream &operator>>(std::istream &s, Binary_signal &signal) {
        unsigned char string[Binary_signal::get_SZ()];
        double duration;
        double time;

        s >> duration;

        s >> string;

        s >> time;

        int sum = Instruments_2::array_length(string);
        signal = Binary_signal(string,time,sum,duration);

        return s;

    }

    double Binary_signal::time_check() const{
        double count = 0;
        for(int i = 0;i < SZ;i++){
            if(status[i].seconds != 0)
                count += status[i].seconds;
        }
        return count;

    }

    int Binary_signal::place_check() const{

        for(int i = 0; i < SZ; i ++){
            if(status[i].seconds == 0)
                return i;
        }
        return -1;

    }

    int Binary_signal::free_place_check() const{
        int count = 0;

        for(int i = 0; i < SZ; i ++){
            if(status[i].seconds == 0)
                count ++;
        }
        return count;
    }


    void Binary_signal::signal_reorganization() {

        double signal_time = time_check();
        double ex_time = 0;
        for(int i = 0; i < SZ; i++){
            if(ex_time < signal_time)
                if(status[i].seconds == 0){
                    for(int k = i; k < SZ; k++){
                        if((k + 1) > SZ)
                            break;
                        Signal_status variable = status[k+1];
                        status[k] = status[k+1];
                        status[k+1] = variable;
                    }
                }
            ex_time += status[i].seconds;
        }

    }


    void Binary_signal::insert_to_time(double duration,unsigned char symbol,double time) {

        if(duration + time_check() > max_duration)
            throw std::invalid_argument("Time error, not enough free time!");
        if(place_check() == -1)
            throw std::invalid_argument("No room to add signal state!");
        if(symbol != '0' && symbol != '1')
            throw std::invalid_argument("Incorrect value!");

        signal_reorganization();

        int ind = find_signal(time);
        int sz = SZ;

        for(int i = sz - 1; i > ind; i--){

            Signal_status variable = status[i];
            status[i] = status[i-1];
            status[i-1] = variable;
        }

        status[ind].value = symbol;
        status[ind].seconds = duration;


    }

    int Binary_signal::find_signal(double time) const {
        double count = 0;
        for(int i = 0; i < SZ; i++){
            count += status[i].seconds;
            if(time < count)
                return i;
        }
        return -1;
    }

    void Binary_signal::delete_to_time(double time,double how_much) {

        int ind = find_signal(time);
        if(ind == -1)
            throw std::invalid_argument("Signal didn't find!");
        if(how_much == -1){
            status[ind].value = '0';
            status[ind].seconds = 0;
        }else{
            if(how_much > status[ind].seconds)
                throw std::invalid_argument("Error with time!");
            status[ind].seconds -= how_much;
        }

    }



    Binary_signal Binary_signal::operator~()  {
        Binary_signal signal = *this;
        for (int i = 0; i < Binary_signal::get_SZ(); i++){
            if(signal.status[i].seconds != 0){
                if(signal.status[i].value == '0')
                    signal.status[i].value = '1';
                else
                    signal.status[i].value = '0';
            }
        }

        return signal;
    }

    Binary_signal &Binary_signal::operator += (const Binary_signal &signal_two) {

        if(signal_two.time_check() > max_duration - (double) time_check())
            throw std::invalid_argument("We cannot add this signal, time error!");

        if(SZ - signal_two.free_place_check() > free_place_check())
            throw std::invalid_argument("We cannot add this signal, size error!");

        signal_reorganization();

        for(int i = 0; i < SZ; i++){
            if(signal_two.getSeconds(i) != 0) {
                status[place_check()].value = signal_two.getValue(i);
                status[place_check()].seconds = signal_two.getSeconds(i);
            }
        }
        return *this;
    }

    Binary_signal Binary_signal::operator +(const Binary_signal &signal) const {
        Binary_signal sum = *this;
        return sum += signal;
    }

    Binary_signal &Binary_signal::operator *=(int n) {

        if(time_check() * (n-1) > max_duration)
            throw std::invalid_argument("Time limit!");
        if(free_place_check() < (SZ - free_place_check()) * (n-1))
            throw std::invalid_argument("Size limitation!");

        signal_reorganization();
        int old_size = place_check();
        for(int i = 0; i < n-1; i ++){
            for(int j = 0; j < old_size; j++){
                status[place_check()] = status[j];
            }
        }

        return *this;
    }

    Binary_signal &Binary_signal::operator--() {

        for(int i = 0;i < SZ;i++){
            status[i].value = '0';
            status[i].seconds = 0;
        }
        return *this;

    }

    Binary_signal &Binary_signal::operator += (const Signal_status &st) {

        if(st.seconds + time_check() > max_duration)
            throw std::invalid_argument("Time error, not enough free time!");
        if(place_check() == -1)
            throw std::invalid_argument("No room to add signal state!");
        if(st.value != '0' && st.value != '1')
            throw std::invalid_argument("Incorrect value!");

        signal_reorganization();

        status[place_check()].value = st.value;
        status[place_check()].seconds = st.seconds;

        std::cout << "\nSignal status with " << st.value << "added to location " << place_check() << std::endl;

        return *this;

    }

    Binary_signal Binary_signal::operator+(const Signal_status &st) const {
        Binary_signal signal1 = *this;
        return signal1 += st;
    }

    namespace Instruments_2{
        int array_length(const unsigned char *string) {
            int count = 0;
            for(int i = 0; i < Laba3::Binary_signal::get_SZ(); i++){
                if(string[i] == '\0')
                    return count;
                count ++;
            }
            return count;

        }
    }
}
