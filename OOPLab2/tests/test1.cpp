#include "gtest/gtest.h"
#include "../lab/laba2.h"
using namespace Lab2;

/* Секция Arrange - настройка теста(обьявление переменных)
 * Секция Act - выполнение действия(метода)
 * Секция Assert - проверка выполнения
 * ASSERT_* - прерывает если не удалось
 * EXPECT_* - продолжает если не удалось
 */

TEST(Circle_init,Constructor){
    Archimedes Circle;
    EXPECT_EQ(1,Circle.getA());

}

TEST(Circle_setter,setA){  // Название набора теста , название кейса
    Archimedes Circle;
    const double example1 = 2.4356;
    const double example2 = -9.432;
    Circle.setA(example1);
    EXPECT_EQ(example1,Circle.getA());
    Circle.setA(example2);
    EXPECT_EQ(example2,Circle.getA());
}

TEST(Circle_method,Distance){
    Archimedes Circle;
    Circle.setA(3);
    EXPECT_EQ(3,Circle.getA());
    double rad = 3.14;
    EXPECT_EQ(3*3.14,Circle.distance(rad));
}

TEST(Circle_method,Sector_area){
    Archimedes Circle;
    double error = 0.00001, r1 = 3.452, r2 = 1.765;
    Circle.setA(0);
    EXPECT_EQ(0,Circle.sector_area(r1,r2));
    Circle.setA(-2);
    EXPECT_NEAR(2.96972,Circle.sector_area(r1,r2),error);
}

TEST(Circle_method, Figure_area){
    Archimedes Circle;
    int n = 3;
    double error = 0.01;
    Circle.setA(4);
    EXPECT_NEAR(12567.87,Circle.figure_area(n),error);
}

TEST(Circle_method,Ring_area){
    Archimedes Circle;
    double error = 0.01;
    int n = 3;
    Circle.setA(-3);
    EXPECT_NEAR(10046.03,Circle.ring_area(n),error);
}

TEST(Circle_method,Arc_length){
    Archimedes Circle;
    double error = 0.0001,rad = 1.5;
    Circle.setA(2);
    EXPECT_NEAR(2.2924,Circle.arc_length(rad),error);
    Circle.setA(-3);
    EXPECT_NEAR(3.4387,Circle.arc_length(rad),error);
};

TEST(Circle_method,radius_of_curvature){
    Archimedes Circle;
    double error = 0.00001,rad = 3.14;
    Circle.setA(5);
    EXPECT_NEAR(2.06748,Circle.radius_of_curvature(rad),error);
}



int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}