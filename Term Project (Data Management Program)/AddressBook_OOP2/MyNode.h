#pragma once
#include "stdafx.h"

class CMyNode
{
	friend class CMyList;
public:
	CMyNode() : pNext(nullptr) {}
	virtual ~CMyNode() {}

	CMyNode* GetNext() const { return pNext; }

	// ������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����
	virtual const string GetKey(int num) = 0;
	virtual const int GetIndex() = 0;
	virtual void PrintNode() = 0;

private:
	// ���� ����Ʈ ��ü�� ���� ���
	CMyNode* pNext;

};