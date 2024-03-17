#include <iostream>
#include <vector>

using namespace std;

float backpack_limit = 8;

struct Item {
  string name;
  float weight;
};

vector<Item> items = {
  {"Shoes", 1.5f},
  {"Sleeping bag", 2.0f},
  {"Jacket", 1.5f},
  {"Beans", 1.5f},
  {"Towel", 1.0f},
  {"Underwear", 0.6f},
  {"Water bottle", 1.5f},
  {"Book", 0.5f},
  {"First-aid kit", 0.7f},
  {"Flashlight", 0.2f},
  {"Map", 0.1f}
};

void printItems(const vector<float>& selected) {
  cout << "Selected items: ";
  for (float i : selected) {
    cout << items[i].name << ", ";
  }
  cout << endl;
}

float backpack_limit = 8;
void exhaustiveSearch(int index, vector<float>& selected, float current_weight) {
  if (index == items.size()) {
    if (current_weight <= backpack_limit && current_weight >= backpack_limit*0.8) {
      cout << "Total weight: " << current_weight << " lbs" << endl;  // Specify unit
      printItems(selected);
      cout << endl;
    }
    return;
  }

  selected.push_back(index);
  exhaustiveSearch(index + 1, selected, current_weight + items[index].weight);
  selected.pop_back();

  exhaustiveSearch(index + 1, selected, current_weight);
}

int main() {
  cout << "Backpack limit: " << backpack_limit << " lbs" << endl;
  cout << "Finding optimal packing..." << endl;
  vector<float> selected;
  exhaustiveSearch(0, selected, 0);
  return 0;
}
