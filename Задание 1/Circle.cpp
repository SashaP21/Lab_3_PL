#include <sstream>
#include "Circle.h"
#include <cmath>
#include <string>

using std::stringstream;
using std::string;

Circle::Circle(double radius) {
    this->radius = new double(radius);
}

Circle::~Circle() {
    delete this->radius;
}

double Circle::calc_area(){
    const double r = *this->radius;

    return r * r * M_PI;
}

string Circle::to_string()  {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"circle\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}
