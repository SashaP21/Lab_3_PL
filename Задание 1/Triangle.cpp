#include <string>
#include <sstream>
#include <cmath>
#include "Triangle.h"

using std::stringstream;
using std::string;

Triangle::Triangle(double a, double b, double c) {
    this->a = new double(a);
    this->b = new double(b);
    this->c = new double(c);
}

Triangle::~Triangle() {
    delete this->a;
    delete this->b;
    delete this->c;
}

double Triangle::calc_area() {
    double p = (*a + *b + *c) / 2.0;
    return sqrt(p * (p - *a) * (p - *b) * (p - *c));
}

string Triangle::to_string() {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"triangle\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}