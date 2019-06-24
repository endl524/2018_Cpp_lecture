#pragma once
#include "stdafx.h"
#include "MyNode.h"
#include "UserData.h"

// 노드 클래스에 대한 알림 선언
class CMyNode;
class CUserData;

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList();

protected:
	void ReleaseList();
	CMyNode *m_pHead;

public:
	CUserData** Find_Node(const string& str, const int& type, int& count);
	int AddNewNode(CMyNode *pNewNode);
	int Print_List();
	int RemoveNode(const string& str, const int& type);
	int RemoveNode(const CMyNode* node);

	int Save_List(const string& filename);
	int Load_List(const string& filename);

	CUserData& operator[](const int& index)
	{
		CMyNode *pTmp = m_pHead->pNext;
		CUserData* data = nullptr;

		while (pTmp != nullptr)
		{
			if (index == pTmp->GetIndex())
			{
				data = reinterpret_cast<CUserData*>(pTmp);
				return *data;
			}
			pTmp = pTmp->pNext;
		}

		return *data;
	}
};