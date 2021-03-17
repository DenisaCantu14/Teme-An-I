#ifndef QUIZ_H
#define QUIZ_H
#include <bits/stdc++.h>
using namespace std;
#pragma once

class Quiz
{
private:
    int len;
    string  *studenti;
public:
    Quiz();
    Quiz(int len, string nume[]);
    virtual ~Quiz();
    Quiz(const Quiz& other);
    Quiz& operator=(const Quiz& other);
    void adauga(string nume);
    friend istream& operator >> (istream& input, Quiz& ob);
    friend ostream& operator << (ostream& output, Quiz& ob);


};

#endif // QUIZ_H
