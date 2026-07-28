#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;

int capacity[MAX][MAX];
int parent[MAX];
int n;
int m;

// Find an augmenting path using BFS
bool bfs(int s, int t)
{

    vector<bool> visited(MAX, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && capacity[u][v] > 0)
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);

                if (v == t)
                    return true;
            }
        }
    }

    return false;
}

// Ford-Fulkerson (Edmonds-Karp)
int maxFlow(int source, int sink)
{
    int flow = 0;

    while (bfs(source, sink))
    {
        int pathFlow = 1e9;

        // Find bottleneck
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }

        // Update residual graph
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        flow += pathFlow;
    }

    return flow;
}

int main(){

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        capacity[u][v]=wt;
    }

    int s, t;
    cin>>s>>t;
    // s=0;
    // t=n-1;

    cout<<maxFlow(s, t)<<endl;

    return 0;
}