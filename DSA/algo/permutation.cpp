#include <bits/stdc++.h>



void getPermutations(int a[], int size, int n, std::vector<std::vector<int>> &permutations) {
	if (size == 1) {
        std::vector<int> perm(a, a+n);
        permutations.push_back(perm);
		return;
	}

	for (int i = 0; i < size; i++) {
		getPermutations(a, size - 1, n, permutations);

		if (size % 2 == 1) {
            int temp = a[0];
            a[0] = a[size-1];
            a[size-1] = temp;
        } else {
            int temp = a[i];
            a[i] = a[size-1];
            a[size-1] = temp;
        }
	}
}

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof a / sizeof a[0];
    std::vector<std::vector<int>> permutations;
	getPermutations(a, n, n, permutations);
    
    for (std::vector<int> v : permutations) {
        for (int n : v) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}
