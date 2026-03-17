#include <iostream>
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"

using std::cout;
using std::cin;

int main() {
    // Раннее связывание
    Fish fish;
    cout << "Fish object:\n";
    fish.breathe();
    fish.eat();
    fish.swim();

    cout << "Bird object:\n";
    Bird bird;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    cout << "FlyingBird object:\n";
    FlyingBird flyingBird;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();

    // Позднее связывание
    Animal* a = nullptr;

    int number;
    cin >> number;

    switch (number) {
        case 1:
            a = new Fish();
            cout << "Fish object:\n";
            a->breathe();
            a->eat();
            break;
        case 2:
            a = new Bird();
            cout << "Bird object:\n";
            a->breathe();
            a->eat();
            break;
        default:
            a = new FlyingBird;
            cout << "FlyingBird object:\n";
            a->breathe();
            a->eat();
            break;
    }
    delete a;
}