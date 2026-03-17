#ifndef _2_ANIMAL_H
#define _2_ANIMAL_H

class Animal {
public:
    virtual ~Animal() = default;
    virtual void breathe() = 0;
    virtual void eat() = 0;
};

#endif //_2_ANIMAL_H