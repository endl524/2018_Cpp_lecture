#include <iostream>
using namespace std;

#define MIN_NUM 1
#define MAX_NUM 100

void main()
{
	int ComNumber; // 컴퓨터가 추측한 숫자
	int count = 0; // 컴퓨터의 추측 횟수
	int min = MIN_NUM, max = MAX_NUM; // 최솟값, 최댓값

	int inputNum = 0; // 1,2,3 숫자 입력


	while (count < 7 && inputNum != 1)
	{
		++count; // 추측 횟수 증가
		
		ComNumber = (min + max) / 2; // 중간값을 계산한다.

		cout << "컴퓨터의 추측: " << ComNumber << " (" << count << "번째 추측)" << endl;
		
		inputNum = 0; // 입력값 초기화
		while (inputNum < 1 || inputNum > 3)
		{
			cout << "'" << ComNumber << "' 이(가) 맞다면 '1'을, 보다 더 높은 숫자라면 '2'를, 보다 더 낮은 숫자라면 '3'을 입력해주세요." << endl << "=> ";
			cin >> inputNum; // 입력

			if (inputNum == 1)
				cout << endl << ComNumber << "이(가) 정답이군요!" << endl;				
			else if (inputNum == 2)
				min = ComNumber + 1; // 최솟값 설정
			else if (inputNum == 3)
				max = ComNumber - 1; // 최댓값 설정
			else
				cout << "다시 입력해주세요." << endl << endl;
		}
		cout << endl;
	}

	if (inputNum != 1)
		cout << "숫자 맞추기에 실패했습니다.." << endl << endl;
}