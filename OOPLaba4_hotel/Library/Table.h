#ifndef LABA4_HOTEL_TABLE_H
#define LABA4_HOTEL_TABLE_H
#include "Floor.h"

namespace Laba4{


    class Table{
    private:
        Vector<Floor*> floors;
        int t_size;
    public:
        Table() : t_size(0){}
        Table(int num_floors);
        ~Table(){}

        int getSize() const {return t_size;}
        void setSize(int m_size) { t_size = m_size;}

        void add_room(Hotel_room *m_room, int n_floor);
        void delete_room(int num_room);
        void add_floor(Floor *floor);
        void generate_random();

        int find_floor(int num);
        Floor *find_floor(Hotel_room *room);
        bool check_floor(int num_floor);

        friend std::ostream &operator<<(std::ostream &s,Table &table) {
            for(int i = 0; i < table.t_size; i ++){
                s  << i+1 << "\n";
                s << *table.floors[i] << "\n";
            }
            return s;
        }

    };


}

#endif //LABA4_HOTEL_TABLE_H
