#include <bits/stdc++.h>
#include <Windows.h>    
#include <mmsystem.h>
using namespace std;
string last="";
static BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam) {
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowTextA(hWnd, buffer, length + 1);
    string windowTitle(buffer);
    if (IsWindowVisible(hWnd) && length != 0) {
        if(windowTitle.find("管理成员")==0||windowTitle.find("成员")==0){
            if(last!=windowTitle){
                last=windowTitle;
                cout<<last<<endl;
                PlaySound(TEXT("C:\\Windows\\media\\Windows Notify System Generic.wav"), 0, 1); 
            }
        }
    }
    return TRUE;
}
int main() {
    cout<<"Wemeet_ComingPrompter\nhttps://github.com/ljlVink/Wemeet_ComingPrompter\nPowered by ljlVink\nPls check readme for more info."<<endl;
    while(1){
        LPARAM lParam;
        EnumWindows(enumWindowCallback, lParam);
        Sleep(500);
    }
    return 0;
}