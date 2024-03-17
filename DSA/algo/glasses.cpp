#include <iostream>
#include <vector>
using namespace std;

void alternateGlasses(vector<bool>& glasses, int n) {
    // Iterate over each glass
    for (int i = 0; i < 2*n; ++i) {
        // Check if the glass is in an incorrect state
        // (i.e., filled when it should be empty, or empty when it should be filled)
        if ((i % 2 == 0 && !glasses[i]) || (i % 2 == 1 && glasses[i])) {
            // Find the next glass in the opposite state
            for (int j = i + 1; j < 2*n; ++j) {
                // If the next glass is in the opposite state, swap the two glasses
                if ((i % 2 == 0 && glasses[j]) || (i % 2 == 1 && !glasses[j])) {
                    swap(glasses[i], glasses[j]);
                    break;
                }
            }
        }
    }
}

int main() {
    int n ;
    cout << "\nEnter n: ";
    cin >> n;
    cout << endl;

    // Create a vector of glasses, with the first n filled (true) and the rest empty (false)
    vector<bool> glasses(2*n, false);
    fill(glasses.begin(), glasses.begin() + n, true);

    // Print the initial state of the glasses
    cout << "The glasses before swapping:" << endl;
    for (bool filled : glasses) {
        cout << (filled ? 1 : 0) << ' ';
    }
    cout << "\n" << endl;

    // Call the function to alternate the glasses
    alternateGlasses(glasses, n);

    // Print the final state of the glasses
    cout << "The glasses after swapping:" << endl;
    for (bool filled : glasses) {
        cout << (filled ? 1 : 0) << ' ';
    }
    cout << "\n" << endl;

    return 0;
}
