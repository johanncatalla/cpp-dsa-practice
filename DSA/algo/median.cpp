#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 3, 5, 6};
    unordered_map<int, int> freq = {};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++) {
        if (freq.find(arr[i]) == freq.end()) {
            freq[arr[i]] = 1;
        } else {
            freq[arr[i]] += 1;
        }
    }

    pair<int, int> mode = {-1, -1};
    for (const auto &iter : freq) {
        if (iter.second > mode.second) {
            mode = iter;
        }
    }

    cout << mode.first << ": " << mode.second << "\n";

    return 0;
}