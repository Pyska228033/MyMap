#ifndef Menu_H
#define Menu_H

#include "Map.h"
#include <chrono>
#include <ctime>
#include <Fstream>

using namespace std;

template<class D, class T>
void menu()
{
	srand(time(0));
	cout << "How many elements do you want?" << endl;
	int n;
	cin >> n;
	Data<D, T>* a = new Data<D,T>[n];
	for (int i = 0; i < n; i++)
	{
		a[i].key = rand();
		a[i].DATA = rand();
	}

	Map<D, T> map(n / 8);
	for (int i = 0; i < n; i++)
	{
		map.insert(a[i]);
	}

	int detector2 = 5;

	while (detector2 != 0)
	{
		cout << "What do you want?" << endl;
		cout << "0. end" << endl;
		cout << "1. print" << endl;
		cout << "2. find" << endl;
		cout << "3. delet" << endl;
		cout << "4. incert" << endl;

		cin >> detector2;

		if (detector2 == 1)
		{
			cout << "Your table:" << endl;
			map.print();
		}

		if (detector2 == 2)
		{
			int key;
			cout << "Enter key:" << endl;
			cin >> key;
			Data<D, T> y = map.Find(key);
			cout << y.key << " = " << y.DATA << endl;

		}

		if (detector2 == 3)
		{
			int key;
			cout << "Enter key:" << endl;
			cin >> key;
			map.delit(key);
		}

		if (detector2 == 4)
		{
			Data<D, T> y;
			cout << "Enter key:" << endl;
			cin >> y.key;
			cout << "Enter DATA:" << endl;
			cin >> y.DATA;
			map.insert(y);
		}
	}
}


template<class T>
void menu()
{
	srand(time(0));
	cout << "How many elements do you want?" << endl;
	int n;
	cin >> n;

	char mass[44] = "a'b51cd>e1f;6ghij.klm<19no3pq5rs /tu0vwx8yz";
	string arr[10000];
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = "          ";
	}
	for (int h = 0; h < 10000; h++)
	{
		for (int g = 0; g < arr[h].length(); g++)
		{
			int random = rand() % (42);
			arr[h][g] = mass[random];
		}
	}


	Data<string, T>* a = new Data<string, T>[n];
	for (int i = 0; i < n; i++)
	{
		int random = rand() % (10000);
		a[i].key = arr[random];
		
		a[i].DATA = rand();
	}

	Map<string, T> map(n / 8);
	for (int i = 0; i < n; i++)
	{
		map.insert(a[i]);
	}

	int detector2 = 5;

	while (detector2 != 0)
	{
		cout << "What do you want?" << endl;
		cout << "0. end" << endl;
		cout << "1. print" << endl;
		cout << "2. find" << endl;
		cout << "3. delet" << endl;
		cout << "4. incert" << endl;

		cin >> detector2;

		if (detector2 == 1)
		{
			cout << "Your table:" << endl;
			map.print();
		}

		if (detector2 == 2)
		{
			string key;
			cout << "Enter key:" << endl;
			cin >> key;
			Data<string, T> y = map.Find(key);
			cout << y.key << " = " << y.DATA << endl;

		}

		if (detector2 == 3)
		{
			string key;
			cout << "Enter key:" << endl;
			cin >> key;
			map.delit(key);
		}

		if (detector2 == 4)
		{
			Data<string, T> y;
			cout << "Enter key:" << endl;
			cin >> y.key;
			cout << "Enter DATA:" << endl;
			cin >> y.DATA;
			map.insert(y);
		}
	}
}


void menu()
{
	srand(time(0));
	cout << "How many elements do you want?" << endl;
	int n;
	cin >> n;

	
	ifstream in("Names.txt");

	string arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = "                ";
	}
	for (int h = 0; h < 100; h++)
	{
		getline(in, arr[h]);
	}

	ifstream in1("Groops.txt");

	string arr1[100];
	for (int i = 0; i < 100; i++)
	{
		arr1[i] = "           ";
	}
	for (int h = 0; h < 100; h++)
	{
		getline(in1, arr1[h]);
	}


	Data<string, string>* a = new Data<string, string>[n];
	for (int i = 0; i < n; i++)
	{
		int random = rand() % (99);
		a[i].key = arr[random];

		int random1 = rand() % (99);
		a[i].DATA = arr1[random1];;
	}

	Map<string, string> map(n / 8);
	for (int i = 0; i < n; i++)
	{
		map.insert(a[i]);
	}

	int detector2 = 5;

	while (detector2 != 0)
	{
		cout << "What do you want?" << endl;
		cout << "0. end" << endl;
		cout << "1. print" << endl;
		cout << "2. find" << endl;
		cout << "3. delet" << endl;
		cout << "4. incert" << endl;

		cin >> detector2;

		if (detector2 == 1)
		{
			cout << "Your table:" << endl;
			map.print();
		}

		if (detector2 == 2)
		{
			string key;
			cout << "Enter key:" << endl;
			cin >> key;
			Data<string, string> y = map.Find(key);
			cout << y.key << " = " << y.DATA << endl;

		}

		if (detector2 == 3)
		{
			string key;
			cout << "Enter key:" << endl;
			cin >> key;
			map.delit(key);
		}

		if (detector2 == 4)
		{
			Data<string, string> y;
			cout << "Enter key:" << endl;
			cin >> y.key;
			cout << "Enter DATA:" << endl;
			cin >> y.DATA;
			map.insert(y);
		}
	}
}


#endif // !Menu_H
