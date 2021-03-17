#include "Final.h"
#include "Exceptions.h"

Final::Final() {}

Final::Final(float scris, float b)
{
    scris_final = scris;
    bonus = b;
    media_final = scris+bonus;
}

Final::~Final()
{
    bonus = 0;
    scris_final = 0;
    media_final = 0;
}

Final::Final(const Final& other)
{
    scris_final = other.scris_final;
    bonus = other.bonus;
    media_final = other.media_final;
}

Final& Final::operator = (const Final& rhs)
{
    if (this == &rhs)
        return *this;
    scris_final = rhs.scris_final;
    bonus = rhs.bonus;
    media_final = rhs.media_final;
    return *this;
}
istream& operator >> (istream& input, Final& ob)
{
    cout<<"Nota scris final:\n";
    input >> ob.scris_final;
    try
    {
        if (ob.scris_final<1 || ob.scris_final>10)
            throw Exceptions("Nota  este invalida");
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
        ob.scris_final=0;
    }
    cout<<"Bonus(0-2p):\n";
    input >>ob.bonus;
    try
    {
        if ( ob.bonus<0 || ob.bonus>2)
            throw Exceptions("Valoarea  este invalida");
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
        ob.bonus=0;
    }
    ob.media_final=ob.scris_final+ob.bonus;
    return input;
}

void Final :: afisare(ostream & output)
{
    cout<<"Final\n";
    cout<<"Nota scris: "<<scris_final<<" si bonus: "<<bonus<<", medie final: "<<media_final;
}
ostream& operator << (ostream& output, Final& ob)
{
    ob.afisare(output);
}
