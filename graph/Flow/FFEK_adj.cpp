#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
};

const int MAX=1005;
vector<Edge> graph[MAX];
int parent[MAX], parentEdge[MAX];

void addEdge(int u, int v, int cap){
    graph[u].push_back({v, cap, (int)graph[v].size()});
    graph[v].push_back({u, 0, (int)graph[u].size()-1});
}

bool bfs(int s, int t){
    memset(parent, -1, sizeof(parent));

    queue<int> q;
    q.push(s);
    parent[s]=s;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for (int i=0; i<graph[u].size(); i++) {
            Edge &e=graph[u][i];

            if(parent[e.v]==-1 && e.capacity>0) {
                parent[e.v]=u;
                parentEdge[e.v]=i;

                if(e.v==t) return true;

                q.push(e.v);
            }
        }
    }

    return false;
}

int maxFlow(int s, int t){
    int flow=0;

    while(bfs(s, t)){

        int pathFlow=INT_MAX;

        for (int v=t; v!=s; v=parent[v]) {
            int u=parent[v];
            Edge &e=graph[u][parentEdge[v]];
            pathFlow=min(pathFlow, e.capacity);
        }

        for (int v=t; v!=s; v=parent[v]) {
            int u=parent[v];

            Edge &e=graph[u][parentEdge[v]];
            e.capacity-=pathFlow;

            graph[v][e.rev].capacity+=pathFlow;
        }

        flow+=pathFlow;
    }

    return flow;
}

int main(){

    int n, m;
    cin>> n>>m;

    while(m--){
        int u, v, capacity;
        cin>>u>>v>>capacity;
        addEdge(u, v, capacity);
    }

    int s, t;
    cin>>s>>t;

    cout<<maxFlow(s, t)<<endl;
}