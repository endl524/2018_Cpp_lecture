#include <iostream>
using namespace std;

#define MIN_NUM 1
#define MAX_NUM 100

void main()
{
	int ComNumber; // ��ǻ�Ͱ� ������ ����
	int count = 0; // ��ǻ���� ���� Ƚ��
	int min = MIN_NUM, max = MAX_NUM; // �ּڰ�, �ִ�

	int inputNum = 0; // 1,2,3 ���� �Է�


	while (count < 7 && inputNum != 1)
	{
		++count; // ���� Ƚ�� ����
		
		ComNumber = (min + max) / 2; // �߰����� ����Ѵ�.

		cout << "��ǻ���� ����: " << ComNumber << " (" << count << "��° ����)" << endl;
		
		inputNum = 0; // �Է°� �ʱ�ȭ
		while (inputNum < 1 || inputNum > 3)
		{
			cout << "'" << ComNumber << "' ��(��) �´ٸ� '1'��, ���� �� ���� ���ڶ�� '2'��, ���� �� ���� ���ڶ�� '3'�� �Է����ּ���." << endl << "=> ";
			cin >> inputNum; // �Է�

			if (inputNum == 1)
				cout << endl << ComNumber << "��(��) �����̱���!" << endl;				
			else if (inputNum == 2)
				min = ComNumber + 1; // �ּڰ� ����
			else if (inputNum == 3)
				max = ComNumber - 1; // �ִ� ����
			else
				cout << "�ٽ� �Է����ּ���." << endl << endl;
		}
		cout << endl;
	}

	if (inputNum != 1)
		cout << "���� ���߱⿡ �����߽��ϴ�.." << endl << endl;
}