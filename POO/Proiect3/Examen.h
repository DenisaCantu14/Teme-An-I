#ifndef EXAMEN_H
#define EXAMEN_H
#include <bits/stdc++.h>
using namespace std;
#include <Partial.h>
#include <Final.h>
#pragma once
class Examen: public Partial, public Final
{
private:

    float nota_finala;
    static int nr;
    string materie;
    int quiz;
    const int bonus_q;
    int nr_aut;

public:
    Examen();
    Examen(int nota, string denumire,float p, float o, float f, float b, int q);
    virtual ~Examen();
    Examen(const Examen& other);
    Examen& operator=(const Examen& other);
    friend istream& operator >> (istream& input, Examen& ob);
    friend ostream& operator << (ostream& output, Examen& ob);
    void afisare(ostream & output);
    int getnota();
    string getmaterie();
    int getquiz();

};

#endif // EXAMEN_H
