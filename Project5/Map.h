#ifndef Basa_H
#define Basa_H

#include "Hash.h"

template <class D, class T>
class Map
{
private:
	Hash<D, T>* basa = new Hash<D ,T>;

public:

	Data<D,T> kash[5];
	Map(int V);
	void insert(Data<D, T>& a);
	void delit(D item);
	Data<D, T> Find(D item);
	void print();
};


template<class D, class T>
Map<D, T>::Map(int V)
{
	*basa = Hash<D, T>(V);
}

template <class D, class T>
void Map<D, T>::insert(Data<D, T>& a)
{
	basa->insert(a);
}

template <class D, class T>
void Map<D, T>::delit(D item)
{
	basa->delit(item);
}

template< class D, class T>
Data<D, T> Map<D, T> ::Find(D item)
{

	for (int i = 0; i < 5; i++)
	{
		if (kash[i].key == item)
		{
			if (i > 0)
			{
				Data<D, T> k = kash[i - 1];
				kash[i - 1] = kash[i];
				kash[i] = k;
				return kash[i - 1];
			}
			else
				return kash[i];
		}	
	}

	Data<D, T> a = 	basa->Find(item);

	Data<D, T> byfer[6];
	byfer[0] = a;

	for (int i = 0; i < 5; i++)
		byfer[i + 1] = kash[i];
	for (int i = 0; i < 5; i++)
		kash[i] = byfer[i];
	
	return a;
}

template < class D, class T>
void Map<D, T> ::print()
{
	basa->print();
}

#endif // !Basa_H
