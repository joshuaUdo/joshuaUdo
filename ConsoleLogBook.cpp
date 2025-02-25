#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<chrono>
#include<iomanip>

using namespace std;

void addLog(){
    string log;
    cout << "Enter daily Log: ";
    getline(cin, log);

    cout << " " << endl;

    auto start = chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(start);
    cout << "This log was created at: " << put_time(localtime(&start_time), "%Y-%m-%d %H:%M") << endl;

    ofstream logFile("logbook.txt", ios::app);
    if(logFile.is_open()){
        logFile << put_time(localtime(&start_time), "%Y-%m-%d %H:%M") << " - " << log << endl;
        logFile.close();
        cout << "Log saved successfully!" << endl;
    } else{ 
        cout << "Failed to open this file." << endl;
    }
}

void editLog(){
    ifstream logFile("logbook.txt");
    if (!logFile.is_open()) {
        cout << "Failed to open log file!" << endl;
        return;
    }

    string line;
    string lastLog;
    while (getline(logFile, line)) {
        lastLog = line;  
    }
    logFile.close();

    string newLog;
    cout << "Enter new log to replace the last log: ";
    getline(cin, newLog);

    ofstream outFile("logbook.txt", ios::trunc);
    if (outFile.is_open()) {
        outFile << newLog << endl;  
        outFile.close();
        cout << "Log updated successfully!" << endl;
    } else {
        cout << "Failed to open the file!" << endl;
    }
}

void viewLog(){
    ifstream logFile("logbook.txt");
    if (!logFile.is_open()) {
        cout << "Failed to open log file!" << endl;
        return;
    }

    string line;
    cout << "All logs:\n";
    while (getline(logFile, line)) {
        cout << line << endl; 
    }
    logFile.close();
}
int main(){
    int choice;
    do {
        cout << "*****\nLogbook Menu*****\n";
        cout << "1. Add Log\n";
        cout << "2. Edit Log\n";
        cout << "3. View Logs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addLog();
                break;
            case 2:
                editLog();
                break;
            case 3:
                viewLog();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}
