#include <Windows.h>
#include <wininet.h>
#include <ShlObj.h>
#include <iostream>

int main()
{
	CoInitialize(nullptr);

	IActiveDesktop* pDesktop = nullptr;
	WCHAR wszWallpaper[MAX_PATH];

	CoCreateInstance(
		CLSID_ActiveDesktop,
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(IActiveDesktop),
		reinterpret_cast<void**>(&pDesktop)
	);

	pDesktop->GetWallpaper(wszWallpaper, MAX_PATH, 0);
	std::wcout << wszWallpaper;

	CoUninitialize();

	std::cin.get();
	return 0;
}