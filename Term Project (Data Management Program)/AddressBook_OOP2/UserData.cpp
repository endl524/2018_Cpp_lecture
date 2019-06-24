#include "stdafx.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData()
{
	m_Title = "";
	m_Genre = "";
	m_Date = "";
	m_RunningTime = "";
	m_Story = "";

	m_index = nUserDataCounter;
	nUserDataCounter++;
}

CUserData::CUserData(const string& title, const string& genre, const string& date, const string&time, const string& story)
{
	m_Title = title;
	m_Genre = genre;
	m_Date = date;
	m_RunningTime = time;
	m_Story = story;
	
	m_index = nUserDataCounter;
	nUserDataCounter++;
}

CUserData::~CUserData() {}

const string CUserData::GetKey(int num)
{
	switch (num)
	{
	case 1:
		return m_Title;
		break;
	case 2:
		return m_Genre;
		break;
	case 3:
		return m_Date;
		break;
	case 4:
		return m_RunningTime;
		break;
	case 5:
		return m_Story;
		break;
	}
}

const int CUserData::GetIndex()
{
	return m_index;
}

void CUserData::PrintNode()
{
	cout << "=================================================" << endl;
	cout << "����: " << m_Title << endl;
	cout << "�帣: " << m_Genre << endl;
	cout << "������: " << m_Date << endl;
	cout << "�󿵽ð�: " << m_RunningTime << "��" << endl;
	cout << "�ٰŸ�: " << m_Story << endl;
	cout << "=================================================" << endl;
}

void CUserData::PrintNode_Short(const int& index)
{
	cout << "[" << index << "] ����: " << m_Title << endl;
}