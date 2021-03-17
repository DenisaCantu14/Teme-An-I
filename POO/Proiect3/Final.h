#include <bits/stdc++.h>
using namespace std;
#ifndef FINAL_H
#define FINAL_H
#pragma once
class Final
{
protected:
    float scris_final;
    float bonus;
    float media_final;
public:
    Final();
    Final(float scris, float b);
    virtual ~Final();
    Final(const Final& other);
    Final& operator=(const Final& other);
    friend istream& operator >> (istream& input, Final& ob);
    friend ostream& operator << (ostream& output, Final& ob);
    virtual void afisare(ostream & output);
};

#endif // FINAL_H
