#include "kosaraju.hpp"
#include "graph.hpp"
#include <iostream>
#include <vector>



/*
how to run
$ cd Q1
$ make
$ ./kosaraju_scc

example:
$ ././kosaraju_scc
$ 5 5
$ 5 5
Enter edge 1 (u v): 1 2
Enter edge 2 (u v): 2 3
Enter edge 3 (u v): 3 1
Enter edge 4 (u v): 3 4
Enter edge 5 (u v): 4 5
Strongly Connected Components are:
5 
1 3 2 
4 

*/

void Kosaraju::fillOrder(Graph &graph, int v, bool visited[], std::stack<int> &Stack) { //this function is used to fill the stack with the vertices
    visited[v] = true;

    for (int u : graph.getAdj()[v])
        if (!visited[u])
            fillOrder(graph, u, visited, Stack);

    Stack.push(v);
}

void Kosaraju::printSCCs(Graph &graph) { //this function is used to print the strongly connected components
    std::stack<int> Stack;
    int V = graph.getVertices();
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(graph, i, visited, Stack);

    Graph gr = graph.getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            std::vector<int> component;
            gr.DFSUtilWrapper(v, visited, component);
            for (int i : component)
                std::cout << i + 1 << " "; // הוספת 1 כדי להציג את הקודקודים מ-1 ולא מ-0
            std::cout << std::endl;
        }
    }

    delete[] visited;
}

