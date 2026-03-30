#include <string>
#include <sstream>
#include "Human.h"

using std::string;
using std::stringstream;

Human::Human() {
    this->name = "Неизвестно";
    this->surname = "Неизвестно";
    this->patronymic = "Неизвестно";
}

Human::Human(string name, string surname, string patronymic) {
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
}

string Human::getSurnameAndInitials() const {
    stringstream s;
    s << surname << " " << name[0] << "." << patronymic[0] << ".";
    return s.str();
}

string Human::getFullName() const {
    stringstream s;
    s << surname << " " << name << " " << patronymic;
    return s.str();
}
