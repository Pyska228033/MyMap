#ifndef Hash_H
#define Hash_H

#include <string>
#include <type_traits>
#include "List.h"
#include "Data.h"


template<class D>
int HashFun(D key, int size)
{
	return (key % size);
}

template<>
int HashFun(string key, int size)
{
	int n = 0;
	for (int i = 0; i < key.length(); i++)
	{
		n = n + key[i];
	}

	return (n % size);
}


template <class D, class T>
class Hash
{
private:
	List<D, T>* list;
	int capacity;

public:

	Hash();
	Hash(int V);
	void insert(Data<D, T>& a);
	void delit(D item);
	void print();
	Data<D,T> Find(D item);
	friend int HashFun(D key);

	int chekprime(int n)
	{
		int i = 0;
		if (n == 1 || n == 0)
		{
			return 0;
		}

		for (i = 2; i < n / 2; i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}

	int getprime(int n)
	{
		if (n % 2 == 0)
		{
			n++;
		}

		while (!chekprime(n))
		{
			n = n + 2;
		}
		return n;
	}


};


template <class D, class T>
Hash<D, T>::Hash()
{

}

template <class D, class T>
Hash<D, T>::Hash(int V)
{
	capacity  = getprime(V);

	list = new List<D, T>[capacity]();
}

template <class D, class T>
void Hash<D, T>::insert(Data<D, T>& a)
{
	int y = 0;
	for (int j = 0; j < this->capacity; j++)
	{
		y = y + this->list[j].GetLength();
	}

	if (y / capacity > 3)
	{
		int size = this->capacity * 3;
		List<D,T>* x =  new List<D, T>[size]();
		
		for (int j = 0; j < this->capacity; j++)
		{
			
			int sizelist = this->list[j].GetLength();
			for (int k = 0; k < sizelist; k++)
			{
				int index1;
				index1 = HashFun(this->list[j].Get(k).key,size);
				x[index1].Prepend(this->list[j].Get(k));
			}
		}
		this->capacity = size;
		this->list = x;
		
	}

	int index;
		index = HashFun(a.key,capacity);
	list[index].Prepend(a);
}

template <class D, class T>
void Hash<D, T>::delit(D item)
{
	int index = HashFun(item,capacity);
	list[index].Delit(item);
}

template<class D, class T>
Data<D,T> Hash<D, T>::Find(D item)
{
	int index = HashFun(item, capacity);
	T r =list[index].find(item);

	Data<D, T> a;
	a.key = item;
	a.DATA = r;
	return a;
}

template <class D, class T>
void Hash<D, T>::print()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << endl;

		cout << "¹" << i << "-->";
		list[i].printList();
	}

	cout << capacity<<endl;
}


#endif // !Hash_H