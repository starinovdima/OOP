#include "Descriptors.h"

namespace Laba4 {
    using std::cout, std::endl;


    void Lux::registration(Vector<Person> m_person) {

        if (m_person.empty() || m_person.size() > 2)
            throw std::invalid_argument("Invalid number of guests for this rooms");

        setBusy(true);
        nums_persons = m_person.size();
        for (int i = 0; i < m_person.size(); i++) {
            person[i].setData(m_person[i].getDay(), m_person[i].getMonth(), m_person[i].getYear());
            person[i].setTime(m_person[i].getTime());
        }
    }

    void Lux::eviction() {
        Hotel_room::eviction();
        person.clear();
        nums_persons = 0;
    }

    void Lux::start_room(int num_room, int rate) {

        setType(1);
        setBusy(false);
        setNumber(num_room);
        num_rooms = Instruments::GetRandomNumber(2, 5);
        setRate(rate);

    }

    Lux &Lux::operator=(const Lux &s) {
        if (this != &s) {
            nums_persons = s.nums_persons;
            num_rooms = s.num_rooms;
            setBusy(s.getBusy());
            setRate(s.getRate());
            setNumber(s.getNum());
            setType(s.getType());
            for (int i = 0; i < nums_persons; i++) {
                person[i] = s.person[i];
            }

        }
        return *this;
    }

    Lux &Lux::operator=(Lux &&s) {
        if (this != &s) {
            std::swap(nums_persons, s.nums_persons);
            std::swap(num_rooms, s.num_rooms);
            setBusy(s.getBusy());
            setRate(s.getRate());
            setNumber(s.getNum());
            setType(s.getType());
            person.swap(s.person);
        }
        return *this;
    }


    bool operator==(Lux &per1, Lux &per2) {
        return (per1.num_rooms == per2.nums_persons && per1.num_rooms == per2.num_rooms && per1.person == per2.person);
    }

    bool operator!=(Lux &per1, Lux &per2) {
        return  !(per1 == per2);
    }

    Vector<Info> Lux::show_info() {
        Vector<Info> info(5);
        info[0].set("Number rooms is ",getNum());
        info[1].set("type ",getType());
        info[2].what = "Busy ";
        if(getBusy())
            info[2].how = 1;
        else
            info[2].how = 0;
        info[3].set("Rate ",getRate());
        info[4].set("Amount rooms ", getNum_rooms());
        return info;
    }


}