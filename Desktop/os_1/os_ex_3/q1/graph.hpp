#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <vector>

class Kosaraju;  // Forward declaration

class Graph {
    int V; //number of vertices
    std::list<int> *adj;
    void DFSUtil(int v, bool visited[], std::vector<int> &component);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    Graph getTranspose();
    int getVertices() const { return V; }
    std::list<int>* getAdj() const { return adj; }
    void DFSUtilWrapper(int v, bool visited[], std::vector<int> &component);

    friend class Kosaraju;  // Declare Kosaraju as a friend class
};

#endif

