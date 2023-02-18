#ifndef Nudl_H
#define Nudl_H
#include"Data.h"

using namespace std;

template <class D ,class T>
class Nudl
{
public:

    Data<D, T> data;
    Nudl* next;
};

#endif /*Nudl_H*/