#include "Floor.h"

void Laba4::Floor::sorted() {
    int i=1, j=2;
    while (i < rooms.size())
    {
        if (rooms[i - 1]->getNum() < rooms[i]->getNum()) {
            i=j;
            j++;
        }
        else
        {
            int temp = rooms[i]->getNum();
            rooms[i]->setNumber(rooms[i - 1]->getNum());
            rooms[i - 1]->setNumber(temp);
            i--;
            if (i==0) {
                i=j;
                j++;
            }
        }
    }
}

void Laba4::Floor::delete_room(int num_room) {
    int i = find_room(num_room);
    if(i == -1)
        throw std::invalid_argument("No such room was found");
    rooms.erase(rooms[i]);
    f_size --;
}

void Laba4::Floor::add_room(Laba4::Hotel_room *m_room) {
    if(find_room(m_room->getNum()) != -1)
        throw std::invalid_argument("Room with this number has already exists");
    if(m_room->getNum() < 100 || m_room->getNum()/100 != num_floor)
        m_room->setNumber(num_floor*100 + m_room->getNum());
    rooms.push_back(m_room);
    sorted();
    f_size ++;
}


Laba4::Hotel_room *Laba4::Floor::find_room(Laba4::Hotel_room *m_room) {
    for(int i = 0;i < f_size; i++){
        if(rooms[i] == m_room)
            return rooms[i];
    }
    return nullptr;
}

int Laba4::Floor::find_room(int num) {
    for(int i = 0; i < f_size; i++){
        if(rooms[i]->getNum() == num)
            return i;
    }
    return -1;
}

