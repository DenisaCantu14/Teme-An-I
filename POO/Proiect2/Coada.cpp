#include "Coada.h"
#include "cstring"
#include "Exceptions.h"
Coada::Coada()
{
    prim=NULL;
    ultim=NULL;
    dim_max=0;
}
Coada::Coada(char cuv[][30], int dim)
{
    dim_max=dim;

        prim = new Nod(cuv[0], NULL, NULL);
        ultim=new Nod(cuv[0], NULL, NULL);
        Nod* current;
        for (int i=1; i < dim; ++i)
        {
            if(i==1)
            {
                current = new Nod(cuv[i], ultim, NULL);
                ultim->next=current;
                prim=ultim;
                ultim=current ;
            }
            else
            {
                current = new Nod(cuv[i], ultim, NULL);
                ultim->next=current;
                ultim=current ;
            }
        }

}
Coada::Coada(const Coada &ob)
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

Coada::~Coada()
{
    delete prim;
    dim_max=0;
}
void Coada::Insert(char *x, int w)
{
    try
    {
        if (w == 0)
            throw Exceptions{ "Something Happened" };
        dim_max++;
        Nod* elem = new Nod(x,NULL, NULL);

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
                elem->prev = ultim;
                ultim->next=elem;
                ultim = elem;
            }
        }
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
    }
}

void  Coada::top( int w)
{
    try
    {
        if (w == 1 || isEmpty()==0)
            throw Exceptions{ "Something Happened" };

        cout<< "TOP: "<<prim->info<<'\n';
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
    }
}
void Coada::pop(int w)
{
    try
    {
        if (w == 1|| isEmpty()==0)
            throw Exceptions{ "Something Happened" };
        Nod* elem=prim;
        prim=prim->next;
        dim_max--;
        delete elem;
    }
    catch (Exceptions &e)
    {
        cout << e.what() <<endl;
    }

}
int Coada::isEmpty()
{
    if(dim_max)
        return 1;
    else
        return 0;
}
void Coada::Empty()
{

    while(dim_max)
       {Nod* elem=prim;
        prim=prim->next;
        dim_max--;
        delete elem;
    }
}
Coada& Coada:: operator =(const Coada &ob)
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
        ultim = new Nod(ob.prim->info, NULL, NULL);
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
istream& operator >> (istream& input, Coada& ob)
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

ostream& operator<<(ostream & out, Coada& ob)
{
    Nod *p = ob.prim;
    out<<"Afisare:"<<'\n';
    for(Nod *p =ob.prim; p != NULL; p = p -> next_node())
    {
        out << p->info_node() << " ";
    }
    out<<'\n'<<"Lungime: "<<ob.dim_max<<'\n';
    return out;
}


