#include "graph.hpp"
#include <vector>

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[], std::vector<int> &component) {
    visited[v] = true;
    component.push_back(v);

    for (int u : adj[v])
        if (!visited[u])
            DFSUtil(u, visited, component);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        for (int u : adj[v]) {
            g.adj[u].push_back(v);
        }
    }
    return g;
}

//this funcation is used because DFSUtil is private and we want to  save the encapsulation
// we can't call DFSUtil from outside the class so we use this function to call DFSUtil from outside the class

void Graph::DFSUtilWrapper(int v, bool visited[], std::vector<int> &component) { 
    DFSUtil(v, visited, component);
}

