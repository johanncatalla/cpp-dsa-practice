#include <iostream>
#include <vector>
#include <algorithm>

void quickSort(std::vector<char>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Choose the high-index Pivot
        int left = low; // Left points to the low index
        int right = high - 1; // Right points to the high index

        while (true) {
            // If the value at the Left is less than the pivot move in the right direction
            while (left <= right && arr[left] < pivot) left++;

            // If the value at the Right is greater than the pivot move in the left direction
            while (left <= right && arr[right] > pivot) right--;

            // If both step 5 and step 6 do not match SWAP Left and Right
            if (left >= right) break;

            std::swap(arr[left], arr[right]);
        }

        // If left ≥ right, the point where they met is a new pivot
        std::swap(arr[left], arr[high]);

        // Recursive calls
        quickSort(arr, low, left - 1);
        quickSort(arr, left + 1, high);
    }
}

void quickSortt(std::vector<char>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<char> arr = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    quickSortt(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    return 0;
}

