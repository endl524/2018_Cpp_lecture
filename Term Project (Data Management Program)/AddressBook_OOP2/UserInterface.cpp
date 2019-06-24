#include "stdafx.h"
#include "UserData.h"
#include "UserInterface.h"
#include "MyList.h"

CUserInterface::CUserInterface(CMyList &rList) : m_List(rList) {}

CUserInterface::~CUserInterface() {}

#define TITLE_UI 0
#define SEARCH_UI 1
#define SAVE_UI 2

int CUserInterface::PrintUI(const int& num) // 초기 메뉴 인터페이스 UI 출력
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
		cout << "			<검색>							" << endl;
		cout << "[1] 제목   [2] 장르   [3] 개봉일   [4] 상영시간   [5] 돌아가기" << endl;
		cout << "==============================================================" << endl;
		break;
	case SAVE_UI:
		cout << "==============================================================" << endl;
		cout << "			<저장>							" << endl;
		cout << "[1] 새 파일에 저장   [2] 현재 파일에 저장   [3] 돌아가기" << endl;
		cout << "==============================================================" << endl;
		break;
	}
	cout << ">> ";
	cin >> input;

	return input;
}

int CUserInterface::Search() // 검색
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
			cout << "제목을 입력하세요: ";
			getline(cin, str);
			break;
		case 2:
			cout << "장르를 입력하세요: ";
			getline(cin, str);
			break;
		case 3:
			cout << "==========================" << endl;
			cout << "[1] 연도   [2] 연도+월" << endl;
			cout << ">> ";
			cin >> i_date;
			switch (i_date)
			{
			case 1:
				cout << "개봉년도를 입력하세요(YYYY): ";
				cin >> str;
				if (str.length() != 4)
					return 0;
				break;

			case 2:
				cout << "개봉년도+월을 입력하세요(YYYYMM): ";
				cin >> str;
				if (str.length() != 6)
					return 0;
				break;

			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}

			
			break;
		case 4:
			cout << "상영시간을 입력하세요: ";
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
		cout << "ERROR: 데이터를 찾을 수 없습니다." << endl;
	else
	{
		system("cls");
		cout << "======================================" << endl;
		for (int i = 0; i < count; ++i)
			pNode[i]->PrintNode_Short(i);
		cout << "======================================" << endl;
		cout << "열람하실 데이터의 번호를 입력해주세요. >> ";
		int index;
		cin >> index;
		if (index >= 0 && index < count)
		{
			system("cls");
			pNode[index]->PrintNode();
			cout << "[1] 데이터 수정  [2] 삭제  [else] 돌아가기" << endl;
			cout << ">> ";
			cin >> input;
			string s;
			int search_index = pNode[index]->GetIndex();
			
			switch (input)
			{
			case 1:
				cout << "============================================================" << endl;
				cout << "		어떤 데이터를 수정하시겠습니까?" << endl;
				cout << "============================================================" << endl;
				cout << "[1] 제목   [2] 장르   [3] 개봉일   [4] 상영시간   [5] 줄거리" << endl;
				cout << ">> ";
				int i;
				cin >> i;
				cin.ignore();
				switch (i)
				{
				case 1:
					cout << "제목을 입력해주세요" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetTitle(s);
					cout << "수정이 완료되었습니다!" << endl;
					break;

				case 2:
					cout << "장르를 입력해주세요" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetGenre(s);
					cout << "수정이 완료되었습니다!" << endl;
					break;

				case 3:
					cout << "개봉일을 입력해주세요" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetDate(s);
					cout << "수정이 완료되었습니다!" << endl;
					break;

				case 4:
					cout << "상영시간을 입력해주세요" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetRunningTime(s);
					cout << "수정이 완료되었습니다!" << endl;
					break;

				case 5:
					cout << "줄거리를 입력해주세요" << endl << ">> ";
					getline(cin, s);
					m_List[search_index].SetStory(s);
					cout << "수정이 완료되었습니다!" << endl;
					break;

				default:
					cout << "잘못된 입력입니다." << endl;
					break;
				}
				break;

			case 2:
				cout << "======================" << endl;
				cout << "정말 삭제하시겠습니까?" << endl;
				cout << "======================" << endl;
				cout << "[1] 예   [else] 아니오" << endl;
				cout << ">> ";
				int a;
				cin >> a;
				if (a == 1)
				{
					m_List.RemoveNode(pNode[index]);
					cout << "삭제되었습니다." << endl;
				}
				break;

			default:
				break;
			}
		}
		else
			cout << "잘못된 인덱스 입니다." << endl;
	}

	delete[] pNode;

	system("pause");
}

void CUserInterface::Add() // 노드 추가
{
	string title, genre, date, runtime, story;

	cin.ignore();
	cout << "제목을 입력하세요: ";
	getline(cin, title);
	cout << "장르를 입력하세요: ";
	getline(cin, genre);
	cout << "개봉일을 입력하세요: ";
	getline(cin, date);
	cout << "상영시간을 입력하세요: ";
	getline(cin, runtime);
	cout << "줄거리를 입력하세요: ";
	getline(cin, story);

	m_List.AddNewNode(new CUserData(title, genre, date, runtime, story));
}

int CUserInterface::Save() // 리스트 파일에 저장
{
	int input = 0;

	string str = "";
	while (str == "")
	{
		switch (PrintUI(SAVE_UI))
		{
		case 1:
			cout << "파일 이름을 입력하세요: ";
			cin >> str;
			SetFileName(str);
			break;
		case 2:
			cout << "현재 파일에 저장합니다." << endl;
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

void CUserInterface::Load() // 파일을 읽어서 리스트에 띄우기
{
	string str = "";
	system("cls");
	cout << "==========================" << endl;
	cout << "	<불러오기>			" << endl;
	cout << "==========================" << endl;
	cout << "파일 이름을 입력하세요 >> ";
	cin >> str;

	int retval = m_List.Load_List(str);
	if (retval == -1)
		cout << str << " 파일을 찾을 수 없습니다." << endl;
	else
	{
		cout << str << " 파일을 불러왔습니다." << endl;
		SetFileName(str);
	}
	
	system("pause");
}


int CUserInterface::Run() // 인터페이스 루프
{
	m_List.Load_List("DataBase.txt"); // 기본 DB 로드
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