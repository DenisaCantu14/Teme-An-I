#include <bits/stdc++.h>
using namespace std;
ifstream f("abce.in");
ofstream g("abce.out");
int t=3; //nr minim de keys
class Node
{
public:
    int *keys;
    Node **link;
    int nr;
    bool leaf;

    Node(bool l)
    {
        leaf=l;
        keys = new int[2*t-1];
        link = new Node *[2*t];
        nr = 0;
    }
    void insertNonFull(int val);
    void split(int i, Node *a);
    Node* Search(int k);
    void Remove(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void succ(int val);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    void traverse(int a, int b);

}*root=NULL;

void Insert(int val)
{
    if (root == NULL)
    {
        root = new Node(true);
        root->keys[0] = val;
        root->nr = 1;
    }
    else
    {
        if (root->nr == 2*t-1) //daca nu mai sunt locuri
        {
            Node *s = new Node(false);

            s->link[0] = root;   //root devine copil pt s
            s->split(0, root);  //sparg nodul in 2
            int i = 0;
            if (s->keys[0] < val)
                i++;
            s->link[i]->insertNonFull(val); // inserez valoarea
            root = s;
        }
        else
            root->insertNonFull(val);
    }
}

void Node::insertNonFull(int val)
{
    int i = nr-1;
    if (leaf == true) //daca e frunza
    {
        while (i >= 0 && keys[i] > val)
        {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = val;
        nr = nr+1;
    }
    else
    {
        while (i >= 0 && keys[i] > val)
            i--;
        if (link[i+1]->nr == 2*t-1)
        {
            split(i+1, link[i+1]);
            if (keys[i+1] < val)
                i++;
        }
        link[i+1]->insertNonFull(val);
    }
}


void Node::split(int i, Node *a)
{
    Node *b = new Node(a->leaf); //creez un nou nod
    b->nr = t - 1; // care va avea nr de keys cat jumatete de nr nodului caruia i se face split
    for (int j = 0; j < t-1; j++)
        b->keys[j] = a->keys[j+t];  // copiez in b valorile
    if (a->leaf == false) //daca a nu e frunza copiez si copii nodului a in b
    {
        for (int j = 0; j < t; j++)
            b->link[j] = a->link[j+t];
    }
    a->nr = t - 1; //scad nr de keys pt ca i am transferat in b
    for (int j = nr; j >= i+1; j--)
        link[j+1] = link[j]; //fac loc pt unnou copil
    link[i+1] = b; //inserez copilul b

    for (int j = nr-1; j >= i; j--)
        keys[j+1] = keys[j]; //fac loc pt o noua valoare/key

    keys[i] = a->keys[t-1]; //inserez valoarea din mijloc

    nr = nr + 1; //cresc nr de keys
}

Node* Node::Search(int val)//cauta o valoare
{
    if(root==NULL)
        return NULL;
    int i = 0;
    while (i < nr && val > keys[i])
        i++;
    if (keys[i] == val)
        return this;
    if (leaf == true)
        return NULL;
    return link[i]->Search(val);
}


void Node::Remove(int val)
{
    int poz=0;
    while (poz<nr && keys[poz] < val)
        ++poz; //caut valoarea
    if (poz < nr && keys[poz] == val) //daca am gasit o
    {
        if (leaf)
            removeFromLeaf(poz);
        else
            removeFromNonLeaf(poz);
    }
    else
    {
        bool flag;
        if(poz==nr)
            flag = true;
        else
            flag  = false;

        if (link[poz]->nr < t) //daca nodul nu are minim t copii
            fill(poz);
        if (flag && poz > nr) //sterg valoarea din nod, in functie de copilul cu care s a facut merge
            link[poz-1]->Remove(val);
        else
            link[poz]->Remove(val);
    }
    return;
}
void Node::removeFromLeaf (int poz)
{
    for (int i=poz+1; i<nr; ++i)
        keys[i-1] = keys[i];
    nr--;
    return;
}
void Node::removeFromNonLeaf(int poz)
{
    int k = keys[poz];
    if (link[poz]->nr >= t)
    {
        int pred = getPred(poz);
        keys[poz] = pred;
        link[poz]->Remove(pred);
    }
    else if  (link[poz+1]->nr >= t)
    {
        int succ = getSucc(poz);
        keys[poz] = succ;
        link[poz+1]->Remove(succ);
    }
    else
    {
        merge(poz);
        link[poz]->Remove(k);
    }
    return;
}
int Node::getPred(int poz)
{
    Node *p=link[poz];
    while (!p->leaf)
        p = p->link[p->nr];
    return p->keys[p->nr-1];
}

int Node::getSucc(int poz)
{
    Node *p = link[poz+1];
    while (!p->leaf)
        p = p->link[0];
    return p->keys[0];
}

void Node::fill(int poz)
{
    if (poz!=0 && link[poz-1]->nr>=t)
        borrowFromPrev(poz);

    else if (poz!=nr && link[poz+1]->nr>=t)
        borrowFromNext(poz);
    else
    {
        if (poz != nr)
            merge(poz);
        else
            merge(poz-1);
    }
    return;
}
void Node::borrowFromPrev(int poz)
{

    Node *child=link[poz];
    Node *sibling=link[poz-1];

    for (int i=child->nr-1; i>=0; --i)
        child->keys[i+1] = child->keys[i];

    if (!child->leaf)
    {
        for(int i=child->nr; i>=0; --i)
            child->link[i+1] = child->link[i];
    }

    child->keys[0] = keys[poz-1];
    if(!child->leaf)
        child->link[0] = sibling->link[sibling->nr];

    keys[poz-1] = sibling->keys[sibling->nr-1];

    child->nr += 1;
    sibling->nr -= 1;
    return;
}

void Node::borrowFromNext(int poz)
{

    Node *child=link[poz];
    Node *sibling=link[poz+1];

    child->keys[(child->nr)] = keys[poz];
    if (!(child->leaf))
        child->link[(child->nr)+1] = sibling->link[0];

    keys[poz] = sibling->keys[0];

    for (int i=1; i<sibling->nr; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    if (!sibling->leaf)
    {
        for(int i=1; i<=sibling->nr; ++i)
            sibling->link[i-1] = sibling->link[i];
    }

    child->nr += 1;
    sibling->nr -= 1;

    return;
}
void Node::merge(int poz)
{
    Node *child = link[poz];
    Node *sibling = link[poz+1];
    child->keys[t-1] = keys[poz];
    for (int i=0; i<sibling->nr; ++i)
        child->keys[i+t] = sibling->keys[i];
    if (!child->leaf)
    {
        for(int i=0; i<=sibling->nr; ++i)
            child->link[i+t] = sibling->link[i];
    }
    for (int i=poz+1; i<nr; ++i)
        keys[i-1] = keys[i];

    for (int i=poz+2; i<=nr; ++i)
        link[i-1] = link[i];

    child->nr += sibling->nr+1;
    nr--;
    delete(sibling);
    return;
}

void Remove(int k)
{
    root->Remove(k);
    if (root->nr==0)
    {
        Node *tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->link[0];

        delete tmp;
    }
    return;
}
void Node::traverse(int a, int b)
{
    int i;
    for (i = 0; i < nr; i++)
    {
        if (leaf == false)
            link[i]->traverse(a, b);
        if(keys[i]>=a && keys[i]<=b)
            g <<keys[i]<<" ";
    }
    if (leaf == false)
        link[i]->traverse(a, b);

}
void succ(Node *a, int val)
{
    int i = 0;
    while (i < a->nr && val > a->keys[i])
        i++;
    if(a->keys[i]==val)
        g<<val<<'\n';
    else

        if(a->leaf)
            g<<a->keys[i]<<'\n';

        else
        {
            Node *p = a->link[i];
            succ(p, val);

        }
}
void pred(Node* a, int val)
{
    int i = 0;
    while (i < a->nr && val > a->keys[i])
        i++;
    if(a->keys[i]==val)
        g<<val<<'\n';
    else

        if(a->leaf)
        {
            g<<a->keys[i-1]<<'\n';

        }

        else
        {
            Node *p = a->link[i];
            if(p->keys[0]>val)
                g<<a->keys[i-1]<<'\n';
            else
                pred(p, val);
        }

}

int main()
{
    int q, x, y, z;
    f>>q;
    for(int i=1; i<=q; i++)
    {
        f>>x>>y;
        switch (x)
        {
        case 1:
        {
            Insert(y);
            break;
        }
        case 2:
        {
            if(root->Search(y)!=NULL)
                Remove(y);
            break;
        }
        case 3:
        {
            if(root->Search(y)!=NULL)
                g<<1<<'\n';
            else
                g<<0<<'\n';
            break;
        }
        case 4:
        {
            pred(root, y);
            break;
        }
        case 5:
        {
            succ(root, y);
            break;
        }
        case 6:
        {
            f>>z;
            root->traverse(y, z);
            g<<'\n';
            break;
        }
        }
    }

    return 0;
}
