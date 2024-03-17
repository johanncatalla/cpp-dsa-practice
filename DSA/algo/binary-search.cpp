#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class ItemStatus {
    Good,
    Usable,
    Bad
};

pair<bool, int> binary_search_inventory(const vector<pair<string, ItemStatus>>& inventory, const string& target_item) {
    int left = 0;
    int right = inventory.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (inventory[mid].first == target_item) {
            return make_pair(true, mid);
        } else if (inventory[mid].first < target_item) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return make_pair(false, -1);
}

void insertionSort(vector<pair<string, ItemStatus>>& inventory) {
    for (int i = 1; i < inventory.size(); i++) {
        pair<string, ItemStatus> current = inventory[i];
        int j = i - 1;

        while (j >= 0 && inventory[j].first > current.first) {
            inventory[j + 1] = inventory[j];
            j--;
        }

        inventory[j + 1] = current;
    }
}

int main() {
    vector<pair<string, ItemStatus>> inventory = {
        {"Lights", ItemStatus::Good},
        {"Sony Camera", ItemStatus::Usable},
        {"Canon Camera", ItemStatus::Good},
        {"HP Computer", ItemStatus::Bad},
        {"Table", ItemStatus::Usable},
        {"Drawing Pad", ItemStatus::Usable},
        {"Drawing Tablet", ItemStatus::Good},
        {"Air Conditioner", ItemStatus::Good},
        {"Office Chair", ItemStatus::Usable},
        {"Printer", ItemStatus::Usable},
        {"Scanner", ItemStatus::Usable},
        {"Desk Lamp", ItemStatus::Good},
        {"Whiteboard", ItemStatus::Usable},    
        {"Telephone", ItemStatus::Good},        
        {"Headset", ItemStatus::Usable},         
        {"Projector", ItemStatus::Good},        
        {"Coffee Machine", ItemStatus::Good},  
        {"Water Dispenser", ItemStatus::Good},   
        {"Filing Cabinet", ItemStatus::Usable},  
        {"Stapler", ItemStatus::Usable},         
        {"Pencil Sharpener", ItemStatus::Usable} 
    };

    // Sort the inventory by item name using insertion sort
    insertionSort(inventory);

    string target_item;
    cout << "Enter item to be searched: ";
    cin >> target_item;

    auto result = binary_search_inventory(inventory, target_item);
    if (result.first) {
        string statusString;
        switch (inventory[result.second].second) {
            case ItemStatus::Good:
                statusString = "Good";
                break;
            case ItemStatus::Usable:
                statusString = "Usable";
                break;
            case ItemStatus::Bad:
                statusString = "Bad";
                break;
        }
        cout << "The item '" << target_item << "' has status: " << statusString << endl;
    } else {
        cout << "The item is not found in the inventory." << endl;
    }

    return 0;
}
