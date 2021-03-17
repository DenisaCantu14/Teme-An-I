#include <bits/stdc++.h>
using namespace std;
#ifndef NOD_H
#define NOD_H
#pragma once

class Nod
{
     private:
            char *info;
            Nod *next;
            Nod *prev;
     public:
        Nod();
        Nod(char *x, Nod *p, Nod *s);
        Nod(const Nod &ob);
        ~Nod();
        Nod* next_node();
         Nod* prev_node();
        char* info_node();
        friend istream& operator >> (istream& input, Nod& ob);
        friend ostream& operator << (ostream& output, Nod& ob);
        Nod& operator = (const Nod &other);
        friend class Coada;
        friend class Deque;

};

#endif // NOD_H
