#include <bits/stdc++.h>
using namespace std;
#ifndef DEQUE_H
#define DEQUE_H
#include "Coada.h"
#pragma once

class Deque:public Coada
{
public:
    Deque();
    Deque(char cuv[][30], int dim );
    Deque(const Deque &ob);
    ~Deque();
    void Insert (char *x, int w);
    void top (int w);
    void pop(int w);
    Deque& operator = (Deque ob);
    friend istream& operator >> (istream& input, Deque& ob);
    friend ostream& operator << (ostream& output, Deque& ob);
};

#endif // DEQUE_H
