#ifndef OOP_3_TRIANGLE_H
#define OOP_3_TRIANGLE_H

#include "Figures.h"

class Triangle: public Figure {
    double *a;
    double *b;
    double *c;

public:
    Triangle(double a, double b, double c);

    ~Triangle() override;

    double calc_area() override;

    std::string to_string() override;
};

#endif //OOP_3_TRIANGLE_H