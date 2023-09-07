#include <iostream>

float getArrayMean(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum/size;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int arr[size] = {};
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element #" << i+1 << ": ";
        std::cin >> arr[i];
    }

    float res = getArrayMean(arr, size);

    printf("The mean is: %.2f", res);
}
