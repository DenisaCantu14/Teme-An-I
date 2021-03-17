#include "Quiz.h"
#include "Exceptions.h"
Quiz::Quiz()
{
    len=0;
    studenti= new string[0];
}

Quiz::Quiz(int len, string nume[])
{
    this->len=len;
    studenti=new string[len];
    for(int i = 0; i < len; i++)
        studenti[i]=nume[i];

}
Quiz::~Quiz()
{
    delete [] studenti;
    len=0;
}

Quiz::Quiz(const Quiz& other)
{
    this->len=other.len;
    studenti=new string[len];
    for(int i = 0; i < len; i++)
        studenti[i]=other.studenti[i];
}

Quiz& Quiz::operator=(const Quiz& rhs)
{
    if (this == &rhs)
        return *this;
    this->len=rhs.len;
    delete [] studenti;
    studenti=new string[len];
    for(int i = 0; i < len; i++)
        studenti[i]=rhs.studenti[i];
    return *this;
}
void Quiz::adauga(string nume)
{
    len++;
    string* aux=new string[len];
    for(int i = 0; i < len-1; i++)
        aux[i]=studenti[i];
    aux[len-1]=nume;
    delete [] studenti;
    studenti=new string[len];
    for(int i = 0; i < len; i++)
    {
        studenti[i]=aux[i];
    }
    delete[]aux;


}
istream& operator >> (istream& input, Quiz& ob)
{
    input>>ob.len;
    try
    {
        if (ob.len<0)
            throw Exceptions("Numarul nu poate fi negativ");
    }
    catch (Exceptions &e)
    {
        ob.len=0;
        cout << e.what() <<endl;
    }
    for( int i=0; i<ob.len; i++)
        input>>ob.studenti[i];
    return input;

}
ostream& operator << (ostream& output, Quiz& ob)
{
    output<<ob.len/2<<" au dat quiz-ul:\n";
    for( int i=0; i<ob.len; i++)
        output<<ob.studenti[i];
    return output;
}
