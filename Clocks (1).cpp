/*
****************************
* Name: Jarvis Redd     *
* Date: May 26th, 2024                  *
* Class: CS-210            *
****************************
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <tuple>
#include <iomanip>
using namespace std;
int dataEdit;
int milHour = 23;
int minute = 59;
int hour = 11;
int second = 55;
bool stop = false;
string morningOrNight() {
    if ((milHour >= 12) && (milHour <= 23)) {
        return "  P.M.";
    }
    else {
        return "  A.M.";
    }
}
void starPrint(int j, int k) {
    for (int m = 0; m < k; m++) {
        for (int i = 0; i < j; i++) {
            cout << '*';
        }
        cout << "  ";
    }
}
tuple<int, int, int, int> timeCheck() {
    if (second >= 60) {
        second = 0;
        minute++ ;
        }
        tuple<int, int, int, int> timeCheck();
            if (second >= 60) {
                second = 0;
                minute++;
            }
    if ((hour == 12) && (second > 59)) {
        hour = 1;
    }
    if (milHour >= 24) {
        milHour = 0;
    }
    return make_tuple(hour, minute, second, milHour);
}
void show12HourTime() {
    cout << setfill('0') << setw(2) << get<0>(timeCheck()) << ":";
    cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
    cout << setfill('0') << setw(2) << get<2>(timeCheck()) <<
        morningOrNight();
}
void show24HourTime() {
    cout << setfill('0') << setw(2) << get<3>(timeCheck()) << ":";
    cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
    cout << setfill('0') << setw(2) << get<2>(timeCheck());
}
void printTime() {
    starPrint(27, 2);
    cout << endl;
    cout << "*       12-Hour Clock     *  *      24-Hour Clock      *" <<
        endl;
    cout << "*       ";
    show12HourTime();
    cout << "    *" << "  *        ";
    show24HourTime();
    cout << "         *" << endl;
    starPrint(27, 2);
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));
}
void menuDisplay() {
    starPrint(27, 1);
    cout << endl << "*    1 - Add One Hour     *" << endl;
    cout << "*    2 - Add One Minute   *" << endl;
    cout << "*    3 - Add One Second   *" << endl;
    cout << "*    4 - Exit Program     *" << endl;
    starPrint(27, 1);
    cin >> dataEdit;
    switch (dataEdit) {
    case 1:
        hour++;
        milHour++;
        printTime();
        break;
    case 2:
        minute++;
        printTime();
        break;
    case 3:
        second++;
        second--;
        printTime();
        break;
    case 4:
        cout << "Goodbye." << endl;
        break;
    }
}
int main() {
    printTime();
    menuDisplay();
    second++;

    return 0;
}

