#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9  

class Graph {
private:
    int V;
    vector<vector<pair<int, int> > > adjList; 

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF);
        vector<int> nextHop(V, -1);
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));
        nextHop[src] = src;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i].first;
                int weight = adjList[u][i].second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                    nextHop[v] = (nextHop[u] == src) ? v : nextHop[u];
                }
            }
        }

       
        cout << "Routing Table for Node " << src << ":\n";
        cout << "Destination\tNext Hop\tCost\n";
        cout << "---------------------------------\n";
        for (int i = 0; i < V; i++) {
            if (i == src) {
                cout << i << "\t\t" << "-" << "\t\t" << 0 << "\n"; 
            } else if (dist[i] == INF) {
                cout << i << "\t\t" << "-" << "\t\t∞\n"; // Unreachable node
            } else {
                cout << i << "\t\t" << nextHop[i] << "\t\t" << dist[i] << "\n";
            }
        }
        cout << "---------------------------------\n";
    }

    void calculateRoutingTables() {
        for (int i = 0; i < V; i++) {
            dijkstra(i);
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of nodes and links: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter edges (source destination cost):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.calculateRoutingTables();

    return 0;
}
