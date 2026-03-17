#ifndef _4_SUMMATOR_H
#define _4_SUMMATOR_H

class Summator {
protected:
    virtual int transform (int i);
public:
    virtual ~Summator() = default;
    int sum(int N);
};

#endif //_4_SUMMATOR_H