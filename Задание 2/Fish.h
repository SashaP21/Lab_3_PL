#ifndef _2_FISH_H
#define _2_FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    void swim();
    void breathe() override;
    void eat() override;
};

#endif //_2_FISH_H