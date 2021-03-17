#include <bits/stdc++.h>
using namespace std;
#ifndef PARTIAL_H
#define PARTIAL_H
#pragma once
class Partial
{
protected:
    float scris_partial;
    float oral;
    float medie_p;
    float medie_i;
public:
    Partial();
    Partial(float scris, float o );
    virtual ~Partial();
    Partial(const Partial& other);
    Partial& operator=(const Partial& other);
    friend istream& operator >> (istream& input, Partial& ob);
    friend ostream& operator << (ostream& output, Partial& ob);
    virtual void afisare(ostream & output);
};

#endif // PARTIAL_H
