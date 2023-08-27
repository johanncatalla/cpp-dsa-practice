#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// Abstraction;
void gotoxy(short x, short y);
int getcenterpos(int content_width);

// Function Definition
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// Terminal center position relative to content width
int getcenterpos(int content_width) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO lpscreeninfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsole, lpscreeninfo);
    COORD NewSBSize = lpscreeninfo->dwMaximumWindowSize;
    return ((NewSBSize.X - content_width)/2);
}

int main() {
    int height, width, centerpos;
    string msg;

    cout << "Enter height: ";
    cin >> height;
    cin.ignore();
    cout << "Enter text: ";
    getline(cin, msg);
    width = msg.length() + 4;
    centerpos = getcenterpos(width);
    short Ypos = ((28 - height)/2);
    system("cls");
   
    for(int a =  0; a <= height+1; a++) {
        // top
        if (a==0) {
        	gotoxy(centerpos, Ypos);
            cout << char(201);
            for (int j=1; j<=width; j++) {
                cout << char(205);
            }
            cout << char(187);
        } else if (a == height+1) {
            gotoxy(centerpos, Ypos+a);
            cout << char(200);
            for (int k = 1; k <= width; k++) {
                cout << char(205);
            }
            cout << char(188);
        } else if(a==height/2) {
            if ((height)%2==0) {
                gotoxy(centerpos, Ypos+a);
                cout << char(186);
                gotoxy(centerpos+3, Ypos+a);
                cout << msg << endl;
                gotoxy(centerpos+3, Ypos+a+1);
                cout << msg << endl;
                gotoxy(centerpos+width+1, Ypos+a);
                cout << char(186);
            } else {
            gotoxy(centerpos, Ypos+a);
            cout << char(186);
            gotoxy(centerpos+3,Ypos+a+1);
            cout << msg << endl;
            gotoxy(centerpos+width+1, Ypos+a);
            cout << char(186);
            }
        } else {
        gotoxy(centerpos, Ypos+a);
        cout << char (186);
        gotoxy(centerpos+width+1, Ypos+a);
        cout << char(186);
    } 
    }
}
