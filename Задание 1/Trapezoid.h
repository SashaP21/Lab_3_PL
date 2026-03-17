#ifndef OOP_3_TRAPEZOID_H
#define OOP_3_TRAPEZOID_H

#include "Figures.h"

class Trapezoid : public Figure {
    double *base1;
    double *base2;
    double *height;

public:
    Trapezoid(double base1, double base2, double height);

    ~Trapezoid() override;

    double calc_area() override;

    std::string to_string() override;
};

#endif //OOP_3_TRAPEZOID_H