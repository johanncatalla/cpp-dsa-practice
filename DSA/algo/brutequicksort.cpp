#include <iostream>
#include <vector>

std::vector<char> quickSort(std::vector<char> exampleVector) {
    int size = exampleVector.size();
    char pivot = exampleVector[size-1];
    std::vector<char> res = {};

    


    return exampleVector;
}

int main() {
    std::vector<char> example = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    std::vector<char> res = quickSort(example);
    return 0;
}