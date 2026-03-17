#ifndef _2_BIRD_H
#define _2_BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    void lay_eggs();
    void breathe() override;
    void eat() override;
};

#endif //_2_BIRD_H