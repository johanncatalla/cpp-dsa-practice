#include <iostream>

std::pair<int, int> findMinMax(int arr[], int low, int high) {
  // Base case: single element array
  if (low == high) {
    return std::make_pair(arr[low], arr[low]);
  }

  // Divide the array into two halves
  int mid = low + (high - low) / 2;

  // Recursively find min and max in each half
  std::pair<int, int> left = findMinMax(arr, low, mid);
  std::pair<int, int> right = findMinMax(arr, mid + 1, high);

  // Combine results: minimum and maximum of left and right subarrays
  return std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

int main() {
  int arr[] = {1, 2, 31, 10, 12, -1, 9, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::pair<int, int> minMax = findMinMax(arr, 0, n - 1);
  std::cout << "Smallest element: " << minMax.first << std::endl;
  std::cout << "Largest element: " << minMax.second << std::endl;

  return 0;
}
