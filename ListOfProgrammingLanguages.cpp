#include "Header.h"

// entrance menu
void consoleMenu(){
    cout << "Welcome to a program which shows you ordered list of all programming languages!" << endl;
    cout << "Press Enter to continue" << endl;
    cin.get();
}

int main() {
    consoleMenu();
    myList* u = NULL; // pointer to the beginning of list
    readFromFile(u);
    delete u;
    cout << "End of program" << endl;
    return 0;
}

