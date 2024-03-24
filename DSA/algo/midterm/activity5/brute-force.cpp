#include <iostream>
#include <vector>

void findSmallestLargestBruteForce(std::vector<int> arr, int n) {
    int smallest = arr[0], largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    std::cout << "Smallest element: " << smallest << std::endl;
    std::cout << "Largest element: " << largest << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 31, 10, 12, -1, 9, 8};
    findSmallestLargestBruteForce(arr, arr.size());
    return 0;
}
