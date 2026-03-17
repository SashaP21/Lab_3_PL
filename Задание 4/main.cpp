#include <iostream>
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"
#include "windows.h"

using std::cout;
using std::cin;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");
    cout << "Раннее связывание:\n";
    Summator simple;
    SquareSummator square;
    CubeSummator cube;

    for (int i : {2, 3, 5, 8, 10}) {
        cout << i << "\n"
             << "Summator: " << simple.sum(i)
             << " Формула: " << i * (i + 1) / 2 << "\n"
             << "SquareSummator: " << square.sum(i)
             << " Формула: " << i * (i + 1) * (2 * i + 1) / 6
             << "\n" << "CubeSummator: " << cube.sum(i)
             << " Формула: " << (i * (i + 1) / 2) * (i * (i + 1) / 2)
             << "\n";
    }
    cout << "Позднее связывание:\n";
    Summator* s = nullptr;

    int number;
    cin >> number;

    switch (number) {
        case 1:
            s = new Summator;
            cout << "Summator: ";
            break;
        case 2:
            s = new SquareSummator;
            cout << "SquareSummator: ";
            break;
        default:
            s = new CubeSummator;
            cout << "CubeSummator: ";
            break;
    }

    cout << "(5) " << s->sum(5) << "\n";
    delete s;
}