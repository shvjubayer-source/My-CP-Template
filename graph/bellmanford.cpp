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
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);

    
    for(int i=1; i<=m; i++){
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
        
        g[v1].push_back({v2, wt});
    }

    bellmanFord(g, 0);

}