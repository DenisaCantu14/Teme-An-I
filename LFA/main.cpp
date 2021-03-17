#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
int initiala, nr_stari, finale[101], nr_finale, nr_muchii, stare1, stare2, fr[101];
char c;

struct tabel
{
    int v[101]= {-1};
    int n=0;

} dfa[101][101], nfa[101][101], coada[101], sf[101];

int main()
{
    fin>>initiala;
    fin>>nr_stari;
    fin>>nr_finale;
    for(int i=1; i<=nr_finale; i++)
        fin>>finale[i];
    for(int i=0; i<nr_stari; i++) // construiesc tabelul pt nfa punand pe coloana 0 nr corespuzator fiecarei stari
    {
        nfa[i][0].n=1;
        nfa[i][0].v[1]=i;
    }
    fin>>nr_muchii;
    for(int i=1; i<=nr_muchii; i++)
    {
        fin>>stare1>>stare2>>c;
        nfa[stare1][c-'a'+1].v[++nfa[stare1][c-'a'+1].n]=stare2; //marchez muchia de la o stare la alta punand starea2 pe linia starii1 si coloana corespunzatoare ordinii caracterului in alfabet
    }
    // memorez in vectorul sf noile stari finale
    int loc=0;
    for(int i=1; i<=nr_finale; i++)
        if(initiala==finale[i]) // daca starea initiala este si finala
        {
            sf[++loc].v[++sf[loc].n]=initiala; // o pun in vector
            break;
        }
    int ultim=1;
    coada[ultim].v[++coada[ultim].n]=initiala;
    dfa[0][0].v[++dfa[0][0].n]=initiala; // pun starea initiala in dfa
    for(int i=1; i<=26; i++) //copiez in n toate muchiile ce pleaca din starea intiala
    {
        dfa[0][i].n=nfa[initiala][i].n;
        for(int j=1; j<=nfa[initiala][i].n; j++)
            dfa[0][i].v[j]=nfa[initiala][i].v[j];
        int OK=0; // verfic daca noua stare formata este sau nu in coada
        for(int j=1; j<=ultim; j++)
        {
            int ok=0;
            if(coada[j].n==dfa[0][i].n)
            {
                ok=1;
                for(int k=1; k<=dfa[0][i].n; k++)
                    if(coada[j].v[k]!=dfa[0][i].v[k])
                        ok=0;
            }
            if(ok==1)
            {
                OK=1;
                break;
            }
        }
        if(OK==0) //daca nu este deja in coada
        {
            ultim++;// adaug starea in coada
            coada[ultim].n=dfa[0][i].n;
            int found=0; //verfic daca noua stare contine o stare finala din nfa
            for(int k=1; k<=dfa[0][i].n; k++)
            {
                coada[ultim].v[k]=dfa[0][i].v[k];
                for(int l=1; l<=nr_finale; l++)
                    if(dfa[0][i].v[k]==finale[l])
                    {
                        found=1;
                        break;
                    }
            }
            if(found==1) // daca contine o stare finala, noua stare devine si ea finala si o memorez in sf
            {
                loc++;
                sf[loc].n=dfa[0][i].n;
                for(int k=1; k<=dfa[0][i].n; k++)
                    sf[loc].v[k]=dfa[0][i].v[k];
            }



        }
    }
    int prim=2;
    int linie=0;
    while(prim<=ultim) // parcurg coada
    {
        linie++;
        dfa[linie][0].n=coada[prim].n;
        for(int i=1; i<=coada[prim].n; i++) // memorez in coalana 0 a matricei n noua starea curenta din coada
        {

            dfa[linie][0].v[i]=coada[prim].v[i];
        }
        for(int i=1; i<=26; i++) //pt fiecare caracter
        {
            for(int j=1; j<=dfa[linie][0].n; j++)
                for(int k=1; k<=nfa[dfa[linie][0].v[j]][i].n; k++)
                    fr[nfa[dfa[linie][0].v[j]][i].v[k]]=1; //marchez starile intre care exista muchie
            for(int j=0; j<nr_stari; j++)
                if(fr[j]) // formez noua stare
                {
                    dfa[linie][i].v[++dfa[linie][i].n]=j;
                    fr[j]=0;
                }
            int OK=0; //verific daca noua stare formata este deja in coada
            for(int j=1; j<=ultim; j++)
            {
                int ok=0;
                if(coada[j].n==dfa[linie][i].n)
                {
                    ok=1;
                    for(int k=1; k<=dfa[linie][i].n; k++)
                        if(coada[j].v[k]!=dfa[linie][i].v[k])
                            ok=0;
                }
                if(ok==1)
                {
                    OK=1;

                }
            }
            if(OK==0) // daca nu este deja in coada o adaug
            {
                ultim++;
                coada[ultim].n=dfa[linie][i].n;
                int found=0; //verfic daca noua stare contine o stare finala din nfa
                for(int k=1; k<=dfa[linie][i].n; k++)
                {
                    coada[ultim].v[k]=dfa[linie][i].v[k];
                    for(int l=1; l<=nr_finale; l++)
                        if(dfa[linie][i].v[k]==finale[l])
                        {
                            found=1;
                            break;
                        }
                }
                if(found==1) // daca contine o stare finala, noua stare devine si ea finala si o memorez in sf
                {
                    loc++;
                    sf[loc].n=dfa[linie][i].n;
                    for(int k=1; k<=dfa[linie][i].n; k++)
                        sf[loc].v[k]=dfa[linie][i].v[k];
                }

            }

        }

        prim++; //trec la urmatoarea pozitie din coada, la urmatoarea stare
    }
    for(int i=0; i<=linie; i++) //adiseaza dfa-ul
    {
        for(int k=1; k<=26; k++)
        {
            if(dfa[i][k].n)
            {
                cout<<"De la { ";
                for(int j=1; j<=dfa[i][0].n; j++)
                    cout<<dfa[i][0].v[j]<<' ';
                cout<<"} la { ";
                for(int j=1; j<=dfa[i][k].n; j++)
                    cout<<dfa[i][k].v[j]<<' ';
                cout<<"} cu ";
                cout<<char(97+k-1);
                cout<<'\n';
            }
        }
    }
    cout<<"Stari finale:"<<'\n'; //afisez noile stari finale
    for(int i=1; i<=loc; i++)
    {
        cout<<"{ " ;
        for(int j=1; j<=sf[i].n; j++)
            cout<<sf[i].v[j]<<' ';
        cout<<"} ";
    }
    return 0;
}
