#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> node_values;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        node_values.resize(V);
    }

    void setNodeValue(int node, int value) {
        node_values[node] = value;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << "Node: " << v << " - Value: " << node_values[v] << "\n";

        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startNode) {
        vector<bool> visited(V, false);
        cout << "Initial DFS " << startNode << ":\n";
        DFSUtil(startNode, visited);
    }
};

int main() {
    Graph g(5);

    g.setNodeValue(0, 10);
    g.setNodeValue(1, 20);
    g.setNodeValue(2, 30);
    g.setNodeValue(3, 40);
    g.setNodeValue(4, 50);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.DFS(0);

    return 0;
}
