#include <iostream>
#include <algorithm>
using namespace std;

void main()
{
	int intaList[5] = { 30,20,10,50,40 };

	sort(intaList, intaList+5);

	cout << "intaList: ";

	for (int i : intaList)
	{
		cout << i << " ";
	}

	cout << endl;
}