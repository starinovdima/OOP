#include "gtest/gtest.h"
#include "library.h"
#include <iostream>



using namespace Laba3;

TEST(Signal_init,Constructor1){
    Binary_signal signal;
    for(int i = 0; i < signal.get_SZ_now(); i++){
        EXPECT_EQ('\0',signal.getValue(i));
        EXPECT_EQ(0,signal.getSeconds(i));
    }
}

TEST(Signal_init,Constructor2){
    const double duration = 4356;
    Binary_signal signal(duration);
    EXPECT_EQ(4356,signal.getDuration());
    for(int i = 0; i < signal.get_SZ_now(); i++){
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
    std::string string = {'0','1','1','0','1'};
    const double time = 50, duration = 1000;
    const int sum = 5;
    Binary_signal signal(string,time,duration);
    EXPECT_EQ(1000,signal.getDuration());
    for(int i = 0; i < sum; i++){
        EXPECT_EQ(string[i],signal.getValue(i));
        EXPECT_EQ(time/sum,signal.getSeconds(i));
    }
}

TEST(Signal_init,Cosntructor6){

    std::string string = {'0','1','1','0','1'};
    const double time = 500, duration = 100;
    EXPECT_ANY_THROW(Binary_signal signal(string,time,duration));

}

TEST(Signal_init, copy){
    std::string string = {'1','0'};
    Binary_signal signal(string,500,1000);
    Binary_signal m_signal(signal);
    EXPECT_EQ(signal.getValue(0),'1');
    EXPECT_EQ(m_signal.getValue(0),'1');
}

TEST(Signal_init, move){

    std::string string = {'1','0'};
    Binary_signal signal(string,500,1000);
    Binary_signal m_signal(std::move(signal));
    EXPECT_EQ(m_signal.getValue(0),'1');

}

TEST(Signal_op, operator_ravno_copy){

    std::string string = {'1','0'};
    Binary_signal signal(string,500,1000);
    Binary_signal m_signal ;
    m_signal = signal;
    EXPECT_EQ(signal.getValue(0),'1');
    EXPECT_EQ(m_signal.getValue(0),'1');

}

TEST(Signal_op, operator_ravno_move){
    std::string string = {'1','0'};
    Binary_signal signal(string,500,1000);
    Binary_signal m_signal;
    m_signal = std::move(signal);
    EXPECT_EQ(m_signal.getValue(0),'1');

}

TEST(Signal_methods_op,operator_tilda){

    std::string string = {'1','0'};
    Binary_signal signal(string,500,1000);
    signal = ~signal;
    EXPECT_EQ(signal.getValue(0),'0');
    EXPECT_EQ(signal.getValue(1),'1');

}

TEST(Signal_methods_op,opertator_plus){

    std::string string1 = {'0','1'};
    std::string string2 = {'1','0'};
    Binary_signal signal1(string1,200,10000);
    Binary_signal signal2(string2,300,1000);
    signal1 += signal2;
    EXPECT_EQ(signal1.getValue(2),'1');
    EXPECT_EQ(signal1.getValue(3),'0');

}

TEST(Signal_methods_op,opertator_plus2){

    std::string string1 = {'0','1'};
    std::string string2 = {'1','0'};
    Binary_signal signal1(string1,200,1000);
    Binary_signal signal2(string2,900,1000);
    EXPECT_ANY_THROW(signal1 += signal2);

}

TEST(Signal_methods_op,operator_mult){

    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,10000);
    signal *= 3;
    for(int i = 0; i < 15; i++){
        EXPECT_EQ(signal.getValue(i),'1');
    }

}

TEST(Signal_methods_op,operator_mult2){

    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,1000);

    EXPECT_ANY_THROW(signal *= 3);


}

TEST(Signal_methods_op,opertator_plus_sost1){
    std::string string = {'1','1','1','1','0'};
    Binary_signal signal2(string,400,1000);
    Signal_status status{'1',35};
    signal2 += status;
    EXPECT_EQ(signal2.getValue(5),'1');
    EXPECT_EQ(signal2.getSeconds(5),35);

}

TEST(Signal_methods_op,opertator_plus_sost2){
    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,10000);
    Signal_status status{'0',40};
    signal = signal + status;
    EXPECT_EQ(signal.getValue(5),'0');
    EXPECT_EQ(signal.getSeconds(5),40);

}

TEST(Signal_methods_op,opertator_plus_sost3){
    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,1000);
    Signal_status status{'0',600};
    EXPECT_ANY_THROW( signal + status );


}

TEST(Signal_methods_op,opertator_plus_sost4){
    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,10000);
    Signal_status status{'4',40};
    EXPECT_ANY_THROW(signal + status);

}

TEST(Signal_methods_op,operator_minus_minus1){
    std::string string = {'1','1','1','1','1'};
    Binary_signal sig(string,500,10000);
    -- sig;
    for(int i = 0; i < 5; i++){
        EXPECT_EQ(sig.getValue(i),'0');
        EXPECT_EQ(sig.getSeconds(i),0);

    }

}

TEST(Signal_methods_op,operator_minus_minus2){
    std::string string = {'1','1','1','1','1'};
    Binary_signal sig(string,500,10000);
    sig --;
    for(int i = 0; i < 5; i++){
        EXPECT_EQ(sig.getValue(i),'0');
        EXPECT_EQ(sig.getSeconds(i),0);

    }

}

TEST(Signal_methods, insert_in_time1){

    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,10000);
    signal.insert_to_time(300,'0',123);

    EXPECT_EQ(signal.getValue(1),'0');
    EXPECT_EQ(signal.getSeconds(1),300);

}
TEST(Signal_methods, insert_in_time2){

    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,10000);

    EXPECT_ANY_THROW( signal.insert_to_time(300,'8',123) );


}

TEST(Signal_methods, insert_in_time3){

    std::string string = {'1','1','1','1','1'};
    Binary_signal signal(string,500,1000);

    EXPECT_ANY_THROW( signal.insert_to_time(3000,'0',123) );


}

TEST(Signal_methods, delete_in_time1){

    std::string string = {'1','1','0','1','1','1','1','0','1','1'};
    Binary_signal signal(string,1000,10000);
    signal.delete_to_time(123,-1);
    EXPECT_EQ(signal.get_SZ_now(),9);
    EXPECT_EQ(signal.getValue(1),'0');
}

TEST(Signal_methods, delete_in_time2){

    std::string string = {'1','1','0','1','1'};
    Binary_signal signal(string,500,1000);
    signal.delete_to_time(123,50);
    EXPECT_EQ(signal.get_SZ_now(),5);
    EXPECT_EQ(signal.getValue(1),'1');
    EXPECT_EQ(signal.getSeconds(1),50);

}

TEST(Signal_methods, delete_in_time3){

    std::string string = {'1','1','0','1','1'};
    Binary_signal signal(string,500,1000);
    EXPECT_ANY_THROW( signal.delete_to_time(600,50) );

}

TEST(Signal_methods, delete_in_time4){

    std::string string = {'1','1','0','1','1'};
    Binary_signal signal(string,500,1000);
    EXPECT_ANY_THROW( signal.delete_to_time(123,120) );

}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}