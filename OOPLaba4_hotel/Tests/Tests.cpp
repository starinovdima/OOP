#include "gtest/gtest.h"
#include "../Library/Descriptors.h"
#include "../Library/Floor.h"
#include "Table.h"
#include <iostream>

using namespace Laba4;

TEST(Person,Construcor1){
    Person person;
    EXPECT_EQ(person.getDay(),0);
    EXPECT_EQ(person.getMonth(),0);
    EXPECT_EQ(person.getYear(),0);
    EXPECT_EQ(person.getTime(),0);
}
TEST(Person,Constructor2){
    Person person(1,2,3,4);
    EXPECT_EQ(person.getDay(),1);
    EXPECT_EQ(person.getMonth(),2);
    EXPECT_EQ(person.getYear(),3);
    EXPECT_EQ(person.getTime(),4);
}
TEST(Person,Seters){
    Person person;
    person.setData(3,2,1);
    person.setTime(5);
    EXPECT_EQ(person.getDay(),3);
    EXPECT_EQ(person.getMonth(),2);
    EXPECT_EQ(person.getYear(),1);
    EXPECT_EQ(person.getTime(),5);
}
TEST(Person,operator1){
    Person person1(1,2,3,4);
    Person person2;
    person1 = person2;
    EXPECT_EQ(person1.getDay(),0);
    EXPECT_EQ(person1.getMonth(),0);
    EXPECT_EQ(person1.getYear(),0);
    EXPECT_EQ(person1.getTime(),0);
}
TEST(Person,operator2){
    Person person1(1,2,3,4);
    Person person2;
    person1 = (std::move(person2));
    EXPECT_EQ(person1.getDay(),0);
    EXPECT_EQ(person1.getMonth(),0);
    EXPECT_EQ(person1.getYear(),0);
    EXPECT_EQ(person1.getTime(),0);
}
TEST(Person,operator3){
    Person person1(1,2,3,4);
    Person person2(1,2,3,4);
    EXPECT_TRUE(person1 == person2);
}

TEST(Person,operator4){
    Person person1(1,2,3,4);
    Person person2(3,2,1,0);
    EXPECT_TRUE(person1 != person2);
}

TEST(Lux,Constructor1){
    Lux lux;
    EXPECT_EQ(lux.getNum_rooms(),0);
    EXPECT_EQ(lux.getNum_persons(),0);
    EXPECT_EQ(lux.getType(),1);

}

TEST(Lux,Constructor2){
    Lux lux(3);
    EXPECT_EQ(lux.getNum_rooms(),3);
    EXPECT_EQ(lux.getNum_persons(),0);
    EXPECT_EQ(lux.getType(),1);

}
TEST(Lux,Setters){
    Lux lux;
    lux.setNum_rooms(3);
    lux.setNum_persons(2);
    EXPECT_EQ(lux.getNum_rooms(),3);
    EXPECT_EQ(lux.getNum_persons(),2);
}

TEST(Lux,Start_room){
    Lux lux;
    lux.start_room(101,555);
    EXPECT_EQ(1,lux.getType());
    EXPECT_FALSE(lux.getBusy());
    EXPECT_EQ(101,lux.getNum());
    EXPECT_EQ(555,lux.getRate());
}

TEST(Lux,Registration){
    Lux lux;
    lux.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    lux.registration(m_person);
    Person &proverka = lux.getGuests(0);
    EXPECT_EQ(1,proverka.getDay());
    EXPECT_EQ(12,proverka.getMonth());
    EXPECT_EQ(2021,proverka.getYear());
    EXPECT_EQ(5,proverka.getTime());
}

TEST(Lux,Eviction){
    Lux lux;
    lux.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    lux.registration(m_person);
    lux.eviction();
    Vector<Person> prov = lux.getPerson();
    EXPECT_EQ(0,prov.size());
}

TEST(Lux,operator1){
    Lux lux;
    lux.start_room(101,32);
    Lux new_lux ;
    new_lux = lux;
    EXPECT_EQ(101,new_lux.getNum());
    EXPECT_EQ(32,new_lux.getRate());
    EXPECT_EQ(false,new_lux.getBusy());
    EXPECT_EQ(lux.getPerson(),new_lux.getPerson());
}

TEST(Lux,operator2){
    Lux lux;
    lux.start_room(101,32);
    Lux new_lux ;
    new_lux = std::move(lux);
    EXPECT_EQ(101,new_lux.getNum());
    EXPECT_EQ(32,new_lux.getRate());
    EXPECT_EQ(false,new_lux.getBusy());

}

TEST(Multi_room,Constructor1){
    Multi_room multi_room;
    EXPECT_EQ(multi_room.getNum_seats(),0);
    EXPECT_EQ(multi_room.getNum_persons(),0);
    EXPECT_EQ(multi_room.getType(),2);

}


TEST(Multi_room,Setters){
    Multi_room multi_room;
    multi_room.setNum_seats(3);
    multi_room.setNum_persons(2);
    EXPECT_EQ(multi_room.getNum_seats(),3);
    EXPECT_EQ(multi_room.getNum_persons(),2);
}

TEST(Multi_room,Start_room){
    Multi_room multi_room;
    multi_room.start_room(101,555);
    EXPECT_EQ(2,multi_room.getType());
    EXPECT_FALSE(multi_room.getBusy());
    EXPECT_EQ(101,multi_room.getNum());
    EXPECT_EQ(555,multi_room.getRate());
}

TEST(Multi_room,Registration){
    Multi_room multi_room;
    multi_room.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    multi_room.registration(m_person);
    Person &proverka = multi_room.getGuests(0);
    EXPECT_EQ(1,proverka.getDay());
    EXPECT_EQ(12,proverka.getMonth());
    EXPECT_EQ(2021,proverka.getYear());
    EXPECT_EQ(5,proverka.getTime());
}

TEST(Multi_room,Eviction){
    Multi_room multi_room;
    multi_room.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    multi_room.registration(m_person);
    multi_room.eviction();
    Vector<Person> prov = multi_room.getPerson();
    EXPECT_EQ(0,prov.size());
}

TEST(Multi_room,operator1){
    Multi_room multi_room;
    multi_room.start_room(101,32);
    Multi_room new_multi_room ;
    new_multi_room = multi_room;
    EXPECT_EQ(101,new_multi_room.getNum());
    EXPECT_EQ(32,new_multi_room.getRate());
    EXPECT_EQ(false,new_multi_room.getBusy());
    EXPECT_EQ(multi_room.getPerson(),new_multi_room.getPerson());
}

TEST(Multi_room,operator2){
    Multi_room multi_room;
    multi_room.start_room(101,32);
    Multi_room new_multi_room ;
    new_multi_room = std::move(multi_room);
    EXPECT_EQ(101,new_multi_room.getNum());
    EXPECT_EQ(32,new_multi_room.getRate());
    EXPECT_EQ(false,new_multi_room.getBusy());

}
TEST(Single_room,Constructor1){
    Single_room singleRoom;
    EXPECT_EQ(singleRoom.getType(),3);

}

TEST(Single_room,Start_room){
    Single_room singleRoom;
    singleRoom.start_room(101,555);
    EXPECT_EQ(3,singleRoom.getType());
    EXPECT_FALSE(singleRoom.getBusy());
    EXPECT_EQ(101,singleRoom.getNum());
    EXPECT_EQ(555,singleRoom.getRate());

}

TEST(Single_room,Registration){
    Single_room singleRoom;
    singleRoom.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    singleRoom.registration(m_person);
    Person &proverka = singleRoom.getGuests();
    EXPECT_EQ(1,proverka.getDay());
    EXPECT_EQ(12,proverka.getMonth());
    EXPECT_EQ(2021,proverka.getYear());
    EXPECT_EQ(5,proverka.getTime());
}

TEST(Single_room,Eviction){
    Single_room singleRoom;
    singleRoom.start_room(101,555);
    Person person(1,12,2021,5);
    Vector<Person> m_person;
    m_person.push_back(person);
    singleRoom.registration(m_person);
    singleRoom.eviction();
    EXPECT_FALSE(singleRoom.getBusy());
}

TEST(Single_room,operator1){
    Single_room singleRoom;
    singleRoom.start_room(101,32);
    Single_room new_singleRoom ;
    new_singleRoom = singleRoom;
    EXPECT_EQ(101,new_singleRoom.getNum());
    EXPECT_EQ(32,new_singleRoom.getRate());
    EXPECT_EQ(false,new_singleRoom.getBusy());
}

TEST(Floor, Constructor1){
    Floor floor;
    EXPECT_EQ(floor.getSize(),0);
    EXPECT_EQ(floor.getNUMFloor(),0);
}

TEST(Floor, Constructor2){
    Floor floor(3);
    EXPECT_EQ(floor.getSize(),0);
    EXPECT_EQ(floor.getNUMFloor(),3);
}

TEST(Floor,Add_room){
    Floor floor(1);
    Lux lux;
    lux.start_room(101,432);
    floor.add_room(&lux);
    Vector<Hotel_room *> rooms = floor.getRoom();
    EXPECT_EQ(&lux,rooms[0]);
    EXPECT_EQ(101,rooms[0]->getNum());
    EXPECT_EQ(432,rooms[0]->getRate());
}

TEST(Floor,delete_room){
    Floor floor(1);
    Lux lux;
    lux.start_room(101,432);
    floor.add_room(&lux);
    Vector<Hotel_room *> rooms = floor.getRoom();
    EXPECT_EQ(&lux,rooms[0]);
    EXPECT_EQ(101,rooms[0]->getNum());
    EXPECT_EQ(432,rooms[0]->getRate());
    floor.delete_room(101);
    Vector<Hotel_room *> room1 = floor.getRoom();
    EXPECT_EQ(room1.size(),0);
}

TEST(Vector,Constructor1){
    Vector<int> vector;
    int a = 3;
    vector.push_back(a);
    EXPECT_EQ(1,vector.getLength());
    EXPECT_EQ(10,vector.getSizeVector());
}
TEST(Vector,Constructor2){
    Vector<int> vector(20);
    EXPECT_EQ(0,vector.getLength());
    EXPECT_EQ(20,vector.getSizeVector());
}
TEST(Vector,CopyConstructor){
    Vector<int> vector(30);
    Vector<int> vector1(vector);
    EXPECT_EQ(0,vector1.getLength());
    EXPECT_EQ(30,vector1.getSizeVector());
}
TEST(Vector,Swap){
    Vector<int> vector1;
    int a = 3;
    vector1.push_back(a);
    Vector<int> vector2;
    int b = 5;
    vector2.push_back(b);
    vector1.swap(vector2);
    EXPECT_EQ(vector2[0],a);
    EXPECT_EQ(vector1[0],b);
}

TEST(Vector,Clear){
    Vector<int> vector;
    int a = 3;
    vector.push_back(a);
    vector.clear();
    EXPECT_EQ(0,vector.getLength());
    EXPECT_EQ(0,vector.getSizeVector());
}

TEST(Vector,Empty){
    Vector<int> vector;
    EXPECT_TRUE(vector.empty());
}

TEST(Vector,Push_back){
    Vector<int> vector;
    int a=1,b=2,c=3;
    vector.push_back(a);
    vector.push_back(b);
    vector.push_back(c);
    EXPECT_EQ(1,vector[0]);
    EXPECT_EQ(2,vector[1]);
    EXPECT_EQ(3,vector[2]);
}

TEST(Vector,Erase){
    Vector<int> vector;
    int a=1,b=2,c=3;
    vector.push_back(a);
    vector.push_back(b);
    vector.push_back(c);
    vector.erase(b);
    EXPECT_EQ(1,vector[0]);
    EXPECT_EQ(3,vector[1]);

}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}