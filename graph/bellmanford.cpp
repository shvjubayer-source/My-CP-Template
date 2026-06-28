#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void bellmanFord(vector<vector<pair<int, int>>> &g, int source) {
    int V = g.size();

    vector<int> dist(V, INF);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            if (dist[u] == INF)
                continue;

            for (auto edge : g[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycle
    for (int u = 0; u < V; u++) {
        if (dist[u] == INF)
            continue;

        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                cout << "Negative weight cycle detected!\n";
                return;
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        cout << "Distance from " << source << " to " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }
}


int main(){
    int V = 5;
    vector<vector<pair<int,int>>> g(V);

    // g[u].push_back({v, weight});
    g[0].push_back({1, -1});
    g[0].push_back({2, 4});
    g[1].push_back({2, 3});
    g[1].push_back({3, 2});
    g[1].push_back({4, 2});
    g[3].push_back({2, 5});
    g[3].push_back({1, 1});
    g[4].push_back({3, -3});

    bellmanFord(g, 0);

}