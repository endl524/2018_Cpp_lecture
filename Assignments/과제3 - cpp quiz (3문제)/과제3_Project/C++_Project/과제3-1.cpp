#include <iostream>
using namespace std;

void main()
{
	int i; // i�� int�� ������ ����ϰڴٰ� ����.
	float f; // f�� float�� ������ ����ϰڴٰ� ����.

	auto at_i = 10; // at_i�� int�� ���� 10���� �ʱ�ȭ �����μ�
					// at_i�� ������Ÿ���� int������ �߷еȴ�.

	auto at_f = 10.0f; // ���������� at_f�� float�� ���� 10.0f�� �ʱ�ȭ �����μ�
						// at_f�� ������Ÿ���� float������ �߷еȴ�.

	cout << "at_i�� Ÿ��: " << typeid(at_i).name() << endl;
	cout << "at_f�� Ÿ��: " << typeid(at_f).name() << endl;
}