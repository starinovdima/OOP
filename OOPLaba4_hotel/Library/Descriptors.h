#ifndef LABA4_HOTEL_DESCRIPTORS_H
#define LABA4_HOTEL_DESCRIPTORS_H
#include "Room.h"

namespace Laba4{

    using namespace My_vector;

    class Person{
    private:
        int day,month,year;
        int time;
    public:
        Person () : day(0),month(0),year(0),time(0){}
        Person (int m_day, int m_month, int m_year, int m_time) : day(m_day),month(m_month),year(m_year),time(m_time) {}

        ~Person() {}

        void setTime(int m_time) {time = m_time;}
        void setData(int m_day,int m_month,int m_year) {day = m_day;month = m_month;year = m_year;}

        int getTime() const {return time;}
        int getDay() const {return day;}
        int getMonth() const {return month;}
        int getYear() const {return year;}

        Person & operator = (const Person &);
        Person & operator = (Person &&);

        friend bool operator ==(Person &per1, Person &per2);
        friend bool operator !=(Person &per1, Person &per2);


    };

    class Lux : public Hotel_room{
    private:
        int num_rooms;
        int nums_persons;
        Vector<Person> person;
    public:
        Lux() :  num_rooms(0),nums_persons(0) { setType(1);}
        Lux(int m_num_rooms) : num_rooms(m_num_rooms),nums_persons(0) {setType(1);}

        virtual ~Lux() {}

        void setNum_rooms(int num) {num_rooms = num;}
        void setNum_persons(int num) {nums_persons = num;}
        Person &getGuests(int ind){ return person[ind];}
        Vector<Person> getPerson(){return person;}

        int getNum_rooms() const {return num_rooms;}

        virtual int getNum_persons() const {return nums_persons;}
        virtual void registration(Vector<Person> m_person) ;
        virtual void eviction() ;
        virtual void start_room(int num_room, int rate);
        virtual Vector<Info> show_info();


        Lux & operator = (const Lux &);
        Lux & operator = (Lux &&);

        friend bool operator ==(Lux &per1, Lux &per2);
        friend bool operator !=(Lux &per1, Lux &per2);


    };

    class Single_room : public Hotel_room{
    private:
        Person person;
    public:
        Single_room() {setType(3);}

        virtual ~Single_room() {}

        Person &getGuests(){ return person;}
        Person &getPerson(){return person;}

        virtual int getNum_persons() const {return 1;}
        virtual void registration(Vector<Person> m_person) ;
        virtual void eviction() ;
        virtual void start_room(int num_room, int rate) ;
        virtual Vector<Info> show_info();


        Single_room & operator = (const Single_room &);

        friend bool operator ==(Single_room &per1, Single_room &per2);
        friend bool operator !=(Single_room &per1, Single_room &per2);

    };

    class Multi_room : public Hotel_room{
    private:
        int num_seats;
        int nums_persons;
        Vector<Person> person;
    public:
        Multi_room() : nums_persons(0), num_seats(0) {setType(2);}

        virtual ~Multi_room() {}

        void setNum_seats(int num) {num_seats = num;}
        void setNum_persons(int num) {nums_persons = num;}

        int getNum_seats() const {return num_seats;}
        virtual int getNum_persons() const {return  nums_persons;}

        void add_to_multi(Vector<Person> m_person);
        void delete_from_multi(Vector<Person> m_person);
        Person &getGuests(int ind){ return person[ind];}
        Vector<Person> getPerson(){return person;}

        virtual void registration(Vector<Person> m_person) ;
        virtual void eviction() ;
        virtual void start_room(int num_room,int rate) ;
        virtual Vector<Info> show_info();


        Multi_room & operator = (const Multi_room &);
        Multi_room & operator = (Multi_room &&);

        friend bool operator ==(Multi_room &per1, Multi_room &per2);
        friend bool operator !=(Multi_room &per1, Multi_room &per2);

    };




}

#endif //LABA4_HOTEL_DESCRIPTORS_H
