#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> v;

	int size;
	cout << "������ ������ ������ �Է��ϼ���: ";
	cin >> size;

	for (int i = 0; i < size; ++i)
	{
		int data;
		cout << "������ ������ �Է��ϼ���: ";
		cin >> data;
		v.push_back(data);
	}

	int max = *v.begin(), min = *v.begin();

	for (auto& data : v)
	{
		if (data > max)
			max = data;
		if (data < min)
			min = data;
	}

	cout << "�ִ�: " << max << ", �ּڰ�: " << min << endl;

	system("pause");
}