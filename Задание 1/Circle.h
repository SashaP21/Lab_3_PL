#ifndef OOP_3_CIRCLE_H
#define OOP_3_CIRCLE_H

#include "Figures.h"

class Circle : public Figure {
    double *radius;

public:
    Circle(double radius);

    ~Circle() override;

    double calc_area() override;

    std::string to_string() override;
};

#endif //OOP_3_CIRCLE_H