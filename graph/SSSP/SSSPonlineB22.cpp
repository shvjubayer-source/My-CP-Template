#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;


const int INF = 1e9;

int n, m, k, b, e;

void bellmanFord(vector<vector<pair<int,int>>> &g,vector<int> &emergency_city, vector<int> &capital_city, vector<int> &blocked_city) {
    int V = n;

    vector<int> dist(V+1, INF);

    for(int i=1; i<=n; i++){
        if(capital_city[i]){
            dist[i]=0;
        }
    }


    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 1; u <= V; u++) {
            if (dist[u] == INF || blocked_city[u])
                continue;

            for (auto edge : g[u]) {
                int v = edge.first;
                int w = edge.second;

                if(blocked_city[v]) continue;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycle
    for (int u = 1; u <= V; u++) {
        if (dist[u] == INF || blocked_city[u])
            continue;

        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if(blocked_city[v]) continue;

            if (dist[u] + w < dist[v]) {
                cout << "Abyss Detected\n";
                return;
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= V; i++) {
        if(emergency_city[i]){

            if(dist[i]!=INF)cout<<dist[i]<<' ';
            else cout<<"INF"<<' ';
        }
    }

    cout<<endl;
}



int main(){
    cin>>n>>m>>k>>b>>e;

    vector<vector<pair<int,int>>> g(n+1);

    vector<int> capital_city(n+1), emergency_city(n+1), blocked_city(n+1);

    for(int i=1; i<=k; i++){
        int x; cin>>x;
        capital_city[x]=1;
    }

    for(int i=1; i<=b; i++){
        int x; cin>>x;
        blocked_city[x]=1;
    }

    for(int i=1; i<=e; i++){
        int x; cin>>x;
        emergency_city[x]=1;
    }

    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        g[u].push_back({v, wt});
    }




    bellmanFord(g, emergency_city, capital_city, blocked_city);



    return 0;
}