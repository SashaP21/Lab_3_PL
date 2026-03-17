#include <string>
#include <sstream>
#include "Trapezoid.h"

using std::stringstream;
using std::string;

Trapezoid::Trapezoid(double base1, double base2, double height) {
    this->base1 = new double(base1);
    this->base2 = new double(base2);
    this->height = new double(height);
}

Trapezoid::~Trapezoid() {
    delete this->base1;
    delete this->base2;
    delete this->height;
}

double Trapezoid::calc_area() {
    return (*base1 + *base2) / 2.0 * *height;
}

string Trapezoid::to_string() {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"trapezoid\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}
