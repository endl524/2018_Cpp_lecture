#pragma once
#include "stdafx.h"
#include "MyNode.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode
{
public:
	CUserData();
	CUserData(const string& title, const string& genre, const string& date, const string& time, const string& story);
	~CUserData();

	const string GetTitle() const { return m_Title; }
	void SetTitle(const string& str) { m_Title = str; }
	const string GetGenre() const { return m_Genre; }
	void SetGenre(const string& str) { m_Genre = str; }
	const string GetDate() const { return m_Date; }
	void SetDate(const string& str) { m_Date = str; }
	const string GetRunningTime() const { return m_RunningTime; }
	void SetRunningTime(const string& str) { m_RunningTime = str; }
	const string GetStory() const { return m_Story; }
	void SetStory(const string& str) { m_Story = str; }

	void SetIndex(const int& i) { m_index = i; }

	static int GetUserDataCounter() { return nUserDataCounter; }
	static void ResetUserDataCounter() { nUserDataCounter = 0; }

protected:
	string m_Title;
	string m_Genre;
	string m_Date;
	string m_RunningTime;
	string m_Story;

	int m_index;

	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	virtual const string GetKey(int num);
	virtual const int GetIndex();
	virtual void PrintNode();
	void PrintNode_Short(const int& index);
};