#include <iostream>
#include <string>

using namespace std;
int main() {
    string msg;
    int num;
    cout << "Enter num: ";
    cin >> num;
    cin.ignore();
    cout << "Enter string: ";
    getline(cin, msg);
    cout << msg;
}