#include "graph.hpp"
#include "kosaraju.hpp"
#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
     while (true) { // Keep asking for input until valid
            std::cout << "Enter edge " << i + 1 << " (u v): ";
            std::cin >> u >> v;
            if (u == 0 || v == 0) {
                std::cout << "Invalid vertex value: 0. Please enter values greater than 0.\n";
                continue; // Ask for input again
            }
            break; // Valid input, exit the loop
        }
        g.addEdge(u - 1, v - 1); 
    }

    Kosaraju kosaraju;
    std::cout << "Strongly Connected Components are:\n";
    kosaraju.printSCCs(g);

    return 0;
}

