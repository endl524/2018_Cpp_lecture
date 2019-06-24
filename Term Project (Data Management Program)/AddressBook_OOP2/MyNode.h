#pragma once
#include "stdafx.h"

class CMyNode
{
	friend class CMyList;
public:
	CMyNode() : pNext(nullptr) {}
	virtual ~CMyNode() {}

	CMyNode* GetNext() const { return pNext; }

	// 관리를 위해 꼭 필요한 인터페이스 함수들을 순수 가상 함수로 선언
	virtual const string GetKey(int num) = 0;
	virtual const int GetIndex() = 0;
	virtual void PrintNode() = 0;

private:
	// 연결 리스트 자체를 위한 멤버
	CMyNode* pNext;

};