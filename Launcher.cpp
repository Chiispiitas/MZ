#include <windows.h>
#include <string>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    wchar_t launcherPath[MAX_PATH];
    GetModuleFileNameW(NULL, launcherPath, MAX_PATH);

    std::wstring baseDir = launcherPath;
    size_t slash = baseDir.find_last_of(L"\\/");
    if (slash != std::wstring::npos) {
        baseDir = baseDir.substr(0, slash);
    }

    std::wstring workDir = baseDir + L"\\files";
    std::wstring gameExe = workDir + L"\\Game.exe";

    STARTUPINFOW si = {};
    PROCESS_INFORMATION pi = {};
    si.cb = sizeof(si);

    BOOL ok = CreateProcessW(
        gameExe.c_str(),
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        workDir.c_str(),
        &si,
        &pi
    );

    if (!ok) {
        MessageBoxW(NULL, L"Could not start files\\Game.exe", L"Launch Error", MB_ICONERROR);
        return 1;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
