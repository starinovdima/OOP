#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include <iostream>

namespace Laba3 {

    struct Signal_status {

        unsigned char value;             //Значение состояния сигнала
        double seconds;                  //Длительность состояния сигнала

    };

    class Binary_signal {

    private:

        static const int SZ = 1000;                 //Колличество состояний сигнала

        double max_duration = 100;                //Максимальная длительность сигнала

        Signal_status status[SZ]{};             //Последовательность состояний сигнала

        int place_check() const;

        int free_place_check() const;

        void signal_reorganization();


    public:

        Binary_signal() = default;

        explicit Binary_signal(double m_duration) : max_duration(m_duration) {};

        explicit Binary_signal(unsigned char num, double duration);

        explicit Binary_signal(const unsigned char *string, double time, int sum, double duration);

        ~Binary_signal() = default;                                                     //Деструктор

        void setMax_duration(const double time){max_duration = time;};
        void setValue(const unsigned char m_value,const int ind) {status[ind].value = m_value;}     //Поставить значение состояния
        void setSeconds(const double &m_seconds,const int ind) {status[ind].seconds = m_seconds;}
        double getDuration() const {return max_duration;}
        static int get_SZ()  {return SZ;}                                                //Просмотреть колличество состояний
        unsigned char getValue (const int ind) const {return status[ind].value;}       //Просмотреть n-е состояние значение
        double getSeconds(const int ind) const {return status[ind].seconds;}           //Просмотреть n-е состояние время
        int find_signal(double time) const;
        double time_check() const;


        friend std::ostream & operator <<(std::ostream & ,const Binary_signal &signal); // <<
        friend std::istream & operator >>(std::istream &, Binary_signal &signal); // >>

        void insert_to_time(double duration,unsigned char symbol,double time);
        void delete_to_time(double time, double how_much);

        Binary_signal & operator +=(const Signal_status &); // Вставка статус сигнала в конец
        Binary_signal operator +(const Signal_status &) const;
        Binary_signal & operator *= (int n); // *=
        Binary_signal operator +(const Binary_signal &signal) const;
        Binary_signal & operator += (const Binary_signal &);
        Binary_signal  operator ~(); // ~
        Binary_signal & operator -- (); // Очищение сигнала
        //a = b + c
        //

    };

    namespace Instruments_2{
        int array_length(const unsigned char *string);
    }





}
#endif
