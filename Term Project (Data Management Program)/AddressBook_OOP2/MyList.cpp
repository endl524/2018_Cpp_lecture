#include "stdafx.h"
#include "MyList.h"
#include "UserData.h"

CMyList::CMyList(CMyNode *pHead)
{
	m_pHead = pHead;
}

CMyList::~CMyList()
{
	ReleaseList();
}


CUserData** CMyList::Find_Node(const string& str, const int& type, int& count)
{
	CMyNode *pTmp = m_pHead->pNext;
	CUserData *pData[10]{ nullptr };
	int retcount = 0;

	while (pTmp != nullptr && retcount < 10)
	{
		if (pTmp->GetKey(type).find(str) != string::npos)
		{
			pData[retcount++] = reinterpret_cast<CUserData*>(pTmp);
		}
		pTmp = pTmp->pNext;
	}

	CUserData** Dest;

	if (retcount > 0)
	{
		Dest = new CUserData*[retcount];
		memcpy(Dest, pData, sizeof(CUserData*) * retcount);
	}
	else Dest = nullptr;

	count = retcount;
	return Dest;
}


int CMyList::AddNewNode(CMyNode *pNewNode)
{
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;

	return 1;
}


int CMyList::Print_List()
{
	int input = 0;

	system("cls");
	cout << "==============================================================" << endl;
	cout << "		<����Ʈ ��ü ��� (����)>							" << endl;
	cout << "[1] ����   [2] �帣   [3] ������   [4] �󿵽ð�   [5] ���ư���" << endl;
	cout << "==============================================================" << endl;
	cout << ">> ";
	cin >> input;

	while (true)
	{
		if (input >= 1 && input <= 4)
		{
			CUserData* counter;

			for (int i = 0; i < counter->GetUserDataCounter() - 1; ++i)
			{
				CMyNode* pTmp1 = m_pHead;
				CMyNode* pTmp2 = m_pHead->pNext;
				CMyNode* temp1;
				CMyNode* temp2;
				
				while (pTmp2->pNext != nullptr)
				{
					if (pTmp2->GetKey(input) > pTmp2->pNext->GetKey(input))
					{
						temp1 = pTmp2->pNext;
						temp2 = pTmp2->pNext->pNext;
						pTmp2->pNext = temp2;
						temp1->pNext = pTmp2;
						pTmp1->pNext = temp1;
					}
					else pTmp2 = pTmp2->pNext;
					pTmp1 = pTmp1->pNext;
				}
			}
			break;
		}

		else if (input == 5)
			return 0;

		else
		{
			cout << "�޴��� ������ ������ϴ�. �ٽ� �Է����ּ���: ";
			cin >> input;
		}
	}

	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != nullptr)
	{
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	system("pause");
}


int CMyList::RemoveNode(const string& str, const int& type)
{
	CMyNode *pPrevNode = m_pHead;
	CMyNode *pDelete = nullptr;

	while (pPrevNode->pNext != nullptr)
	{
		pDelete = pPrevNode->pNext;

		if (pDelete->GetKey(type).find(str) != string::npos)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}
	
	return 0;
}

int CMyList::RemoveNode(const CMyNode* node)
{
	CMyNode *pPrevNode = m_pHead;
	CMyNode *pDelete = nullptr;

	while (pPrevNode->pNext != nullptr)
	{
		pDelete = pPrevNode->pNext;

		if (pDelete == node)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}


void CMyList::ReleaseList()
{
	CMyNode *pTmp = m_pHead->pNext;
	CMyNode *pDelete = nullptr;

	while (pTmp != nullptr)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}
	m_pHead->pNext = nullptr;
	CUserData* tmp;
	tmp->ResetUserDataCounter();
}


int CMyList::Save_List(const string& filename)
{
	ofstream dataBase(filename);

	if (dataBase.fail())
		return -1;
	else
	{
		CMyNode *pTmp = m_pHead->pNext;
		if (pTmp != nullptr)
		{
			while (true)
			{
				for (int i = 1; i < 6; ++i)
				{
					dataBase << pTmp->GetKey(i);
					if (i != 5)
						dataBase << "<!>";
				}
				pTmp = pTmp->pNext;

				if (pTmp != nullptr)
					dataBase << endl;
				else
					break;
			}
		}
		dataBase.close();
	}
	return 0;
}

int CMyList::Load_List(const string& filename)
{
	ifstream dataBase(filename);

	if (dataBase.fail())
		return -1;
	else
	{
		CUserData* counter;
		if (counter->GetUserDataCounter() - 1 > 0)
		{
			cout << "���� ����Ʈ�� ����� ���� �ҷ��ɴϴ�." << endl;
			ReleaseList();
		}

		string str, tmpStr[5];
		int count;

		while (!dataBase.eof())
		{
			getline(dataBase, str); // ���� �б�

			count = 0; // �ʱ�ȭ
			for (int i = 0; i < 5; ++i)
				tmpStr[i] = ""; // �ʱ�ȭ

			for (int i = 0; i != str.length(); ++i)
			{
				if (str[i] == '<', str[i + 1] == '!', str[i + 2] == '>') // Split
				{
					++count;
					i += 2;
				}
				else
					tmpStr[count] += str[i]; // ���ڿ� ä���
			}

			AddNewNode(new CUserData(tmpStr[0], tmpStr[1], tmpStr[2], tmpStr[3], tmpStr[4])); // �ϼ��� �����͵��� ����Ʈ�� ����
		}
		
		dataBase.close();
	}
	return 0;
}