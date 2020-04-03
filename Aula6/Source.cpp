#include <Windows.h>
#include <tchar.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

int _tmain(int argc, TCHAR* argv[]) {

	HANDLE hMapFile, hFich;
	char* pBuf, aux;
	TCHAR auxt;

	hFich = CreateFile(TEXT("letras.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	hMapFile = CreateFileMapping(hFich, NULL, PAGE_READWRITE, 0, 26, NULL);
	pBuf = (char*)MapViewOfFile(hMapFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 26);

	for (unsigned int i = 0; i < 13; i++) {
		aux = pBuf[i];
		pBuf[i] = pBuf[25 - i];
		pBuf[25 - i] = aux;
	}

	for (unsigned int i = 0; i < 26; i++)
		_tprintf(_T("%c"), pBuf[i]);

	_tprintf(_T("\n"));

	UnmapViewOfFile(hMapFile);
	CloseHandle(hFich);
}