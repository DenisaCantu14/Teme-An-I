#include <bits/stdc++.h>
using namespace std;
fstream f("date.in");
#include "Nod.h"
#include "Coada.h"
#include "Deque.h"
int main()
{
    char cuv[7][30]= {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
    Coada ob(cuv, 6);
    cout<<"Inainte de inserare:"<<'\n';
    cout<<ob;
    ob.Insert("ggg", 0);
    ob.Insert("hhh", 1);
    cout<<"Dupa inserare:"<<'\n';
    cout<<ob;
    cout<<'\n'<<'\n';

    Coada ob1;
    ob1=ob;
    ob1.Insert("cuvant_nou", 1);
    cout<<ob1;
    ob1.top(0);
    ob1.top(1);
    ob1.pop(0);
    ob1.pop(1);
    cout<<ob1;
    cout<<'\n'<<'\n';

    char cuv1[6][30]= {"verde", "rosu", "roz", "mov", "negru"};
    Deque ob2(cuv1, 5);
    cout<<"Inainte de inserare:"<<'\n';
    cout<<ob2;
    ob2.Insert("ddd", 0);
    ob2.Insert("fff", 1);
    cout<<"Dupa inserare:"<<'\n';
    cout<<ob2;
    cout<<'\n'<<'\n';

    Deque ob3;
    f>>ob3;
    cout<<ob3;
    ob3.top(0);
    ob3.top(1);
    ob3.pop(0);
    ob3.pop(1);
    ob3.pop(1);
    cout<<ob3;
    ob3.pop(1);
    ob3.pop(1);
    ob3.pop(1);
    cout<<ob3;
    ob3.pop(1);
    cout<<ob3;

    cout<<'\n'<<'\n';
    vector<Coada*> obiecte;
    char sir1[4][30]= {"Prima", "propozitie", "!"};
    char sir2[5][30]= {"A!","doua","propozitie", "."};

    Coada* c =new Coada(sir1, 3);
    obiecte.push_back(c);

    Deque* e =new Deque(sir2, 4);
    obiecte.push_back(e);

    Deque* l =new Deque;
    f>>*l;
    obiecte.push_back(l);

    for(int i = 0; i < obiecte.size(); ++i)
    {
        cout<<*obiecte[i];
        obiecte[i]->top(1);
    }
    return 0;
}
