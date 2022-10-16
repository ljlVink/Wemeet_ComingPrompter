#include <bits/stdc++.h>
#include <Windows.h>    
#include <mmsystem.h>
using namespace std;
string last="",x="";
int lastnum=0,current=0,sz=0;
void timeshow(int l){
    time_t nowtime;
    nowtime = time(NULL); 
    struct tm *local;
    local = localtime(&nowtime);
    char buf[80];
    strftime(buf, 80, "%Y-%m-%d %H:%M:%S", local);
    cerr<<"["<<buf<<"]:"<<l<<endl;
    char buf1[80];
    strftime(buf1, 80, "%H:%M:%S", local);
}
static BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam) {
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowTextA(hWnd, buffer, length + 1);
    string windowTitle(buffer);
    if (IsWindowVisible(hWnd) && length != 0) {
        if(windowTitle.find("管理成员")==0||windowTitle.find("成员")==0){
            sz=windowTitle.size();
            x=windowTitle.substr(windowTitle.find("(")+1,windowTitle.find(")")-5);
            current=atoi(x.c_str());
            //coming
            if(current<lastnum){
                PlaySound(TEXT("C:\\Windows\\media\\Windows Hardware Remove.wav"), 0, 1); 
                lastnum=current;
                timeshow(current);            
            }
            //gone
            else if(current>lastnum){
                PlaySound(TEXT("C:\\Windows\\media\\Windows Hardware Insert.wav"), 0, 1); 
                lastnum=current;
                timeshow(current);            
            }
        }
    }
    return TRUE;
}
int main() {
    cerr<<"Wemeet_ComingPrompter\nhttps://github.com/ljlVink/Wemeet_ComingPrompter\nPowered by ljlVink\nPls check readme for more info."<<endl;
    while(1){
        LPARAM lParam;
        EnumWindows(enumWindowCallback, lParam);
        Sleep(300);
    }
    return 0;
}