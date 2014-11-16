// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#pragma comment(lib,"nkf32")

#include "stdafx.h"
#include "..\nkf\nkf32.h"

int _tmain(int argc, _TCHAR* argv[])
{
	_TCHAR file[] = L"C:\\Users\\kato\\AppData\\Local\\Temp\\tmp65B0.tmp";

	BOOL mode = ::NkfFileConvert1SafeW(file, wcslen(file) + 1);
}

