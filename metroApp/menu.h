#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;

// shange colors
void setColor(int x, int y)
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     if (x == y) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

// display menu 
string display(vector<string>items) {
        // number of items
        int size = items.size();
        // user select index
        int selectIndex = 0;
      
        do {
            // pprint items
            for (int i = 0; i < size; i++) {
                //change color if user select index == item index
                setColor(i, selectIndex);
                cout << items[i] << endl;
            }
            Sleep(100);
            // get input key
            char key = _getch();
            // check 
            switch (key) {
            case 72:  // Up arrow key -> incerement selectIndex if not qrual zero 
                selectIndex = (selectIndex == 0) ? size - 1 : --selectIndex;
                break;
            case 80:  // Down arrow key -> decerement selectIndex if not qrual zero 
                selectIndex = (selectIndex == size - 1) ? 0 : ++selectIndex;
                break;
            case 13:  // Enter key -> return the select item
                return items[selectIndex];
            }
            // clear screan
            system("cls");
        } while (true);

    }
