#include "Nod.h"
#include "cstring"

Nod::Nod()
{
    info=new char[0];
    next=NULL;
    prev=NULL;

}
Nod::Nod(char *x, Nod*p, Nod *s)
{
    info=new char;
    info=x;
    next=s;
    prev=p;
}
Nod::Nod(const Nod &ob)
{
    info=new char;
    strcpy(info, ob.info);
    next=ob.next;
    prev=ob.prev;

}

Nod::~Nod()
{
    delete info;
    delete next;

}

Nod* Nod:: next_node()
{
    return next;
}
char* Nod:: info_node()
{
    return info;
}

Nod& Nod:: operator =(const Nod &other)
{
    info=new char;
    strcpy(info, other.info);
    next=other.next;
    prev=other.prev;
}

istream& operator >> (istream& input, Nod& ob)
{
    input >> ob.info;
    return input;
}

ostream& operator << (ostream& output, Nod& ob)
{
    output << ob.info << '\n';
    return output;
}
