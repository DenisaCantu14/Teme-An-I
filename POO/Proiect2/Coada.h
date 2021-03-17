#include <bits/stdc++.h>
using namespace std;
#ifndef COADA_H
#define COADA_H
#include "Nod.h"
#pragma once

class Coada
{
protected:
    Nod *prim;
    Nod *ultim;
    int dim_max;
public:
    Coada();
    Coada(char cuv[][30], int dim);
    Coada(const Coada &ob);
    virtual ~Coada();
    virtual void Insert(char *x, int w);
    virtual void top(int w);
    virtual void pop(int w);
    int isEmpty();
    void Empty();
    Coada& operator = (const Coada &ob);
    friend istream& operator >> (istream& input, Coada& ob);
    friend ostream& operator << (ostream& output, Coada& ob);
};

#endif // COADA_H
