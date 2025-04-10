#include <iostream>
using namespace std;

#define INF 1e9 

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

class DistanceVectorRouting {
private:
    int V;
    vector<Edge> edges;

public:
    DistanceVectorRouting(int vertices) {
        V = vertices;
    }

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
        edges.push_back(Edge(dest, src, weight)); 
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INF);
        vector<int> nextHop(V, -1);  
        dist[src] = 0;
        nextHop[src] = src;

        // Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int w = edges[j].weight;

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    nextHop[v] = (nextHop[u] == src) ? v : nextHop[u]; // Track next hop
                }
            }
        }

        // Print Routing Table
        cout << "Routing Table for Node " << src << ":\n";
        cout << "Destination\tNext Hop\tCost\n";
        cout << "---------------------------------\n";
        for (int i = 0; i < V; i++) {
            if (i == src) {
                cout << i << "\t\t" << "-" << "\t\t" << 0 << "\n"; 
            } else if (dist[i] == INF) {
                cout << i << "\t\t" << "-" << "\t\t∞\n";
            } else {
                cout << i << "\t\t" << nextHop[i] << "\t\t" << dist[i] << "\n";
            }
        }
        cout << "---------------------------------\n";
    }

    void calculateRoutingTables() {
        for (int i = 0; i < V; i++) {
            bellmanFord(i);
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of nodes and links: ";
    cin >> V >> E;

    DistanceVectorRouting dvr(V);

    cout << "Enter edges (source destination cost):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dvr.addEdge(u, v, w);
    }

    dvr.calculateRoutingTables();

    return 0;
}
