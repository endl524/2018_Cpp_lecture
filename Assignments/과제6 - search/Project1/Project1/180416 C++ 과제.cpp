#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> v;

	int size;
	cout << "삽입할 정수의 개수를 입력하세요: ";
	cin >> size;

	for (int i = 0; i < size; ++i)
	{
		int data;
		cout << "삽입할 정수를 입력하세요: ";
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

	cout << "최댓값: " << max << ", 최솟값: " << min << endl;

	system("pause");
}