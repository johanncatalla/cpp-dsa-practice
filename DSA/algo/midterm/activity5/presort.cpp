#include <iostream>
#include <vector>
#include <algorithm>

void quickSortHelper(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int left = low; 
        int right = high - 1; 

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
        quickSortHelper(arr, low, left - 1);
        quickSortHelper(arr, left + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

void findSmallestLargestPresorting(std::vector<int> &arr, int n) {
    // Sort the array in ascending order
    quickSort(arr);

    // Smallest element is at the beginning
    int smallest = arr[0];

    // Largest element is at the end
    int largest = arr[n - 1];

    std::cout << "Smallest element: " << smallest << std::endl;
    std::cout << "Largest element: " << largest << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 31, 10, 12, -1, 9, 8};
    findSmallestLargestPresorting(arr, arr.size());
    return 0;
}

