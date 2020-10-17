#include<iostream>
#include<Windows.h>

using namespace std;

int main() {
	int money = 0;
	int timeout = 3000;

	HWND hwnd = FindWindowA(NULL, "Counter-Strike");
	if (hwnd == NULL) {
		cout << "Counter-Strike window is not found" << endl;
		Sleep(timeout);
		exit(-1);
	}
	else {
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		if (procID == NULL) {
			cout << "Process ID is not found" << endl;
			Sleep(timeout);
			exit(-1);
		}
		else {
			ReadProcessMemory(handle, (LPVOID)0x0741423C, &money, sizeof(money), 0);
			while (1) {
				if (GetAsyncKeyState(VK_F3)) {
					WriteProcessMemory(handle, (LPVOID)0x0741423C, &money, sizeof(money), 0);
					WriteProcessMemory(handle, (LPVOID)0x0F1513C4, &money, sizeof(money), 0);
					money++;
				}
				Sleep(1);
			}
		}
	}

	return 0;
}