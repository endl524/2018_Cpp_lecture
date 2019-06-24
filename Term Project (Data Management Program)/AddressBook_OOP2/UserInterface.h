#pragma once
#include "stdafx.h"

class CMyList;

class CUserInterface
{
protected:
	CMyList	 &m_List;
	string m_File_Name;

public:
	CUserInterface(CMyList &rList);
	~CUserInterface();

	string GetFileName() const { return m_File_Name; }
	void SetFileName(const string& str) { m_File_Name = str; }



	int Search();
	void Add();
	int PrintUI(const int& num);
	int Save();
	void Load();


	int Run();
};