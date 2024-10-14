#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "libs.h"
#include "OList.h"

struct Stack{
    ONode* head;
    ONode* tail;

    Stack() : head(nullptr), tail(nullptr){}

    bool is_empty();
    void push(string);
    void pop();
    void print();
};

#endif // STACK_H_INCLUDED
