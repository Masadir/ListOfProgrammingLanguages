#include "Header.h"

// check if file located in folder of your programm
inline bool isFileExist(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

// reading file line by line and send the data to elementCreation() method
void readFromFile(myList* u) {
    string line;
    if (isFileExist("listOfProgrammingLanguages.csv")) {
        ifstream file("listOfProgrammingLanguages.csv");
        if (file.is_open()) {
            while (getline(file, line)) {
                int const size = 256;
                char arr[size];
                strcpy(arr, line.c_str());
                char* ptr = 0;
                delete ptr;
                ptr = strtok(arr, ";");
                char* year = ptr;
                ptr = strtok(0, ";");
                string name = ptr;
                ptr = strtok(0, ";");
                string creator = ptr;
               
                int intYear = stoi(year);
                elementCreation(&u, intYear, name, creator);
            }
        }
        file.close();
        printElements(u);
    }
    else {
        cout << "File listOfProgrammingLanguages.csv doesn't exist in your working directory!" << endl;
    }
}