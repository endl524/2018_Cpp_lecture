#include <iostream>
using namespace std;

// ������ ��ǥ ����ü
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

	// ���� �ʱ�ȭ
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			board[x][y] = ' ';
		}
	}

	while (k < 9 && !is_GameOver)
	{
		// ��ǥ�� �ʱ�ȭ
		coord.x = -2;
		coord.y = -2;

		// �� ���� ���
		if (k % 2 == 0)
		{
			while (coord.x < 0 || coord.x > 2 || coord.y < 0 || coord.y > 2 || board[coord.x][coord.y] != ' ')
			{
				cout << "Your Turn! (x,y) : ";
				cin >> coord.x >> coord.y;
			}
		}

		// ��ǻ�� ���� ���
		else
		{
			coord = Think(board);
			cout << "Computer's Turn! (x,y) : " << coord.x << " " << coord.y << endl;
		}

		// ���忡 �׷��� �� ����
		board[coord.x][coord.y] = (k % 2 == 0) ? 'X' : 'O';

		// ���� ���� �׸���
		DrawBoard(board);

		// ���� üũ�ϱ�
		is_GameOver = CheckBoard(board);

		++k; // Ƚ�� ����
	}
	--k;
	if (k >= 9) cout << "Draw!" << endl;
	cout << endl;

}

Coordinate Think(char (*b)[3])
{
	// �� ��ǥ�� ���� ����
	Coordinate newCoord;
	newCoord.x = -1;
	newCoord.y = -1;

	// 0 �� - ����� ��
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


	// 1 �� - ����� ��
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


	// 2 �� - ����� ��
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


	// ����� ���� ���ٸ� ����
	if (newCoord.x == -1 && newCoord.y == -1)
	{
		while (b[newCoord.x][newCoord.y] != ' ')
		{
			newCoord.x = rand() % 3;
			newCoord.y = rand() % 3;
		}
	}

	// ��ǥ�� ��ȯ
	return newCoord;
}

bool CheckBoard(char (*b)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		// ������
		if (b[i][0] != ' ' && (b[i][0] == b[i][1]) && (b[i][1] == b[0][2]))
		{
			if (b[i][0] == 'X')
				cout << "����� �̰���ϴ�!" << endl;
			else
				cout << "��ǻ�Ͱ� �̰���ϴ�!" << endl;

			return true;
		}

		// ������
		if (b[0][i] != ' ' && (b[0][i] == b[1][i]) && (b[1][i] == b[2][i]))
		{
			if (b[0][i] == 'X')
				cout << "����� �̰���ϴ�!" << endl;
			else
				cout << "��ǻ�Ͱ� �̰���ϴ�!" << endl;

			return true;
		}
	}

	// �밢 1
	if (b[1][1] != ' ')
	{
		if ((b[0][0] == b[1][1]) && (b[1][1] == b[2][2]))
		{
			if (b[1][1] == 'X')
				cout << "����� �̰���ϴ�!" << endl;
			else
				cout << "��ǻ�Ͱ� �̰���ϴ�!" << endl;

			return true;
		}

		// �밢 2
		if ((b[0][2] == b[1][1]) && (b[1][1] == b[2][0]))
		{
			if (b[1][1] == 'X')
				cout << "����� �̰���ϴ�!" << endl;
			else
				cout << "��ǻ�Ͱ� �̰���ϴ�!" << endl;

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