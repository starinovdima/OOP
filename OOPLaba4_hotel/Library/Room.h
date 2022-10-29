#ifndef LABA4_HOSTEL_HOSTEL_LIB_H
#define LABA4_HOSTEL_HOSTEL_LIB_H
#include <iostream>
#include "Vector.h"
#include "instruments.h"

namespace Laba4{
    using namespace My_vector;

    struct Info{
        const char *what;
        int how;
        void set(const char *m_what,int m_how) {what = m_what; how = m_how;}
    };

    class Hotel_room {

    private:
        int number;
        int type;
        bool busy;
        double rate;

    public:
        Hotel_room() : number(0),type(0),busy(false),rate(0){}

        virtual ~Hotel_room(){}

        void setNumber(int m_number) {number = m_number;}
        void setType(int m_type) {type = m_type;}
        void setBusy(bool m_busy) {busy = m_busy;}
        void setRate(double m_rate) {rate = m_rate;}

        int getType() const{ return type;}
        bool getBusy() const {return busy;}
        int getNum() const {return number;}
        double getRate() const {return rate;}

        virtual void eviction();
        virtual Vector<Info> show_info() = 0;
        virtual void start_room(int num_room, int rate) = 0;
        virtual int getNum_persons() const = 0;

    };


}


#endif //LABA4_HOSTEL_HOSTEL_LIB_H
