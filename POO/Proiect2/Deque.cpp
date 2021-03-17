#include "Deque.h"
#include "Exceptions.h"
Deque::Deque():Coada() {}
Deque::Deque(char cuv[][30], int dim ):Coada(cuv, dim) {}
Deque::Deque(const Deque &ob):Coada(ob) {}
Deque::~Deque()
{
}
void Deque::Insert(char *x, int w)
{
    Nod* elem = new Nod(x,NULL, NULL);
    if(w==0)
    {
        dim_max++;
        if (prim == NULL)
        {
            prim = ultim = elem;
        }
        else
        {
            elem->next = prim;
            prim->prev=elem;
            prim = elem;
        }
    }
    if(w==1)
    {
        dim_max++;
        if (ultim == NULL)
        {
            prim = new Nod(x,NULL, NULL);
            ultim = new Nod(x,NULL, NULL);
        }
        else
        {
            if(ultim->prev==NULL)
            {
                elem ->prev=ultim;
                ultim->next=elem;
                prim=ultim;
                ultim=elem;
            }
            else
            {
                elem->prev=ultim;
                ultim->next = elem;
                ultim = elem;
            }
        }
    }
}
void  Deque::top( int w)
{
    try
    {
        if (isEmpty()==0)
            throw Exceptions{ "Empty queue" };
        else
            if(w==0)
                cout<< "First element:"<<'\n'<<prim->info<<'\n';
            else
                cout<< "Last element:"<<'\n'<<ultim->info<<'\n';
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
    }
}
void Deque::pop(int w)
{
    try
    {
        if(isEmpty()==0)
            throw Exceptions{ "Empty queue" };
        if(w==0)
        {
            Nod* elem=prim;
            prim=prim->next;
            if(prim==NULL)
                ultim=NULL;
            else
                prim->prev=NULL;

            dim_max--;
            delete elem;
        }
        else
        {
            Nod* elem=ultim;
            ultim=ultim->prev;
            if(ultim==NULL)
                prim=NULL;
            else
                ultim->next=NULL;
            dim_max--;
            delete elem;
        }
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
    }
}

Deque& Deque:: operator =(Deque ob)
{
    dim_max=ob.dim_max;
    if (ob.prim == NULL)
    {
        prim = NULL;
        ultim=NULL;
    }
    else
    {
        Nod *current = new Nod(ob.prim->info, NULL, NULL);
        prim = new Nod(ob.prim->info, NULL, current);
        Nod *currentObj =  ob.prim;
        int ok=0;
        while (currentObj->next != NULL)
        {
            if(ok==0)
            {
                prim=current;
                ok=1;
            }
            current->next = new Nod(currentObj->next->info, current,NULL);
            currentObj = currentObj->next;
            current = current->next;
        }
        ultim=current;
    }
}
istream& operator >> (istream& input, Deque& ob)
{
    char n[1000], *p;
    input.getline(n, 10001);
    p=strtok(n, " ");
    while(p)
    {
        ob.Insert(p, 1);
        p=strtok(NULL, " ");
    }
}

ostream&  operator<<(ostream & out, Deque& ob)
{
    Nod *p = ob.prim;
    out<<"Afisare:"<<'\n';
    for(Nod *p =ob.prim; p != NULL; p = p -> next_node())
    {
        out << p->info_node() << " ";
    }
    out<<'\n'<<"Lungime: ";
    out<<ob.dim_max;
    out<<'\n';
    return out;
}

