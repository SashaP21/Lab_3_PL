#include <sstream>
#include <string>
#include "Rectangle.h"

using std::stringstream;
using std::string;

Rectangle::Rectangle(double width, double height) {
    this->width = new double(width);
    this->height = new double(height);
}

Rectangle::~Rectangle() {
    delete this->width;
    delete this->height;
};

double Rectangle::calc_area() {
    return *width * *height;
};

string Rectangle::to_string() {
    stringstream ss;

    ss << "{"
            << "\n\t"
            << "\"figure_type\": \"rectangle\","
            << "\n\t"
            << "\"area\": " << this->calc_area()
            << "\n"
            << "}";

    return ss.str();
}
