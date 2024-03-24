#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    cout << "Disk 1 moved from " << from_rod << " to " << to_rod << endl;
    return;
  }

  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  cout << "Disk " << n << " moved from " << from_rod << " to " << to_rod << endl;
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
  int num_disks;
  cout << "Enter the number of disks: ";
  cin >> num_disks;

  towerOfHanoi(num_disks, 'A', 'C', 'B'); 

  return 0;
}
