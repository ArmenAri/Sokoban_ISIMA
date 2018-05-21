#include <iostream>
#include "Partie.h"
#include <tchar.h>
#include "resources.h"

int main()
{
	typedef BOOL(WINAPI *PSetConsoleIcon)(HICON);
	static PSetConsoleIcon pSetConsoleIcon = NULL;
	if (pSetConsoleIcon == NULL)
		pSetConsoleIcon = (PSetConsoleIcon)::GetProcAddress(::GetModuleHandle(_T("kernel32")), "SetConsoleIcon");
	if (pSetConsoleIcon == NULL) return FALSE;
	pSetConsoleIcon((HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON), IMAGE_ICON, 16, 16, 0));
	std::string title = "Sokoban_Armen_et_Antony";
	TCHAR szOldTitle[MAX_PATH];
	if (GetConsoleTitle(szOldTitle, MAX_PATH))
	{
		if (!SetConsoleTitle((const TCHAR*)title.c_str()))
		{
			_tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
		}
	}

	Partie partie;
	partie.start();
	return 0;
}