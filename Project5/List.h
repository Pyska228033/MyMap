#ifndef List_H
#define List_H

#include <iostream>
#include "Nudl.h"
#include "Data.h"
#include <assert.h>

using namespace std;

template <class D, class T>
class List
{
private:
    Nudl<D,T>* ne1 = new Nudl<D, T>;

public:

    List();
    int GetLength();
    Data<D,T> GetFirst();
    Data<D,T> GetLast();
    Data<D,T> Get(int n);
    void Append(Data<D,T> item);
    void Prepend(Data<D,T> item);
    void InsertAt(Data<D,T> item, int n);
    void Delit(D item);
    T find(D item);
    void printList();

};

template <class D, class T>
List<D,T> ::List()
{
    ne1 = NULL;
}

template <class D, class T>
int List<D, T> ::GetLength()
{
    Nudl<D, T>* ne = new Nudl<D ,T>;
    ne = ne1;

    int n = 0;

    while (ne != NULL)
    {
        n++;
        ne = ne->next;
    }

    return n;
}

template <class D, class T>
Data<D,T> List<D ,T> ::GetFirst()
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;
    int n = 0;

    while (ne != NULL)
    {
        ne = ne->next;
        n++;
    }

    if ((n == 1 && (ne->data) == 1357))
        assert(0);

    Data<D,T> k;

    k = (ne1->data);

    return k;
}

template <class D, class T>
Data<D,T> List<D, T> ::GetLast()
{
    Nudl<D, T>* ne = new Nudl<D, T>;
    ne = ne1;
    Nudl<D, T>* ne2 = new Nudl<D, T>;
    ne2 = ne1;

    int n = 0;

    while (ne != NULL)
    {
        ne = ne->next;
        n++;
    }

    if ((n == 1 && (ne->data) == 1357))
        assert(0);

    Data<D,T> k;

    while (ne2->next != NULL)
    {
        ne2 = ne2->next;
    }

    k = ne2->data;

    return k;
}

template <class D,class T>
Data<D, T> List<D,T> ::Get(int n)
{

    Data<D, T> k;

    Nudl<D,T>* ne = new Nudl<D,T>;
    ne = ne1;

    for (int i = 0; i < n; i++)
    {
        ne = ne->next;
    }

    k = ne->data;

    return k;
}



template <class D, class T>
void List<D ,T> ::Append(Data<D,T> item)
{

    if (ne1 == NULL)
    {
        ne1->data = item;
        ne1->next = NULL;
    }

    else if (ne1 != NULL)
    {
        Nudl<D, T>* ne = new Nudl<D, T>;
        Nudl<D, T>* ne2 = new Nudl<D, T>;

        ne = ne1;

        ne2->data = item;
        ne2->next = NULL;

        while (ne->next != NULL)
        {
            ne = ne->next;
        }

        ne->next = ne2;
    }

}

template <class D, class T>
void List<D, T> ::Prepend(Data<D,T> item)
{
    
    Nudl<D, T>* ne2 = new Nudl<D, T>;

    ne2->data = item;
    ne2->next = ne1;

    ne1 = ne2;
    
}

template <class D, class T>
void List<D, T> ::InsertAt(Data<D,T> item, int n)
{

    Nudl<D,T>* ne = new Nudl<D,T>;
    ne = ne1;

    for (int i = 0; i < n; i++)
    {
        ne = ne->next;
    }

    ne->data = item;
}


template<class D, class T>
void List<D, T> ::Delit(D item)
{

    if (ne1->data.key == item)
    {
        Nudl<D, T>* ne = new Nudl<D, T>;
        ne = ne1;
        ne1 = ne1->next;
        delete(ne);
    }

    else if (ne1->data.key != item)
    {
        Nudl<D, T>* ne = new Nudl<D, T>;
        ne = ne1;

        while (ne->next->data.key != item)
        {
            ne = ne->next;
            if (ne->next == NULL)
            {
                cout << endl << "elementa net" << endl;
                break;
            }
        
        }
       
        Nudl<D, T>* ne2 = new Nudl<D, T>;
        ne2 = ne->next;

        ne->next = ne2->next;
        delete(ne2);
        
    }  
}

template < class D, class T>
T List<D, T> ::find(D item)
{
    Nudl<D, T>* ne = new Nudl<D, T>;
    ne = ne1;


    while (ne->data.key != item)
    {
        ne = ne->next;
        if (ne == NULL)
        {
            cout << "elementa net" << endl;
            return 0;
            break;
        }
    }

    if(ne != NULL)
        return ne->data.DATA;
}


template <class D, class T>
void List<D, T> ::printList()
{
    Nudl<D, T>* ne = new Nudl<D, T>;
    ne = ne1;

    while (ne != NULL)
    {
        cout << ne->data.key << " = "<< ne ->data.DATA<< "  -->  ";
        ne = ne->next;
    }
    cout << endl;
}

#endif /*List_H*/

