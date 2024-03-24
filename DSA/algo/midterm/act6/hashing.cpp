#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;

class HashTable
{
private:
    int table[TABLE_SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = -1; // Initializing all slots to -1 indicating empty
    }

    void insert(int key)
    {
        int index = key % TABLE_SIZE; // Applying the hash function

        // Handling collisions using linear probing
        while (table[index] != -1)
        {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key; // Inserting the key into the table
    }

    bool search(int key)
    {
        int index = key % TABLE_SIZE; // Applying the hash function
        int comparisons = 1;          // For counting key comparisons

        // Searching for the key, considering collisions
        while (table[index] != key)
        {
            if (table[index] == -1)
                return false; // Key not found
            index = (index + 1) % TABLE_SIZE;
            comparisons++;
        }

        // Key found
        cout << "Number of key comparisons in successful search: " << comparisons << endl;
        return true;
    }

    float averageComparisons()
    {
        int totalComparisons = 0;
        int successfulSearches = 0;

        // Counting total comparisons and successful searches
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != -1)
            {
                int key = table[i];
                int comparisons = 1;
                int index = key % TABLE_SIZE;

                while (table[index] != key)
                {
                    index = (index + 1) % TABLE_SIZE;
                    comparisons++;
                }

                totalComparisons += comparisons;
                successfulSearches++;
            }
        }

        return (float)totalComparisons / successfulSearches;
    }

    void displayTable()
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            cout << i << ": ";
            if (table[i] != -1)
                cout << table[i];
            cout << endl;
        }
    }
};

int main()
{
    int keys[] = {30, 20, 56, 75, 31, 19};
    HashTable hashTable;

    // Inserting keys into the hash table
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i)
        hashTable.insert(keys[i]);

    // Displaying the hash table
    hashTable.displayTable();

    // Searching for a key
    int searchKey;
    int keysToSearch[] = {30, 11, 56, 5, 1, 19};

    for (int i = 0; i < 6; i++)
    {
        searchKey = keysToSearch[i];
        if (hashTable.search(searchKey))
            cout << "Key " << searchKey << " found!\n" << endl;
        else
            cout << "Key " << searchKey << " not found!\n" << endl;
    }

    // Calculating average number of key comparisons
    float avgComparisons = hashTable.averageComparisons();
    cout << "Average number of key comparisons in successful search: " << avgComparisons << endl;

    return 0;
}
