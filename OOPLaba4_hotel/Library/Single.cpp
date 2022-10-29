#include "Descriptors.h"

namespace Laba4 {
    using std::cout, std::endl;


    void Single_room::registration(Vector<Person> m_person) {
        if (m_person.empty() || m_person.size() > 1)
            throw std::invalid_argument("Invalid number of guests for this rooms");

        setBusy(true);
        person.setData(m_person[0].getDay(), m_person[0].getMonth(), m_person[0].getYear());
        person.setTime(m_person[0].getTime());
    }


    void Single_room::eviction() {
        Hotel_room::eviction();
        person.setData(0, 0, 0);
        person.setTime(0);
    }

    void Single_room::start_room(int num_room, int rate) {

        setType(3);
        setBusy(false);
        setNumber(num_room);
        setRate(rate);

    }

    Single_room &Single_room::operator=(const Single_room &s) {
        if(this != &s){
            person = s.person;
            setBusy(s.getBusy());
            setRate(s.getRate());
            setNumber(s.getNum());
            setType(s.getType());
        }
        return *this;
    }

    bool operator==(Single_room &per1, Single_room &per2) {
        return (per1.person == per2.person);
    }

    bool operator!=(Single_room &per1, Single_room &per2) {
        return !(per1 == per2);
    }

    Vector<Info> Single_room::show_info() {
        Vector<Info> info(4);
        info[0].set("Number rooms is ",getNum());
        info[1].set("type ",getType());
        info[2].what = "Busy ";
        if(getBusy())
            info[2].how = 1;
        else
            info[2].how = 0;
        info[3].set("Rate ",getRate());
        return info;
    }

}