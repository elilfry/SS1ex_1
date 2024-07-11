#ifndef KOSARAJU_HPP
#define KOSARAJU_HPP

#include "graph.hpp"
#include <stack>

class Kosaraju {
    void fillOrder(Graph &graph, int v, bool visited[], std::stack<int> &Stack);

public:
    void printSCCs(Graph &graph);
};

#endif

