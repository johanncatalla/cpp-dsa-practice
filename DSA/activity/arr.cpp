#include <iostream>
using namespace std;

int main() {
    int size, x, y; 
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter xy: ";
    cin >> x >> y;
    
    int arr[size] = {};

    for (int i = 0; i < size; i++) {
        std::cout << "Enter Element #" << i+1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] >= x && arr[i] <= y) {
            cout << "Element #" << i+1 << " = YES\n";
        } else {
            cout << "Element #" << i+1 << " = NO\n";
        }
    }
}