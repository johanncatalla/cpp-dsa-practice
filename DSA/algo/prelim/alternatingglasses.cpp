#include <iostream>
#include <vector>
using namespace std;

void alternateGlasses(vector<bool> &glasses, int n)
{
    // Base case: if there's only one pair of glasses, they're already in the correct order
    if (n == 1)
    {
        return;
    }

    // Recursive case: solve the problem for the first n-1 pairs of glasses
    alternateGlasses(glasses, n - 1);

    // Find the last filled glass (should be even index and filled)
    int lastFilled = -1;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (i % 2 != 0 && glasses[i])
        {
            lastFilled = i;
            break;
        }
    }

    // Find the last empty glass (should be odd index and empty)
    int lastEmpty = -1;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (i % 2 == 0 && !glasses[i])
        {
            lastEmpty = i;
            break;
        }
    }

    // Swap if both positions are found
    if (lastFilled != -1 && lastEmpty != -1)
    {
        swap(glasses[lastFilled], glasses[lastEmpty]);
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

    vector<bool> random = {true, true, false, true, false, false};

    // Print the initial state of the glasses
    cout << "The glasses before swapping:" << endl;
    for (bool filled : random)
    {
        cout << (filled ? 1 : 0) << ' ';
    }
    cout << "\n"
         << endl;

    // Call the function to alternate the glasses
    alternateGlasses(random, 3);

    // Print the final state of the glasses
    cout << "The glasses after swapping:" << endl;
    for (bool filled : random)
    {
        cout << (filled ? 1 : 0) << ' ';
    }
    cout << "\n"
         << endl;

    return 0;
}
