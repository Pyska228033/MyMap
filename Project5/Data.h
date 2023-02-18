#ifndef Data_H
#define Data_H

#include <iostream>
using namespace std;

template <class D, class T>
struct Data
{
	D key;
	T DATA;

	Data& operator = (Data<D, T> b)
	{
		this->DATA = b.DATA;
		this->key = b.key;
		return *this;
	}
	bool operator == (Data<D, T> b)
	{
		if (this->key == b.key && this->DATA == b.DATA)
			return 1;
		else
			return 0;
	}
};


#endif // !Data_H
