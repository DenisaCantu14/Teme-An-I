#include "Examen.h"
#include "Exceptions.h"
int Examen::nr = 0;
Examen::Examen():Partial(), Final(), bonus_q(1)
{
    nr++;
    materie="";
    quiz=0;
    nr_aut=nr;
}
Examen::Examen(int nota, string denumire,float p, float o, float f, float b, int q):Partial(p, o), Final(f, b), bonus_q(1)
{
    nr++;
    nr_aut=nr;
    if(medie_i< 5)
    {
        medie_p=scris_final;
        nota_finala=(medie_p+media_final)/2;
    }
    else
        nota_finala=(medie_i+media_final)/2;
    if(media_final<5)
        nota_finala=min(medie_i, media_final);
    materie = denumire;
    quiz=q;
    if(quiz && nota_finala>5)
        nota_finala+=bonus_q;
    if(nota_finala>10)
        nota_finala=10;
}

Examen::~Examen()
{
    nr--;
    nota_finala=0;
}

Examen::Examen(const Examen& other):Final(other), Partial(other),bonus_q(1)
{
    nr++;
    nr_aut=nr;
    nota_finala = other.nota_finala;
    materie = other.materie;
    quiz=other.quiz;
}
Examen& Examen :: operator=(const Examen& rhs)
{
    if (this == &rhs)
        return *this;
    scris_partial = rhs.scris_partial;
    oral = rhs.oral;
    medie_i = rhs.medie_i;
    medie_p = rhs.medie_p;
    scris_final = rhs.scris_final;
    bonus = rhs.bonus;
    media_final = rhs.media_final;
    nr_aut=rhs.nr_aut;
    nota_finala = rhs.nota_finala;
    materie = rhs.materie;
    quiz=rhs.quiz;

}
int  Examen :: getnota()
{
    return nota_finala;
}
string Examen ::getmaterie()
{
    return materie;
}
int  Examen ::getquiz()
{
    return quiz;
}


istream& operator >> (istream& input, Examen& ob)
{
    cout<<"Nume materie:\n";
    input>> ob.materie;
    try
    {
        if (ob.materie=="")
            throw Exceptions("Nume materie invalid");
    }
    catch (Exceptions &e)
    {
        ob.materie="Nespecificat";
        cout << e.what() <<endl;
    }
    input >> dynamic_cast <Partial&> (ob);
    input >> dynamic_cast <Final&> (ob);
    cout<<"A dat quiz (0/1):\n";
    input>>ob.quiz;
    try
    {
        if (ob.quiz!=0 && ob.quiz!=1)
            throw Exceptions("Valoare invalida");
    }
    catch (Exceptions &e)
    {
        ob.quiz=0;
        cout << e.what() <<endl;
    }
    if(ob.medie_i< 5)
    {
        ob.medie_p=ob.scris_final;
        ob.nota_finala=(ob.medie_p+ob.media_final)/2;
    }
    else
        ob.nota_finala=(ob.medie_i+ob.media_final)/2;
    if(ob.media_final<5)
        ob.nota_finala=min(ob.medie_i, ob.media_final);
    if(ob.quiz && ob.nota_finala>5)
        ob.nota_finala+=ob.bonus_q;
    if(ob.nota_finala>10)
        ob.nota_finala=10;
    return input;
}

void Examen :: afisare(ostream & output)
{
    cout<<nr_aut<<'.'<<materie<<'\n';
    cout<<"Partial\n";
    cout<<"Nota scris: "<<scris_partial<<" si nota la oral: "<<oral<<", medie partial: "<<medie_i<<'\n';
    if(medie_p)
        cout<<"Medie partial dupa refacere: "<<medie_p<<'\n';
    cout<<"Final\n";
    cout<<"Nota scris: "<<scris_final<<" si bonus: "<<bonus<<", medie final: "<<media_final<<'\n';
    cout<<"Nota finala este: "<<nota_finala<<'\n';
    cout<<'\n';

}
ostream& operator << (ostream& output, Examen& ob)
{
    ob.afisare(output);
    return output;
}
