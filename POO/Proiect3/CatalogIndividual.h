#ifndef CATALOGINDIVIDUAL_H
#define CATALOGINDIVIDUAL_H
#include <bits/stdc++.h>
#include <Examen.h>
#include "Exceptions.h"
using namespace std;
#pragma once


template<class T>
class CatalogIndividual
{
private:
    string nume_complet;
    int nr_examene;
    T *examene;
    string fisa;
    static int nr;
    int nr_quiz;

public:
    CatalogIndividual();
    CatalogIndividual(string n, int nt, T exam[]);
    virtual ~CatalogIndividual();
    CatalogIndividual(const CatalogIndividual<T>& other);
    CatalogIndividual& operator=(const CatalogIndividual<T>& other);
    CatalogIndividual& operator += (string obs);
    vector<string> restanta();
    void afisare (ostream& output) const;
    string getnume();
    static void print_nr()

    {
        nr++;
        cout << '\n'<<"Pagina  " << nr << endl;
    }
    int get_nr_quiz();
    friend istream& operator >> (istream& input, CatalogIndividual<T>& ob)
    {
        string nume, prenume;
        cout<<"Nume student:\n";
        input >> nume;
        cout<<"Prenume student:\n";
        input >> prenume;
        ob.nume_complet=nume+" "+prenume;
        try
        {
            if (nume == "" || prenume== "")
                throw Exceptions("Numele nu este complet");
        }
        catch (Exceptions &e)
        {
            ob.nume_complet="Necunoscut";
            cout << e.what() <<endl;
        }
        cout<<"Nr examene:\n";
        input >> ob.nr_examene;
        try
        {
            if (ob.nr_examene<=0)
                throw Exceptions("Numarul de examene nu e valid");
        }
        catch (Exceptions &e)
        {
            ob.nr_examene=0;
            cout << e.what() <<endl;
        }
        ob.examene=new T[ob.nr_examene];
        for(int i=0; i<ob.nr_examene; i++)
        {
            input>>ob.examene[i];
            if(ob.examene[i].getquiz())
                ob.nr_quiz++;
        }
        return input;
    };
    friend ostream& operator << (ostream& output, CatalogIndividual<T>& ob)
    {
        ob.afisare(output);

    };

};

template <class T>
int CatalogIndividual<T>::nr = 0;

template <class T>
CatalogIndividual<T>::CatalogIndividual()
{
    examene=NULL;
    nr_examene=0;
    nr_quiz=0;

}
template <class T>
CatalogIndividual<T>::CatalogIndividual(string n, int nr, T exam[])
{
    nume_complet=n;
    nr_examene=nr;
    examene=new T[nr];
    for(int i = 0; i < nr; i++)
        examene[i]=exam[i];

}
template <class T>
CatalogIndividual<T>::~CatalogIndividual()
{
    nr--;
    nr_examene=0;
    delete [] examene;

}
template <class T>
CatalogIndividual<T>::CatalogIndividual(const CatalogIndividual& other)
{
    nume_complet=other.nume_complet;
    nr_examene=other.nr_examene;
    examene=new T[nr_examene];
    for(int i = 0; i < nr_examene; i++)
        examene[i]=other.examene[i];
    nr_quiz=other.nr_quiz;


}
template <class T>
CatalogIndividual<T>& CatalogIndividual<T>::operator=(const CatalogIndividual<T>& rhs)
{
    if (this == &rhs)
        return *this;
    nume_complet=rhs.nume_complet;
    nr_examene=rhs.nr_examene;
    delete []examene;
    examene=new T[nr_examene];
    for(int i = 0; i < nr_examene; i++)
        examene[i]=rhs.examene[i];
    nr_quiz=rhs.nr_quiz;
    return *this;
}
template <class T>
CatalogIndividual<T>& CatalogIndividual<T>::operator += (string obs)
{
    this->fisa=obs;
}


template <typename T>
void  CatalogIndividual<T>::afisare (ostream& output) const

{
    print_nr();
    cout<<nume_complet<<" are "<<nr_examene<<" examene:\n";
    for (int i=0; i < nr_examene; i++)
         cout<<examene[i];
    if(fisa!="")
        cout<<"A fost adaugata fisa de observatii:\n"<<fisa<<'\n';
}

template <typename T>
vector<string> CatalogIndividual<T>::restanta()
{
    vector<string> v;
    for(int i=0; i<nr_examene; i++)
        if(examene[i].getnota()<5)
            v.push_back(examene[i].getmaterie());
    return v;
}

template <typename T>
string  CatalogIndividual<T>:: getnume()
{
    return nume_complet;
}

template <typename T>
int CatalogIndividual<T>::get_nr_quiz()
{
    return nr_quiz;
}

#endif // CATALOGINDIVIDUAL_H
