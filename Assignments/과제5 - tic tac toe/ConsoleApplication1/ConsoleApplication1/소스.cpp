#include <iostream>
using namespace std;

// 보드의 좌표 구조체
struct Coordinate 
{
	int x;
	int y;
};

Coordinate Think(char(*b)[3]);
bool CheckBoard(char (*b)[3]);
void DrawBoard(char (*b)[3]);


void main()
{
	char board[3][3];
	Coordinate coord;
	int k = 0, i;
	bool is_GameOver = false;

	// 보드 초기화
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			board[x][y] = ' ';
		}
	}

	while (k < 9 && !is_GameOver)
	{
		// 좌표값 초기화
		coord.x = -2;
		coord.y = -2;

		// 내 턴일 경우
		if (k % 2 == 0)
		{
			while (coord.x < 0 || coord.x > 2 || coord.y < 0 || coord.y > 2 || board[coord.x][coord.y] != ' ')
			{
				cout << "Your Turn! (x,y) : ";
				cin >> coord.x >> coord.y;
			}
		}

		// 컴퓨터 턴일 경우
		else
		{
			coord = Think(board);
			cout << "Computer's Turn! (x,y) : " << coord.x << " " << coord.y << endl;
		}

		// 보드에 그려질 말 선택
		board[coord.x][coord.y] = (k % 2 == 0) ? 'X' : 'O';

		// 보드 새로 그리기
		DrawBoard(board);

		// 보드 체크하기
		is_GameOver = CheckBoard(board);

		++k; // 횟수 증가
	}
	--k;
	if (k >= 9) cout << "Draw!" << endl;
	cout << endl;

}

Coordinate Think(char (*b)[3])
{
	// 새 좌표값 변수 생성
	Coordinate newCoord;
	newCoord.x = -1;
	newCoord.y = -1;

	// 0 행 - 경우의 수
	if (b[0][0] != 'O')
	{
		if (((b[0][1] == 'X') && (b[0][2] == 'X')) || ((b[1][0] == 'X') && (b[2][0] == 'X')) || ((b[1][1] == 'X') && (b[2][2] == 'X')))
		{
			newCoord.x = 0;
			newCoord.y = 0;
		}
	}

	if (b[0][1] != 'O')
	{
		if (((b[0][0] == 'X') && (b[0][2] == 'X')) || ((b[1][1] == 'X') && (b[2][1] == 'X')))
		{
			newCoord.x = 0;
			newCoord.y = 1;
		}
	}

	if (b[0][2] != 'O')
	{
		if (((b[0][0] == 'X') && (b[0][1] == 'X')) || ((b[1][2] == 'X') && (b[2][2] == 'X')) || ((b[1][1] == 'X') && (b[2][0] == 'X')))
		{
			newCoord.x = 0;
			newCoord.y = 2;
		}
	}


	// 1 행 - 경우의 수
	if (b[1][0] != 'O')
	{
		if (((b[0][0] == 'X') && (b[2][0] == 'X')) || ((b[1][1] == 'X') && (b[1][2] == 'X')))
		{
			newCoord.x = 1;
			newCoord.y = 0;
		}
	}

	if (b[1][1] != 'O')
	{
		if (((b[0][0] == 'X') && (b[2][2] == 'X')) || ((b[0][1] == 'X') && (b[2][1] == 'X')) || ((b[0][2] == 'X') && (b[2][0] == 'X')) || ((b[1][0] == 'X') && (b[1][2] == 'X')))
		{
			newCoord.x = 1;
			newCoord.y = 1;
		}
	}

	if (b[1][2] != 'O')
	{
		if (((b[0][2] == 'X') && (b[2][2] == 'X')) || ((b[1][0] == 'X') && (b[1][1] == 'X')))
		{
			newCoord.x = 1;
			newCoord.y = 2;
		}
	}


	// 2 행 - 경우의 수
	if (b[2][0] != 'O')
	{
		if (((b[0][0] == 'X') && (b[1][0] == 'X')) || ((b[0][2] == 'X') && (b[1][1] == 'X')) || ((b[2][1] == 'X') && (b[2][2] == 'X')))
		{
			newCoord.x = 2;
			newCoord.y = 0;
		}
	}

	if (b[2][1] != 'O')
	{
		if (((b[2][0] == 'X') && (b[2][2] == 'X')) || ((b[0][1] == 'X') && (b[1][1] == 'X')))
		{
			newCoord.x = 2;
			newCoord.y = 1;
		}
	}

	if (b[2][2] != 'O')
	{
		if (((b[0][2] == 'X') && (b[1][2] == 'X')) || ((b[0][0] == 'X') && (b[1][1] == 'X')) || ((b[2][0] == 'X') && (b[2][1] == 'X')))
		{
			newCoord.x = 2;
			newCoord.y = 2;
		}
	}


	// 경우의 수가 없다면 랜덤
	if (newCoord.x == -1 && newCoord.y == -1)
	{
		while (b[newCoord.x][newCoord.y] != ' ')
		{
			newCoord.x = rand() % 3;
			newCoord.y = rand() % 3;
		}
	}

	// 좌표값 반환
	return newCoord;
}

bool CheckBoard(char (*b)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		// 가로줄
		if (b[i][0] != ' ' && (b[i][0] == b[i][1]) && (b[i][1] == b[0][2]))
		{
			if (b[i][0] == 'X')
				cout << "당신이 이겼습니다!" << endl;
			else
				cout << "컴퓨터가 이겼습니다!" << endl;

			return true;
		}

		// 세로줄
		if (b[0][i] != ' ' && (b[0][i] == b[1][i]) && (b[1][i] == b[2][i]))
		{
			if (b[0][i] == 'X')
				cout << "당신이 이겼습니다!" << endl;
			else
				cout << "컴퓨터가 이겼습니다!" << endl;

			return true;
		}
	}

	// 대각 1
	if (b[1][1] != ' ')
	{
		if ((b[0][0] == b[1][1]) && (b[1][1] == b[2][2]))
		{
			if (b[1][1] == 'X')
				cout << "당신이 이겼습니다!" << endl;
			else
				cout << "컴퓨터가 이겼습니다!" << endl;

			return true;
		}

		// 대각 2
		if ((b[0][2] == b[1][1]) && (b[1][1] == b[2][0]))
		{
			if (b[1][1] == 'X')
				cout << "당신이 이겼습니다!" << endl;
			else
				cout << "컴퓨터가 이겼습니다!" << endl;

			return true;
		}
	}

	return false;
}

void DrawBoard(char (*b)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		cout << "---|---|---" << endl;
		cout << " " << b[i][0] << " | " << b[i][1] << " | " << b[i][2] << endl;
	}
	cout << "---|---|---" << endl << endl;
}