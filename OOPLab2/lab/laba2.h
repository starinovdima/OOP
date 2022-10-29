#ifndef LABA2_LABA2_H
#define LABA2_LABA2_H

namespace Lab2{

    class Archimedes{
    private:

        double step;  //Шаг спирали

    public:

        explicit Archimedes(double st = 1) : step {st}{}     // Конструктор
        ~Archimedes() = default;                        // Деструктор

        double getA() const {return step;}      // Геттер
        void setA(const double m_step) {step = m_step;}  // Сеттер

        double distance(const double rad) const;              // Методы
        double sector_area(const double r1, double r2) const;
        double figure_area(const int n) const;
        double ring_area(const int n) const;
        double arc_length(const double rad) const;
        double radius_of_curvature(const double rad) const;
    };

}




#endif //LABA2_LABA2_H
