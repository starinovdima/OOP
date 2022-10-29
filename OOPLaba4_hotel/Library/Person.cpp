#include "Descriptors.h"

namespace Laba4 {

    bool operator==(Person &per1, Person &per2) {
        return (per1.day == per2.day && per1.month == per2.month && per1.year == per2.year && per1.time == per2.time);
    }

    bool operator!=(Person &per1, Person &per2) {
        return !(per1 == per2);
    }

    Person &Person::operator=(const Person &person) {
        if(this != &person){
            day = person.day;
            month = person.month;
            year = person.year;
            time = person.time;
        }
        return *this;
    }

    Person &Person::operator=(Person &&person) {
        if(this != &person){
            std::swap(day,person.day);
            std::swap(month,person.month);
            std::swap(year,person.year);
            std::swap(time,person.time);
        }
        return *this;
    }


}
