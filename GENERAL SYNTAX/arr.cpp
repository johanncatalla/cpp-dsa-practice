#include <iostream>
#define N 10

int main() {
	int arr[N], odd[10], even[10], sum, evenL, oddH, evencnt = 0, oddcnt = 0;
	float  avg;
	// Definition
	for (short i = 0; i < N; i++) {
		std::cout << "Enter element " << i << ": ";
		std::cin >> arr[i];
	}

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

        // get highest odd
	oddH = odd[0];
	for (int i = 1; i < oddcnt; i++) {
		if (odd[i] > oddH) {
			oddH = odd[i];
		}
	}

        // lowest even
	evenL = even[0];
	for (int i = 1; i < evencnt: i++) {
		if (even[i] < evenL) {
			evenL = even[i];
		}
	}
	
	std::cout << "Highest odd: " << oddH << "\nLowest Even: " << evenL;
	
	return 0;
}
