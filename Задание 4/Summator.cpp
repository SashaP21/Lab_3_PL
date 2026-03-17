#include "Summator.h"

int Summator::transform(int i) {
    return i;
}

int Summator::sum(int N) {
    int sum = 0;
    for (int n = 1; n <= N; n++)
        sum += transform(n);
    return sum;
}
