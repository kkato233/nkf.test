// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#pragma comment(lib,"nkf32")

#include "stdafx.h"
#include "..\nkf\nkf32.h"

void test_36572()
{
	/*
    &test("$nkf -sW --fb-html", 
    "\xe6\xbf\xb9\xe4\xb8\x8a", 
    "&#28665;\x8f\xe3"); 
	*/
	::SetNkfOption("-sW --fb-html");
	const char *in = "\xe6\xbf\xb9\xe4\xb8\x8a";
	char* out = new char[65535];
	DWORD len;
	boolean result = ::NkfConvertSafe(out, 65535, &len, in, strlen(in) + 1);
	for (int i = 0; i < len; i++) {
		printf("%02x ", out[i]);
	}
	wchar_t guess[256];
	::GetNkfGuessW(guess, 256, &len);
	printf("%s", guess);

	char guessa[256];
	::GetNkfGuessA(guessa, 256, &len);
	printf("%s", guessa);

}

void test3()
{
	::SetNkfOption("--guess");
	const char *in = "\n";
	char* out = new char[65535];
	DWORD len;
	boolean result = ::NkfConvertSafe(out, 65535, &len, in, strlen(in) + 1);
	for (int i = 0; i < len; i++) {
		printf("%02x ", out[i]);
	}
	wchar_t guess[256];
	::GetNkfGuessW(guess, 256, &len);
	printf("%s", guess);

	char guessa[256];
	::GetNkfGuessA(guessa, 256, &len);
	printf("%s", guessa);

}

void test2()
{
	::SetNkfOption("--ic=euc-jisx0213 -w");
	const char *in = "\xAE\xA2\xAF\xC2\xAF\xCC\xAF\xE0\xAF\xFB\xCF\xD4\xCF\xE3\xCF\xEE\xF5\xBA\xF5\xF2\xF6\xA9\xF6\xB2\xF6\xE0\xF7\xEC\xF8\xFE\xF9\xA9\xF9\xC7\xF9\xD4\xF9\xEE\xFA\xDD\xFB\xB3\xFB\xC9\xFB\xEC\xFC\xC9\xFC\xD1\xFE\xE6\x8F\xA1\xA1\x8F\xA1\xAB\x8F\xA1\xAE\x8F\xA1\xB6\x8F\xA1\xC6\x8F\xA1\xF0\x8F\xA1\xF7\x8F\xA1\xF9\x8F\xA3\xA2\x8F\xA3\xA5\x8F\xA3\xA7\x8F\xA3\xB1\x8F\xA3\xB2\x8F\xA3\xB8\x8F\xA3\xBF\x8F\xA3\xC1\x8F\xA3\xCA\x8F\xA3\xD2\x8F\xA3\xD3\x8F\xA3\xD9\x8F\xA3\xDC\x8F\xA3\xF7\x8F\xA4\xAA\x8F\xA4\xB1\x8F\xA4\xB2\x8F\xA4\xBA\x8F\xA4\xBD\x8F\xA4\xD9\x8F\xA4\xDC\x8F\xA4\xDE\x8F\xA4\xE3\x8F\xA4\xEA\x8F\xA4\xEB\x8F\xA4\xF2\x8F\xA4\xF4\x8F\xA4\xF5\x8F\xA5\xA5\x8F\xA5\xB2\x8F\xA5\xBE\x8F\xA5\xC4\x8F\xA5\xC7\x8F\xA5\xD5\x8F\xA5\xD6\x8F\xA5\xFE\x8F\xA8\xB0\x8F\xA8\xB7\x8F\xA8\xB8\x8F\xA8\xBA\x8F\xA8\xBB\x8F\xA8\xBF\x8F\xA8\xC0\x8F\xA8\xC5\x8F\xA8\xC8\x8F\xA8\xCA\x8F\xA8\xCB\x8F\xA8\xDB\x8F\xA8\xE6\x8F\xA8\xEC\x8F\xAC\xA2\x8F\xAC\xAB\x8F\xAC\xB0\x8F\xAC\xD0\x8F\xAC\xE5\x8F\xAC\xED\x8F\xAC\xF2\x8F\xAD\xA4\x8F\xAD\xA9\x8F\xAD\xAA\x8F\xAD\xB2\x8F\xAD\xB4\x8F\xAD\xB5\x8F\xAD\xB9\x8F\xAD\xD6\x8F\xAD\xFD\x8F\xAE\xA3\x8F\xAE\xA4\x8F\xAE\xBA\x8F\xAE\xBC\x8F\xAE\xBD\x8F\xAE\xC2\x8F\xAE\xC3\x8F\xAE\xC4\x8F\xAE\xC7\x8F\xAE\xC9\x8F\xAE\xD5\x8F\xAE\xD6\x8F\xAE\xD7\x8F\xAE\xDB\x8F\xAE\xF7\x8F\xAE\xF8\x8F\xAF\xAA\x8F\xAF\xBF\x8F\xAF\xC0\x8F\xAF\xC2\x8F\xAF\xC3\x8F\xAF\xCE\x8F\xAF\xD9\x8F\xAF\xE1\x8F\xAF\xE9\x8F\xAF\xEA\x8F\xAF\xF0\x8F\xAF\xF5\x8F\xEE\xA3\x8F\xEE\xB4\x8F\xEE\xC9\x8F\xEE\xDC\x8F\xEE\xDE\x8F\xEE\xDF\x8F\xEE\xE0\x8F\xEF\xB2\x8F\xEF\xC7\x8F\xEF\xCD\x8F\xEF\xE1\x8F\xEF\xE4\x8F\xF0\xA2\x8F\xF0\xB3\x8F\xF0\xB9\x8F\xF0\xD3\x8F\xF0\xFB\x8F\xF1\xAE\x8F\xF1\xB0\x8F\xF1\xB5\x8F\xF1\xC4\x8F\xF1\xDD\x8F\xF1\xE1\x8F\xF1\xE6\x8F\xF1\xE9\x8F\xF1\xF5\x8F\xF1\xF7\x8F\xF1\xFA\x8F\xF2\xA1\x8F\xF2\xA3\x8F\xF2\xA4\x8F\xF2\xA8\x8F\xF2\xAC\x8F\xF2\xBD\x8F\xF2\xC8\x8F\xF2\xDB\x8F\xF2\xF5\x8F\xF2\xF6\x8F\xF3\xB2\x8F\xF3\xBD\x8F\xF3\xBE\x8F\xF3\xC0\x8F\xF3\xD2\x8F\xF3\xDD\x8F\xF3\xDE\x8F\xF3\xF3\x8F\xF3\xF4\x8F\xF3\xF5\x8F\xF3\xF7\x8F\xF3\xFB\x8F\xF3\xFD\x8F\xF4\xA2\x8F\xF4\xA4\x8F\xF4\xA7\x8F\xF4\xAE\x8F\xF4\xAF\x8F\xF4\xB4\x8F\xF4\xB5\x8F\xF4\xBD\x8F\xF4\xC2\x8F\xF4\xCF\x8F\xF4\xE9\x8F\xF4\xEB\x8F\xF4\xF2\x8F\xF4\xF5\x8F\xF4\xF9\x8F\xF5\xB5\x8F\xF5\xBA\x8F\xF5\xC6\x8F\xF5\xD6\x8F\xF5\xD8\x8F\xF5\xDA\x8F\xF5\xDD\x8F\xF5\xDF\x8F\xF5\xE3\x8F\xF5\xEA\x8F\xF5\xF0\x8F\xF5\xF3\x8F\xF6\xC4\x8F\xF6\xCE\x8F\xF6\xDD\x8F\xF6\xF5\x8F\xF6\xFE\x8F\xF7\xA1\x8F\xF7\xA2\x8F\xF7\xB3\x8F\xF7\xB6\x8F\xF7\xE4\x8F\xF7\xE5\x8F\xF7\xEB\x8F\xF7\xEE\x8F\xF7\xF3\x8F\xF8\xA9\x8F\xF8\xAA\x8F\xF8\xAC\x8F\xF8\xB4\x8F\xF8\xBC\x8F\xF8\xBE\x8F\xF8\xC2\x8F\xF8\xD6\x8F\xF8\xE3\x8F\xF8\xF7\x8F\xF8\xF9\x8F\xF8\xFA\x8F\xF9\xA5\x8F\xF9\xAF\x8F\xF9\xB2\x8F\xF9\xB9\x8F\xF9\xC2\x8F\xF9\xC8\x8F\xF9\xD9\x8F\xF9\xDE\x8F\xF9\xE6\x8F\xF9\xEB\x8F\xF9\xFA\x8F\xF9\xFE\x8F\xFA\xA1\x8F\xFA\xAC\x8F\xFA\xAF\x8F\xFA\xCF\x8F\xFA\xD0\x8F\xFA\xD7\x8F\xFA\xE5\x8F\xFA\xE6\x8F\xFA\xF1\x8F\xFA\xF2\x8F\xFA\xFE\x8F\xFB\xA1\x8F\xFB\xAC\x8F\xFB\xAD\x8F\xFB\xB6\x8F\xFB\xB7\x8F\xFB\xBD\x8F\xFB\xBE\x8F\xFB\xCE\x8F\xFB\xCF\x8F\xFB\xD7\x8F\xFB\xDA\x8F\xFB\xDC\x8F\xFB\xDD\x8F\xFB\xE1\x8F\xFB\xE5\x8F\xFB\xE7\x8F\xFB\xE9\x8F\xFB\xF1\x8F\xFC\xA2\x8F\xFC\xA3\x8F\xFC\xB8\x8F\xFC\xC2\x8F\xFC\xCC\x8F\xFC\xD6\x8F\xFC\xD9\x8F\xFC\xDD\x8F\xFC\xF6\x8F\xFD\xAC\x8F\xFD\xCB\x8F\xFD\xCC\x8F\xFD\xD9\x8F\xFD\xDB\x8F\xFD\xDD\x8F\xFD\xE7\x8F\xFD\xED\x8F\xFD\xF0\x8F\xFE\xA5\x8F\xFE\xA9\x8F\xFE\xAB\x8F\xFE\xB2\x8F\xFE\xB5\x8F\xFE\xD3\x8F\xFE\xD8\x8F\xFE\xDA\x8F\xFE\xEE\x8F\xFE\xF0\x8F\xFE\xF2\x8F\xFE\xF6\x0A\x00";
	char* out = new char[65535];
	DWORD len;
	boolean result = ::NkfConvertSafe(out, 65535, &len, in, strlen(in) + 1);
	for (int i = 0; i < len; i++) {
		printf("%02x ", out[i]);
	}


}

int _tmain(int argc, _TCHAR* argv[])
{
	test_36572();
}

void test1()
{

	_TCHAR file[] = L"C:\\Users\\kato\\AppData\\Local\\Temp\\tmp65B0.tmp";

	BOOL mode = ::NkfFileConvert1SafeW(file, wcslen(file) + 1);
}


