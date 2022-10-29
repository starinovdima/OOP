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
        EXPECT_EQ(0,signal.getSeconds(i));
    }
}

TEST(Signal_init,Constructor2){
    const double duration = 4356;
    Binary_signal signal(duration);
    EXPECT_EQ(4356,signal.getDuration());
    for(int i = 0; i < Binary_signal::get_SZ(); i++){
        EXPECT_EQ('\0',signal.getValue(i));
        EXPECT_EQ(0,signal.getSeconds(i));
    }
}

TEST(Signal_init,Constructor3){
    const unsigned char symbol = '1';
    const double duration = 4000;
    Binary_signal signal(symbol,duration);
    EXPECT_EQ(4000,signal.getDuration());
    EXPECT_EQ('1',signal.getValue(0));
    EXPECT_EQ(4000,signal.getSeconds(0));

}

TEST(Signal_init,Constructor4){
    const unsigned char symbol = '0';
    const double duration = 120;
    Binary_signal signal(symbol,duration);
    EXPECT_EQ(120,signal.getDuration());
    EXPECT_EQ('0',signal.getValue(0));
    EXPECT_EQ(120,signal.getSeconds(0));

}

TEST(Signal_init,Constructor5){
    unsigned char string[5]{'0','1','1','0','\0'};
    const double time = 50, duration = 1000;
    const int sum = 5;
    Binary_signal signal(string,time,sum,duration);
    EXPECT_EQ(1000,signal.getDuration());
    for(int i = 0; i < sum - 1; i++){
        EXPECT_EQ(string[i],signal.getValue(i));
        EXPECT_EQ(time/sum,signal.getSeconds(i));
    }
}

TEST(Signal_init,Cosntructor6){
    unsigned char string[5]{'0','1','1','0','1'};
    const double time = 500, duration = 100;
    const int sum = 5;
    EXPECT_ANY_THROW(Binary_signal signal(string,time,sum,duration));
}

TEST(Siganl_methods_op,operator_tilda){

    unsigned char string[2]{'0','1'};
    Binary_signal signal(string,500,2,1000);
    signal = ~signal;
    EXPECT_EQ(signal.getValue(0),'1');
    EXPECT_EQ(signal.getValue(1),'0');

}

TEST(Signal_methods_op,opertator_plus){

    unsigned char string1[2]{'0','1'};
    unsigned char string2[2]{'1','0'};
    Binary_signal signal1(string1,200,2,10000);
    Binary_signal signal2(string2,300,2,1000);
    signal1 = signal1 + signal2;
    EXPECT_EQ(signal1.getValue(2),'1');
    EXPECT_EQ(signal1.getValue(3),'0');

}

TEST(Signal_methods_op,operator_mult){

    unsigned char string[5]{'1','1','1','1','1'};
    Binary_signal signal(string,500,5,10000);
    signal *= 3;
    for(int i = 0; i < 15; i++){
        EXPECT_EQ(signal.getValue(i),'1');
    }

}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}