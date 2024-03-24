#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAX_CHAR = 256;  // Assuming ASCII characters

std::vector<int> shiftTable(const char* pat, int m) {
  std::vector<int> shift(MAX_CHAR, m);  // Default shift is pattern length

  // Pre-compute shifts for characters in pattern
  for (int i = 0; i < m - 1; i++) {
    shift[(unsigned char)pat[i]] = m - 1 - i;
  }
  return shift;  // Return the shift values
}

int horspoolMatching(const char* text, const char* pat) {
  int n = strlen(text);
  int m = strlen(pat);

  std::vector<int> shift = shiftTable(pat, m);

  int i = m - 1;
  while (i < n) {
    int j = 0;
    while (j < m && text[i - j] == pat[m - 1 - j]) {
      j++;
    }

    // Pattern match found
    if (j == m) {
      return i - m + 1;
    }

    // Shift the pattern based on the character at the current position
    i += std::max(shift[(unsigned char)text[i]], m - j);
  }

  // Pattern not found
  return -1;
}

int main() {
  const char* text = "BESS KNEW ABOUT BAOBABS";
  const char* pattern = "BAOBAB";

  int index = horspoolMatching(text, pattern);

  if (index == -1) {
    std::cout << "Can't find pattern" << std::endl;
  } else {
    std::cout << "Pattern found at index: " << index << std::endl;
  }

  return 0;
}
