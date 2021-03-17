#include "Partial.h"
#include "Exceptions.h"
Partial::Partial() {}

Partial::Partial(float scris, float o)
{
    scris_partial = scris;
    oral = o;
    medie_p = 0;
    medie_i = (scris_partial+oral)/2;
}

Partial::~Partial()
{
    oral = 0;
    scris_partial = 0;
    medie_p = 0;
    medie_i = 0;
}

Partial::Partial(const Partial& other)
{
    scris_partial = other.scris_partial;
    oral = other.oral;
    medie_i = other.medie_i;
    medie_p = other.medie_p;
}

Partial& Partial::operator=(const Partial& rhs)
{
    if (this == &rhs)
        return *this;
    scris_partial = rhs.scris_partial;
    oral = rhs.oral;
    medie_i = rhs.medie_i;
    medie_p = rhs.medie_p;
    return *this;
}
istream& operator >> (istream& input, Partial& ob)
{
    cout<<"Nota scris partial:\n";
    input >> ob.scris_partial;
    try
    {
        if (ob.scris_partial<1 || ob.scris_partial>10)
            throw Exceptions("Nota  este invalida");
    }
    catch (Exceptions &e)
    {
        ob.scris_partial=0;
        cout << e.what() <<endl;
    }
    cout<<"Nota oral partial:\n";
    input>>ob.oral;
    try
    {
        if ( ob.oral<1 || ob.oral>10)
            throw Exceptions("Nota  este invalida");
    }
    catch (Exceptions &e)
    {
        ob.oral=0;
        cout << e.what() <<endl;
    }
    ob.medie_i = (ob.scris_partial+ob.oral)/2;
    ob.medie_p = 0;
    return input;
}

void Partial :: afisare(ostream & output)
{
    cout<<"Partial\n";
    cout<<"Nota scris: "<<scris_partial<<" si nota la oral: "<<oral<<", medie partial: "<<medie_i;
}

ostream& operator << (ostream& output, Partial& ob)
{
    ob.afisare(output);
}
