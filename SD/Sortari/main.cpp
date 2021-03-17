#include <bits/stdc++.h>
using namespace std;
fstream fin("date.in");
int n, maxcif, v[100000009], l[100000009], a[100000009];

int getmax(int v[], int n)
{
    int  maxi=v[0];
    for(int i=1; i<=n; i++)
        maxi=max(maxi, v[i]);
    return maxi;
}


void afisare(char c[], double timp, int ok)
{
    cout<<c<<" "<<timp<<" "<<ok<<'\n';
}

void fillFunc(int arr[], int n, int maxicif)
{
    for (int i = 1; i <=n; i++)
        arr[i] = (rand()*rand())% maxcif;

}

void testare(int n, int v[], char c[], double timp)
{
    int ok=1;
    for(int i=1; i<n; i++)
        if(v[i]>v[i+1])
        {
            ok=0;
        }
    afisare(c, timp, ok);
}
void copiere(int v[], int a[], int n)
{
    for(int i=1; i<=n; i++)
        v[i]=a[i];
}

void bubble(int n, int v[])
{
    int i, j;
    bool swaped;
    for(i=1; i<n; i++)
    {
        swaped=false;
        for(j=1; j<=n-i; j++)
            if(v[j]>v[j+1])
            {
                swap(v[j], v[j+1]);
                swaped=true;
            }

        if(swaped == false)
            break;
    }
}

void interclasare(int st, int dr, int m)
{
    int loc=0, i=st, j=m+1;
    while(i<=m && j<=dr)
    {
        if(v[i]<v[j])
            l[++loc]=v[i++];
        else
            l[++loc]=v[j++];
    }
    while(i<=m)
        l[++loc]=v[i++];
    while(j<=dr)
        l[++loc]=v[j++];
    for(i=st, j=1; i<=dr; i++, j++)
    {
        v[i]=l[j];
    }
}
void mergesort(int st, int dr)
{
    if(st<dr)
    {
        int m=(st+dr)/2;
        mergesort(st, m);
        mergesort( m+1, dr);
        interclasare(st, dr, m);
    }
}

void countsort(int n, int v[])
{
    int l[10000]= {0};//pt freventa
    int i, loc=0, maxi;
    for(i=1; i<=n; i++)
        l[v[i]]++;
    maxi=getmax(v, n);
    for(i=0; i<=maxi; i++)
    {
        while(l[i])
        {
            v[++loc]=i;
            l[i]--;
        }
    }
}
void cifra(int v[], int n, int exp, int baza)
{
    int output[n+1];
    int i, count[baza+1] = {0};
    for (i = 1; i <=n; i++)
        count[ (v[i]/exp)%baza]++;
    for (i = 1; i < baza; i++)
        count[i] += count[i - 1];
    for (i = n ; i > 0; i--)
    {
        output[count[ (v[i]/exp)% baza]] = v[i];
        count[ (v[i]/exp)%baza ]--;
    }
    for (i = 1; i <= n; i++)
        v[i] = output[i];
}
void radixsort(int n, int v[], int baza)
{
    int m = getmax(v, n);
    for (int exp = 1; m/exp > 0; exp *= baza)
        cifra(v, n, exp, baza);
}

void quiksort(int st, int dr, int v[ ],int varianta)
{

    int piv;
    if(varianta==1)
    {
        piv=v[(st+dr)/2];

    }
    else
    {
        piv=v[st+rand()%(dr-st+1)];

    }
    int i=st;
    int j=dr;

    while(i<=j)
    {
        while(v[i]<piv)
            i++;
        while(v[j]>piv)
            j--;
        if(i<=j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }

    }

    if(st<j)
        quiksort( st, j, v, varianta);
    if(i<dr)
        quiksort(i, dr, v, varianta);
}
int main()
{
    int nr_teste;
    fin>>nr_teste;
    for(int i=1; i<=nr_teste; i++)
    {
        fin>>n;
        fin>>maxcif;
        srand((unsigned) time(0));
        clock_t start, end;
        double time_taken;
        srand((unsigned)time(NULL));
        fillFunc(a, n, maxcif);
        cout<<i<<"."<<'\n';
        cout<<"N="<<n<<", Max="<<getmax(a, n)<<'\n';

        if(n<10000)
        {
            copiere(v, a, n);
            start = clock();
            bubble(n, v);
            end = clock();
            time_taken= double(end - start) / double(CLOCKS_PER_SEC);
            testare(n, v, "Bubble_sort", time_taken);
        }


        copiere(v, a, n);
        start = clock();
        mergesort(1, n);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        testare(n, v, "Merge_sort", time_taken);

        if(getmax(v, n)<10000)
        {
            copiere(v, a, n);
            start = clock();
            countsort(n, v);
            end = clock();
            time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            testare(n, v,"Count_sort", time_taken);
        }

        copiere(v, a, n);
        start = clock();
        quiksort( 1, n, v, 1);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        testare(n, v,"Quick_sort_mijloc", time_taken);

        copiere(v, a, n);
        start = clock();
        quiksort( 1, n, v, 2);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        testare(n, v,"Quick_sort_random", time_taken);

        if(n<1000000)
        {
            copiere(v, a, n);
            start = clock();
            radixsort(n, v, 10);
            end = clock();
            time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            testare(n, v, "Radix_sort_baza_10", time_taken);

            copiere(v, a, n);
            start = clock();
            radixsort(n, v, 256);
            end = clock();
            time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            testare(n, v, "Radix_sort_baza_256", time_taken);
            cout<<'\n'<<'\n';
        }

    }

    return 0;
}
