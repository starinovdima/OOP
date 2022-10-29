#include "Table.h"
#include "Descriptors.h"


Laba4::Floor *Laba4::Table::find_floor(Laba4::Hotel_room *room) {
    for(int i = 0;i < t_size; i++){
        if(floors[i]->find_room(room) != nullptr)
            return floors[i];
    }
    return nullptr;
}

bool Laba4::Table::check_floor(int num_floor) {
    for(int i = 0; i < t_size; i ++){
        if(floors[i]->getNUMFloor() == num_floor)
            return true;
    }
    return false;
}

Laba4::Table::Table(int num_floors) {
    floors.up_vector(num_floors);
    t_size = num_floors;
    for(int i = 1; i < t_size+1; i++){
        floors[i]->setFloor(i);
    }
}

void Laba4::Table::add_floor(Floor *floor) {
    floors.push_back(floor);
    floors[t_size]->setFloor(t_size+1);
    t_size += 1;
}

void Laba4::Table::add_room(Laba4::Hotel_room *m_room, int n_floor) {
    if(n_floor < 1 || n_floor > t_size)
        throw std::invalid_argument("This floor didn't find");
    floors[n_floor-1]->add_room(m_room);
}

void Laba4::Table::delete_room(int num_room) {
    int i = num_room / 100;
    floors[i]->delete_room(i);
}

int Laba4::Table::find_floor(int num) {
    for(int i = 0;i < t_size;i++){
        if(floors[i]->find_room(num) != -1)
            return i;
    }
    return -1;
}

void Laba4::Table::generate_random() {
    int num_floors = Instruments::GetRandomNumber(2,8);
    floors.up_vector(num_floors);

    for(int i = 0; i < num_floors; i++){
        Floor floor1(i+1);
        add_floor(&floor1);
    }

    for(int i = 0; i < t_size; i++){
        int num_room = 0;
        int k = Instruments::GetRandomNumber(2,5);
        int j = Instruments::GetRandomNumber(10,25);
        int f = Instruments::GetRandomNumber(10,25);
        for(int p = 0; p < k; p++){
            Lux *room = new Lux;
            num_room += 1;
            room->start_room(num_room, Instruments::GetRandomNumber(800,1500));
            floors[i]->add_room(room);
        }
        for(int z = 0; z < j; z++){
            Single_room *room = new Single_room;
            num_room += 1;
            room->start_room(num_room, Instruments::GetRandomNumber(100,300));
            floors[i]->add_room(room);
        }
        for(int m = 0; m < f; m++){
            Multi_room *room = new Multi_room;
            num_room += 1;
            room->start_room(num_room, Instruments::GetRandomNumber(300,800));
            floors[i]->add_room(room);
        }
    }

}
