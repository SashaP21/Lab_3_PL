#include <iostream>
#include "Figures.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Triangle.h"

using namespace std;

int main() {
    Figure* c = nullptr;

    int number;
    cin >> number;

    switch (number) {
        case 1:
            c = new Circle(3);
            break;
        case 2:
            c = new Triangle(3, 4, 5);
            break;
        case 3:
            c = new Trapezoid(5, 7, 4);
            break;
        default:
            c = new Rectangle(3, 4);
            break;
    }

    cout << c->to_string() << endl;
    cout << calc_cylinder_volume(c, 5) << endl;

    delete c;

    return 0;
}