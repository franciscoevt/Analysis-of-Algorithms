#include <iostream>
#include <vector>
#include <queue>

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

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS traversal starting from node " << startNode << ":\n";

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            cout << "Node: " << currentNode << " - Value: " << node_values[currentNode] << "\n";

            for (int neighbor : adj[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
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

    g.BFS(0);

    return 0;
}
