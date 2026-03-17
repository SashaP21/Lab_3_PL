#ifndef _3_HUMAN_H
#define _3_HUMAN_H

#include <string>

class Human {
    std::string name;
    std::string surname;
    std::string patronymic;
public:
    Human();
    Human(std::string name,
          std::string surname,
          std::string patronymic);
    std::string getSurnameAndInitials() const;
    std::string getFullName() const;
};

#endif //_3_HUMAN_H