#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

void depthFirstSearch(const std::string& node,
                     std::map<std::string, std::vector<std::string>>& graph,
                     std::map<std::string, bool>& visited,
                     std::map<std::string, bool>& recStack,
                     std::stack<std::string>& stack) {

  // Mark the current node as visited
  visited[node] = true;

  // Mark the current node as being in the recursion stack
  recStack[node] = true;

  // Iterate over the neighbors of the current node
  for (const auto& neighbor : graph[node]) {
    // If the neighbor is not visited, perform DFS on it
    if (!visited[neighbor]) {
      depthFirstSearch(neighbor, graph, visited, recStack, stack);
    } else if (recStack[neighbor]) {
      // If the neighbor is already in the recursion stack, it indicates a cycle
      throw std::runtime_error("The provided graph is not a DAG.");
    }
  }

  // Push the current node onto the stack after all its neighbors are processed
  stack.push(node);

  // Unset the recursion stack mark for the current node
  recStack[node] = false;
}

std::vector<std::string> topologicalSort(std::map<std::string, std::vector<std::string>>& graph) {
  // Maps to keep track of visited nodes and nodes in the recursion stack
  std::map<std::string, bool> visited;
  std::map<std::string, bool> recStack;

  // Stack to store the topological order
  std::stack<std::string> stack;

  // Iterate over each node in the graph
  for (const auto& node : graph) {
    // If the node hasn't been visited yet, perform DFS on it
    if (!visited[node.first]) {
      depthFirstSearch(node.first, graph, visited, recStack, stack);
    }
  }

  // Create a vector to store the topological order
  std::vector<std::string> result;

  // While the stack is not empty, pop elements and add them to the result vector
  while (!stack.empty()) {
    result.push_back(stack.top());
    stack.pop();
  }

  // Return the vector containing the topological sort
  return result;
}

int main() {
    std::map<std::string, std::vector<std::string>> graph1 = {
        {"A", {"B", "C"}},
        {"B", {"G", "E"}},
        {"C", {"F"}},
        {"D", {"A", "B", "C", "F", "G"}},
        {"E", {}},
        {"F", {}},
        {"G", {"E", "F"}}
    };

    std::map<std::string, std::vector<std::string>> graph2 = {
        {"A", {"B"}},
        {"B", {"C"}},
        {"C", {"D"}},
        {"D", {"G"}},
        {"E", {"A"}},
        {"F", {"B", "C", "E", "G"}},
        {"G", {"E"}}
    };

    try {
        auto result1 = topologicalSort(graph1);
        std::cout << "Topological Sort: ";
        for (const auto& node : result1) {
            std::cout << node << " ";
        }
        std::cout << std::endl;

        auto result2 = topologicalSort(graph2);
        std::cout << "Topological Sort: ";
        for (const auto& node : result2) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Topological Sort: " << e.what() << std::endl;
    }

    return 0;
}
