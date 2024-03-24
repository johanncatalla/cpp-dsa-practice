#include <iostream>
#include <vector>

using namespace std;

vector<char> distributionCountingSort(vector<char> data) {
  // Create a count array to store the frequency of each character
  const int ALPHABET_SIZE = 4;
  vector<int> counts(ALPHABET_SIZE, 0);
  for (char charr : data) {
    counts[charr - 'a']++;
  }

  // Perform cumulative sum to get starting indices for each character in the output
  for (int i = 1; i < ALPHABET_SIZE; i++) {
    counts[i] += counts[i - 1];
  }

  // Create a new vector to store the sorted characters
  vector<char> sortedData(data.size());

  // Fill the sorted vector from the back, using the counts to determine positions
  for (int i = data.size() - 1; i >= 0; i--) {
    int charIndex = data[i] - 'a';
    counts[charIndex]--;
    sortedData[counts[charIndex]] = data[i];
  }
  return sortedData;
}

int main() {
  vector<char> data = {'b', 'c', 'd', 'c', 'b', 'a', 'a', 'b'};
  vector<char> sortedData = distributionCountingSort(data);

  cout << "Sorted data: ";
  for (char charr : sortedData) {
    cout << charr << " ";
  }
  cout << endl;

  return 0;
}

    
