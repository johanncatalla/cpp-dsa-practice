#include <iostream>
#include <bits/stdc++.h>
#define N 10

int main() {
	int arr[N], odd[5], even[5], sum, evenL, oddH, evencnt = 0, oddcnt = 0;
	float  avg;
	// Definition
	for (short i = 0; i < N; i++) {
		std::cout << "Enter element " << i << ": ";
		std::cin >> arr[i];
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	std::sort(arr, arr + n);
	
	
	// Calculation
	for (short j = 0; j < N; j++) {
		sum += arr[j];
	}
	avg = sum/N;
	
	// odd even
	for (short i = 0; i < N; i++) {
		if (arr[i] % 2 != 0) {
			odd[oddcnt++] = arr[i];
		} else {
			even[evencnt++] = arr[i];
		}
		
	} 
	// Print array
	std::cout << "Array: ";
	for (short  i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	// Print odd
	std::cout << "Odd: ";
	for (short  i = 0; i < oddcnt; i++) {
		std::cout << odd[i] << " ";
	}
	std::cout << std::endl;
	
	// print even
	std::cout << "Even: ";
	for (short  i = 0; i < evencnt; i++) {
		std::cout << even[i] << " ";
	}
	std::cout << std::endl;
	
	// print size
	std::cout << "Size of odd: " << oddcnt << std::endl;
	std::cout << "Size of even: " << evencnt;
	
	
	std::cout  << "\nSum: " << sum << "\n";
	printf("Avg: %.2f\n", avg);
	
	for (short i = 0; i < oddcnt; i++) {
		if (odd[i+1] > odd[i]) {
			oddH = odd[i+1];
		} else {
			oddH = odd[i];
		}
	}

	std::cout << "Highest odd: " << odd[oddcnt-1] << "\nLowest Even: " << even[evencnt-(evencnt)];
	
	return 0;
}
