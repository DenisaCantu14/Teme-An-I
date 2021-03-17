#include <bits/stdc++.h>
using namespace std;
class Vector
{
private:
    int L, *arr;
public:
    Vector();
    Vector(int l, int nr);
    Vector(Vector&ob);
    ~Vector();
    Vector operator = (Vector other);
    void reactualizare(int nr_comp, int nr);
    int suma ();
    void maxim(int &maxi, int &poz);
    void sortare();
    friend long operator *(Vector & ob1, Vector & ob2);
    friend istream& operator >> (istream& input, Vector& ob);
    friend ostream& operator << (ostream& output, Vector& ob);
    Vector* citeste(int n)
    {
        Vector *v= new Vector[n];
        for(int i=1; i<=n; i++)
            cin>>v[i];
        for(int i=1; i<=n; i++)
            cout<<v[i]<<'\n';
        return v;

    }
};
Vector::Vector()
{
    L=0;
    arr=NULL;
}

Vector:: Vector(int l, int nr)
{
    arr = new int[l+1];
    for(int i = 1; i <=l; i++)
        arr[i] = nr;
    L = l;
}

Vector::Vector(Vector&ob)
{
    L = ob.L;
    if(ob.L<=0)
        arr=NULL;
    else
    {
        arr = new int[ob.L+1];
        for(int i = 1; i <=ob.L; i++)
            arr[i] = ob.arr[i];
    }
}
Vector::~Vector()
{
    L=0;
    delete[] arr;
}

Vector  Vector:: operator =(Vector other)
{
    L = other.L;
    if(arr!=NULL)
        delete[]arr;
    if(other.L<=0)
        arr=NULL;
    else
    {
        arr = new int[other.L+1];
        for(int i=1; i<=L; i++)
            arr[i]=other.arr[i];
    }


}

void Vector:: reactualizare(int nr_comp, int nr)
{
    if(nr_comp>=1 && nr_comp<=L)
        for(int i=1; i<=nr_comp; i++)
            arr[i]=nr;
    else if(nr_comp>L)
    {
        delete [] arr;
        arr= new int[nr_comp+1];
        for(int i=1; i<=nr_comp; i++)
            arr[i]=nr;
    }
}

int Vector::suma ()
{
    int suma=0;
    for(int i=1; i<=L; i++)
        suma+=arr[i];
    return suma;
}

void Vector:: maxim(int &maxi, int &poz)
{
    for(int i=1; i<=L; i++)
        if(arr[i]>maxi)
        {
            maxi=arr[i];
            poz=i;
        }
}
void Vector::sortare()
{
    for(int i=1; i<L; i++)
        for(int j=i+1; j<=L; j++)
            if(arr[i]>arr[j])
                swap(arr[i], arr[j]);
}

long  operator *(Vector & ob1, Vector & ob2)
{
    long produs=0;
    if(ob1.L !=ob2.L)
        return 0;
    else
    {
        for(int i=1; i<=ob1.L; i++)
            produs=produs +ob1.arr[i]*ob2.arr[i];
        return produs;
    }
}
istream& operator >> (istream& input, Vector& ob)
{
    input >> ob.L;
    for(int i=1; i<=ob.L; i++)
        input>>ob.arr[i];
    return input;
}

ostream& operator << (ostream& output, Vector& ob)
{
    output << ob.L << '\n';
    for (int i = 1; i <=ob.L; i++)
        output << ob.arr[i] << ' ';
    output << '\n';
    return output;
}



int main()
{
    int n;
    cin>>n;
    Vector ob(4,5);
    cout<<ob.suma()<<'\n';
    Vector ob1(4, 15);
    ob1.reactualizare(4,1);
    ob=ob1;
    cout<<ob*ob1;

    return 0;
}
