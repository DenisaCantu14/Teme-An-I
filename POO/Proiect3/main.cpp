#include <bits/stdc++.h>
using namespace std;
#include "Examen.h"
#include "Partial.h"
#include "Final.h"
#include "CatalogIndividual.h"
#include "Quiz.h"

void afisare_meniu()
{
    cout << "MENIU\n";
    cout << "1. Introduceti o pagina de catalog noua.\n";
    cout << "2. Lista restantieri\n";
    cout << "3. Lista cu studentii care au dat cel putin 2 quiz-uri.\n";
    cout << "4. Adauga o fisa de observatii.\n";
    cout << "5. Afiseaza catalog.\n";
    cout << "6. Exit\n";

}

int main()
{
    vector<CatalogIndividual<Examen>*> catalog;
    do
    {
        afisare_meniu();
        int op;
        cin >> op;
        if(op == 1)
        {
            CatalogIndividual<Examen>* temp = new CatalogIndividual<Examen>;
            cin >> *temp;
            catalog.push_back(temp);
        }
        else if(op == 2)
        {
            unordered_map<string, string> restantieri;
            vector<string> v;
            for(int i=0; i<catalog.size(); i++)
            {
                v=catalog[i]->restanta();
                for(int j=0; j< v.size(); j++)
                {
                    restantieri[v[j]].append(catalog[i]->getnume());
                    restantieri[v[j]].append(", ");
                }
            }
            cout<<"Restante:\n";
            for (auto const& pair: restantieri)
            {
                cout << pair.first << ": " << pair.second<< "\n";
            }
        }
        else if(op == 3)
        {
            Quiz *q=new Quiz;
            for(int i=0; i<catalog.size(); i++)
            {
                if(catalog[i]->get_nr_quiz()>=2)
                {
                    q->adauga(catalog[i]->getnume());
                    q->adauga(", ");
                }
            }
            cout<<*q<<'\n';
        }
        else if(op == 4)
        {
            cout << "Introduceti pagina: ";
            int pag;
            string fisa;
            cin >> pag;
            cout << "Introduceti fisa de observatii: ";
            getline(cin, fisa);
            getline(cin, fisa);
            *catalog[pag]+=fisa;
            cout<<*catalog[pag];
        }
        else if(op == 5)
        {
             for(int i=0; i<catalog.size(); i++)
                cout<<*catalog[i];
        }
        else if(op == 6)
        {
            break;
        }
        else
        {
            cout << "Introduceti o optiune valida!\n";
            continue;
        }
    }
    while(true);
    return 0;
}
