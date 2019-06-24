#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

void main()
{
	CMyList DB(new CUserData);
	CUserInterface UI(DB);

	UI.Run();
}