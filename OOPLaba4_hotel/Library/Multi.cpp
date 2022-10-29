#include "Descriptors.h"

namespace Laba4 {
    using std::cout, std::endl;


    void Multi_room::registration(Vector<Person> m_person) {

        if (m_person.empty() || m_person.size() > 4)
            throw std::invalid_argument("Invalid number of guests for this rooms");

        setBusy(true);
        nums_persons = m_person.size();
        for (int i = 0; i < m_person.size(); i++) {
            person[i].setData(m_person[i].getDay(), m_person[i].getMonth(), m_person[i].getYear());
            person[i].setTime(m_person[i].getTime());
        }
    }

    void Multi_room::eviction() {
        Hotel_room::eviction();
        person.clear();
        nums_persons = 0;
    }


    void Multi_room::add_to_multi(Vector<Person> m_person) {
        if (m_person.empty())
            throw std::invalid_argument("Error in the number of guests entered");
        if (num_seats < m_person.size() + nums_persons)
            throw std::invalid_argument("There is no place");

        for (int i = 0; i < m_person.size(); i++) {
            person.push_back(m_person[i]);
        }
    }

    void Multi_room::delete_from_multi(Vector<Person> m_person) {
        if (m_person.empty() || m_person.size() > nums_persons)
            throw std::invalid_argument("Error in the number of guests entered");

        int count = 0;
        for (int i = 0; i < m_person.size(); i++) {
            for (int k = 0; k < person.size(); k++) {
                if (m_person[i] == person[k]) {
                    person.erase(person[k]);
                    nums_persons -= 1;
                    count++;
                }
            }
        }
        if (count == 0)
            throw std::invalid_argument("Didn't find guests which you enter");
        if (count != m_person.size())
            throw std::invalid_argument("We could not delete all the guests you entered, as some of them do not exist");
    }

    void Multi_room::start_room(int num_room, int rate) {

        setType(2);
        setBusy(false);
        setNumber(num_room);
        num_seats = 4;
        setRate(rate);

    }

    Multi_room &Multi_room::operator=(const Multi_room &s) {
        if (this != &s) {
            nums_persons = s.nums_persons;
            num_seats = s.num_seats;
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

    Multi_room &Multi_room::operator=(Multi_room &&s) {
        if (this != &s) {
            std::swap(nums_persons, s.nums_persons);
            std::swap(num_seats,s.num_seats);
            setBusy(s.getBusy());
            setRate(s.getRate());
            setNumber(s.getNum());
            setType(s.getType());
            person.swap(s.person);
        }
        return *this;
    }

    bool operator==(Multi_room &per1, Multi_room &per2) {
        return (per1.nums_persons == per2.nums_persons && per1.num_seats == per2.num_seats && per1.person == per2.person);
    }

    bool operator!=(Multi_room &per1, Multi_room &per2) {
        return !(per1 == per2);
    }

    Vector<Info> Multi_room::show_info() {
        Vector<Info> info(5);
        info[0].set("Number rooms is ",getNum());
        info[1].set("type ",getType());
        info[2].what = "Busy ";
        if(getBusy())
            info[2].how = 1;
        else
            info[2].how = 0;
        info[3].set("Rate ",getRate());
        info[4].set("Amount seats ", getNum_seats());
        return info;
    }

}