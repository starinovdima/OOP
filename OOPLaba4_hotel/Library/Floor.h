#ifndef LABA4_HOTEL_FLOOR_H
#define LABA4_HOTEL_FLOOR_H
#include "Room.h"


namespace Laba4{


    class Floor {

    private:

        int num_floor;
        int f_size;
        Vector<Hotel_room*> rooms;
        void sorted();

    public:
        Floor() : f_size(0), num_floor(0){}
        Floor(int n_floor) : f_size(0), num_floor(n_floor){}

        ~Floor() {}

        int getSize() const {return f_size;}
        void setSize(int m_size) { f_size = m_size;}
        int getNUMFloor() const {return num_floor;}
        void setFloor(int m_floor){ num_floor = m_floor;}
        Vector<Hotel_room *> getRoom(){return rooms;}

        void add_room(Hotel_room *m_room);
        void delete_room(int num_room);
        int find_room(int num);
        Hotel_room *find_room(Hotel_room *m_room);

        friend std::ostream &operator<<(std::ostream &s,Floor &floor) {
            for(auto i : floor.rooms){
                s <<  i->getNum();
                s << i->getType();
                s << i->getBusy();
                s << i->getRate();
            }
            return s;
        }


    };



}

#endif //LABA4_HOTEL_FLOOR_H
