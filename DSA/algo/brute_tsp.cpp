#include <iostream>
#include <vector>

/**
 * Recursive function to generate all permutations of an array.
 * @param a: The array to generate permutations for.
 * @param size: The size of the sub-array to generate permutations for.
 * @param n: The total size of the array.
 * @param permutations: A reference to a vector to store the generated permutations.
 */
void getPermutations(int a[], int size, int n, std::vector<std::vector<int>> &permutations) {
	if (size == 1) {
        // Create a vector from the array and add it to the permutations
        std::vector<int> perm(a, a+n);
        permutations.push_back(perm);
		return;
	}

	for (int i = 0; i < size; i++) {
		getPermutations(a, size - 1, n, permutations);

		// Swap elements to generate new permutation
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

/**
 * Function to calculate the total distance of a path.
 * @param path: The path of the travel.
 * @param graph: The adjacency matrix representing the graph.
 * @return: The total distance of the travel.
 */
int calculateTotalDistance(const std::vector<int>& path, const std::vector<std::vector<int>>& graph) {
    int distance = 0;
    int n = path.size();

    // Calculate the distance between each pair of consecutive cities in the path
    for (int i = 1; i < n; ++i) {
        distance += graph[path[i - 1]][path[i]];
    }

    // Add the distance from the last department back to the starting department
    distance += graph[path[n - 1]][path[0]];

    return distance;
}

/**
 * Brute force implementation of the Travelling Salesman Problem.
 * @param graph: The adjacency matrix representing the graph.
 * @return: A pair containing the shortest path and its distance.
 */
std::pair<std::vector<int>, int> shortestPath(const std::vector<std::vector<int>>& graph) {
    int nodes = graph.size();
    
    // Initialize the sequence of departments
    std::vector<int> depts(nodes);
    for (int i = 0; i < nodes; ++i) {
        depts[i] = i;
    }

    // Vector to store all possible paths
    std::vector<std::vector<int>> permutations;
	getPermutations(depts.data(), nodes, nodes, permutations);

    int min_distance = INT_MAX;
    std::vector<int> min_path;

    // Find the path with the minimum distance
    for (const auto& path : permutations) {
        int distance = calculateTotalDistance(path, graph);

        if (distance < min_distance) {
            min_distance = distance;
            min_path = path;
        }
    }

    return {min_path, min_distance};
}

int main() {
    // Distance Matrix
    std::vector<std::vector<int>> graph = {
        {0, 16, 14, 25, 26, 40},
        {13, 0, 19, 21, 18, 30},
        {21, 22, 0, 12, 32, 42},
        {27, 24, 15, 0, 40, 55},
        {20, 18, 27, 35, 0, 19},
        {30, 28, 40, 55, 19, 0}
    };

    // Find the shortest path and its distance
    auto result = shortestPath(graph);

    std::cout << "Best Tour: ";
    for (int city : result.first) {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    std::cout << "Best Distance: " << result.second << std::endl;

    return 0;
}
