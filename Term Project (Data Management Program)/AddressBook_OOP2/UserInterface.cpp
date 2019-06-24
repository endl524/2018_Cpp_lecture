#include "stdafx.h"
#include "UserData.h"
#include "UserInterface.h"
#include "MyList.h"

CUserInterface::CUserInterface(CMyList &rList) : m_List(rList) {}

CUserInterface::~CUserInterface() {}

#define TITLE_UI 0
#define SEARCH_UI 1
#define SAVE_UI 2

int CUserInterface::PrintUI(const int& num) // �ʱ� �޴� �������̽� UI ���
{
	int input = 0;

	system("cls");
	switch (num)
	{
	case TITLE_UI:
		cout << "==========================================================" << endl;
		cout << "[1]Search  [2]Add  [3]Print All  [4]Save  [5]Load  [0]Exit" << endl;
		cout << "==========================================================" << endl;
		break;
	case SEARCH_UI:
		cout << "==============================================================" << endl;
		cout << "			<�˻�>							" << endl;
		cout << "[1] ����   [2] �帣   [3] ������   [4] �󿵽ð�   [5] ���ư���" << endl;
		cout << "==============================================================" << endl;
		break;
	case SAVE_UI:
		cout << "==============================================================" << endl;
		cout << "			<����>							" << endl;
		cout << "[1] �� ���Ͽ� ����   [2] ���� ���Ͽ� ����   [3] ���ư���" << endl;
		cout << "==============================================================" << endl;
		break;
	}
	cout << ">> ";
	cin >> input;

	return input;
}

int CUserInterface::Search() // �˻�
{
	int input = 0;
	int i_date = 0;
	string str = "";
	while (str == "")
	{
		input = PrintUI(SEARCH_UI);
		cin.ignore();
		switch (input)
		{
		case 1:
			cout << "������ �Է��ϼ���: ";
			getline(cin, str);
			break;
		case 2:
			cout << "�帣�� �Է��ϼ���: ";
			getline(cin, str);
			break;
		case 3:
			cout << "==========================" << endl;
			cout << "[1] ����   [2] ����+��" << endl;
			cout << ">> ";
			cin >> i_date;
			switch (i_date)
			{
			case 1:
				cout << "�����⵵�� �Է��ϼ���(YYYY): ";
				cin >> str;
				if (str.length() != 4)
					return 0;
				break;

			case 2:
				cout << "�����⵵+���� �Է��ϼ���(YYYYMM): ";
				cin >> str;
				if (str.length() != 6)
					return 0;
				break;

			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}

			
			break;
		case 4:
			cout << "�󿵽ð��� �Է��ϼ���: ";
			getline(cin, str);
			break;
		case 5:
			return 0;
			break;
		}
	}

	int count;
	CUserData** pNode = m_List.Find_Node(str, input, count);

	if (count == 0)
		cout << "ERROR: �����͸� ã�� �� �����ϴ�." << endl;
	else
	{
		system("cls");
		cout << "======================================" << endl;
		for (int i = 0; i < count; ++i)
			pNode[i]->PrintNode_Short(i);
		cout << "======================================" << endl;
		cout << "�����Ͻ� �������� ��ȣ�� �Է����ּ���. >> ";
		int index;
		cin >> index;
		if (index >= 0 && index < count)
		{
			system("cls");
			pNode[index]->PrintNode();
			cout << "[1] ������ ����  [2] ����  [else] ���ư���" << endl;
			cout << ">> ";
			cin >> input;
			string s;
			int search_index = pNode[index]->GetIndex();
			
			switch (input)
			{
			case 1:
				cout << "============================================================" << endl;
				cout << "		� �����͸� �����Ͻðڽ��ϱ�?" << endl;
				cout << "============================================================" << endl;
				cout << "[1] ����   [2] �帣   [3] ������   [4] �󿵽ð�   [5] �ٰŸ�" << endl;
				cout << ">> ";
				int i;
				cin >> i;
				cin.ignore();
				switch (i)
				{
				case 1:
					cout << "������ �Է����ּ���" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetTitle(s);
					cout << "������ �Ϸ�Ǿ����ϴ�!" << endl;
					break;

				case 2:
					cout << "�帣�� �Է����ּ���" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetGenre(s);
					cout << "������ �Ϸ�Ǿ����ϴ�!" << endl;
					break;

				case 3:
					cout << "�������� �Է����ּ���" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetDate(s);
					cout << "������ �Ϸ�Ǿ����ϴ�!" << endl;
					break;

				case 4:
					cout << "�󿵽ð��� �Է����ּ���" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetRunningTime(s);
					cout << "������ �Ϸ�Ǿ����ϴ�!" << endl;
					break;

				case 5:
					cout << "�ٰŸ��� �Է����ּ���" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetStory(s);
					cout << "������ �Ϸ�Ǿ����ϴ�!" << endl;
					break;

				default:
					cout << "�߸��� �Է��Դϴ�." << endl;
					break;
				}
				break;

			case 2:
				cout << "======================" << endl;
				cout << "���� �����Ͻðڽ��ϱ�?" << endl;
				cout << "======================" << endl;
				cout << "[1] ��   [else] �ƴϿ�" << endl;
				cout << ">> ";
				int a;
				cin >> a;
				if (a == 1)
				{
					m_List.RemoveNode(pNode[index]);
					cout << "�����Ǿ����ϴ�." << endl;
				}
				break;

			default:
				break;
			}
		}
		else
			cout << "�߸��� �ε��� �Դϴ�." << endl;
	}

	delete[] pNode;

	system("pause");
}

void CUserInterface::Add() // ��� �߰�
{
	string title, genre, date, runtime, story;

	cin.ignore();
	cout << "������ �Է��ϼ���: ";
	getline(cin, title);
	cout << "�帣�� �Է��ϼ���: ";
	getline(cin, genre);
	cout << "�������� �Է��ϼ���: ";
	getline(cin, date);
	cout << "�󿵽ð��� �Է��ϼ���: ";
	getline(cin, runtime);
	cout << "�ٰŸ��� �Է��ϼ���: ";
	getline(cin, story);

	m_List.AddNewNode(new CUserData(title, genre, date, runtime, story));
}

int CUserInterface::Save() // ����Ʈ ���Ͽ� ����
{
	int input = 0;

	string str = "";
	while (str == "")
	{
		switch (PrintUI(SAVE_UI))
		{
		case 1:
			cout << "���� �̸��� �Է��ϼ���: ";
			cin >> str;
			SetFileName(str);
			break;
		case 2:
			cout << "���� ���Ͽ� �����մϴ�." << endl;
			str = GetFileName();
			break;
		case 3:
			return 0;
			break;
		}
	}

	m_List.Save_List(str);
	return 1;
}

void CUserInterface::Load() // ������ �о ����Ʈ�� ����
{
	string str = "";
	system("cls");
	cout << "==========================" << endl;
	cout << "	<�ҷ�����>			" << endl;
	cout << "==========================" << endl;
	cout << "���� �̸��� �Է��ϼ��� >> ";
	cin >> str;

	int retval = m_List.Load_List(str);
	if (retval == -1)
		cout << str << " ������ ã�� �� �����ϴ�." << endl;
	else
	{
		cout << str << " ������ �ҷ��Խ��ϴ�." << endl;
		SetFileName(str);
	}
	
	system("pause");
}


int CUserInterface::Run() // �������̽� ����
{
	m_List.Load_List("DataBase.txt"); // �⺻ DB �ε�
	SetFileName("DataBase.txt");

	int nMenu = 0;
	while (nMenu = PrintUI(TITLE_UI))
	{
		switch (nMenu)
		{
		case 1:    // Search
			Search();
			break;

		case 2:    // Add
			Add();
			break;

		case 3:    // Print_List
			m_List.Print_List();
			break;

		case 4:    // Save
			Save();
			break;

		case 5:		// Load
			Load();
			break;

		case 0:
			return 0;
			break;

		default:
			break;
		}
	}

	return nMenu;
}