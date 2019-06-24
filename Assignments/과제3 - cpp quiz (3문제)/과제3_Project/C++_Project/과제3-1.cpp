#include <iostream>
using namespace std;

void main()
{
	int i; // i를 int형 변수로 사용하겠다고 선언.
	float f; // f를 float형 변수로 사용하겠다고 선언.

	auto at_i = 10; // at_i를 int형 값인 10으로 초기화 함으로서
					// at_i는 데이터타입이 int형으로 추론된다.

	auto at_f = 10.0f; // 마찬가지로 at_f를 float형 값인 10.0f로 초기화 함으로서
						// at_f는 데이터타입이 float형으로 추론된다.

	cout << "at_i의 타입: " << typeid(at_i).name() << endl;
	cout << "at_f의 타입: " << typeid(at_f).name() << endl;
}