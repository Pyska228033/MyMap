#include "Map.h"
#include <chrono>
#include <ctime>

#include "Menu.h"

using namespace std;

int main()
{

	cout << "1. int int\n2. string int\n3. string string" << endl;
	int detector1;
	cin >> detector1;
	if (detector1 == 1)
	{
		menu<int, int>();
	}

	if(detector1 == 2)
	{
		menu<int>();
	}

	if (detector1 == 3)
	{
		menu();
	}



	/*int n;
	cout << "Enter the number of elements:" << endl;
	cin >> n;
	Data<int, int>* z = new Data<int,int>[n];
	for (int i = 0; i < n; i++)
	{
		z[i].key = i;
		z[i].DATA = i * 10;
	}

	
	auto begin = chrono::steady_clock::now();
	Map<int, int> b(10);
	for (int i = 0; i < n; i++)
		b.insert(z[i]);
	Data<int, int>a;
	a.key = 99;
	a.DATA = 999;
	b.insert(a);

	auto end = chrono::steady_clock::now();

	auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
	cout << "Map: " << elapsed_ms.count() << " ms\n";

	b.print();*/
	
	return 0; 
}