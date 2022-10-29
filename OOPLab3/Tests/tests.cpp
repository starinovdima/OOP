#include "gtest/gtest.h"
#include "library.h"
#include <iostream>

/* Секция Arrange - настройка теста(обьявление переменных)
 * Секция Act - выполнение действия(метода)
 * Секция Assert - проверка выполнения
 * ASSERT_* - прерывает если не удалось
 * EXPECT_* - продолжает если не удалось
 */

using namespace Laba3;

TEST(Siganl_init,Constructor1){
    Binary_signal signal;
    for(int i = 0; i < Binary_signal::get_SZ(); i++){
        EXPECT_EQ('\0',signal.getValue(i));
        EXPECT_EQ(0,signal.getseconds(i));
    }
}

TEST(Signal_init,Constructor2){
    const double duration = 4356;
    Binary_signal signal(duration);
    EXPECT_EQ(4356,signal.getDuration());
    for(int i = 0; i < Binary_signal::get_SZ(); i++){
        EXPECT_EQ('\0',signal.getValue(i));
        EXPECT_EQ(0,signal.getseconds(i));
    }
}

TEST(Signal_init,Constructor3){
    const unsigned char symbol = '1';
    const double duration = 4000;
    Binary_signal signal(symbol,duration);
    EXPECT_EQ(4000,signal.getDuration());
    EXPECT_EQ('1',signal.getValue(0));
    EXPECT_EQ(4000,signal.getseconds(0));

}

TEST(Signal_init,Constructor4){
    const unsigned char symbol = '0';
    const double duration = 120;
    Binary_signal signal(symbol,duration);
    EXPECT_EQ(120,signal.getDuration());
    EXPECT_EQ('0',signal.getValue(0));
    EXPECT_EQ(120,signal.getseconds(0));

}

TEST(Signal_init,Constructor5){
    unsigned char string[5]{'0','1','1','0','1'};
    const double time = 50, duration = 1000;
    const int sum = 5;
    Binary_signal signal(string,time,sum,duration);
    EXPECT_EQ(1000,signal.getDuration());
    for(int i = 0; i < sum; i++){
        EXPECT_EQ(string[i],signal.getValue(i));
        EXPECT_EQ(time/sum,signal.getseconds(i));
    }
}

TEST(Signal_init,Cosntructor6){
    unsigned char string[5]{'0','1','1','0','1'};
    const double time = 500, duration = 100;
    const int sum = 5;
    EXPECT_THROW(Binary_signal signal(string,time,sum,duration),std::invalid_argument);
}







int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}