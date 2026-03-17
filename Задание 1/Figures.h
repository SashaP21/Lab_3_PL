#ifndef OOP_3_FIGURES_H
#define OOP_3_FIGURES_H

#include <string>

class Figure {
public:
    virtual ~Figure() = default;

    virtual double calc_area() = 0;

    virtual std::string to_string();
};

double calc_cylinder_volume(Figure *base, double height);


#endif //OOP_3_FIGURES_H
