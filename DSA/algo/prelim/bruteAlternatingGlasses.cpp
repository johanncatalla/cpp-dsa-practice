#include <iostream>
#include <vector>
using namespace std;

void alternateGlasses(vector<bool> &glasses, int n)
{
  for (int i = 0; i < 2 * n; i++)
  {
    if (i % 2 != 0 && glasses[i] == true)
    {
      for (int j = 0; j < 2 * n; j++)
      {
        if (j % 2 == 0 && glasses[j] == false)
        {
          swap(glasses[i], glasses[j]);
        }
      }
    }
    else if (i % 2 == 0 && glasses[i] == false)
    {
      for (int k = 0; k < 2*n; k++) 
      {
        if (k % 2 != 0 && glasses[k] == true)
        {
          swap(glasses[i], glasses[k]);
        }
      }
    }
  }
}

int main()
{
  int n;
  cout << "\nEnter n: ";
  cin >> n;
  cout << endl;

  // Create a vector of glasses, with the first n filled (true)
  // and the rest empty (false)
  vector<bool> glasses(2 * n, false);
  fill(glasses.begin(), glasses.begin() + n, true);

  // Print the initial state of the glasses
  cout << "The glasses before swapping:" << endl;
  for (bool filled : glasses)
  {
    cout << (filled ? 1 : 0) << ' ';
  }
  cout << "\n"
       << endl;

  // Call the function to alternate the glasses
  alternateGlasses(glasses, n);

  // Print the final state of the glasses
  cout << "The glasses after swapping:" << endl;
  for (bool filled : glasses)
  {
    cout << (filled ? 1 : 0) << ' ';
  }
  cout << "\n"
       << endl;

  return 0;
}
