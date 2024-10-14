#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include "libs.h"
#include "OList.h"

struct Set{
    OList data;

    int contains(const string&);
    void add(const string&);
    void remove(const string&);
};

#endif // SET_H_INCLUDED
