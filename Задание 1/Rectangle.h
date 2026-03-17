#ifndef OOP_3_RECTANGLE_H
#define OOP_3_RECTANGLE_H

#include "Figures.h"

class Rectangle : public Figure {
    double *width;
    double *height;

public:
    Rectangle(double width, double height);

    ~Rectangle() override;

    double calc_area() override;

    std::string to_string() override;
};

#endif //OOP_3_RECTANGLE_H