//bipartite matching

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
};

vector<vector<Edge>> graph;
vector<int> parent;
vector<int> parentEdge;
int n, k, m;

void addEdge(int u, int v, int cap){
    graph[u].push_back({v, cap, (int)graph[v].size()});
    graph[v].push_back({u, 0, (int)graph[u].size()-1});
}

bool bfs(int s, int t){
    for(auto &i:parent) i=-1;

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

    
    // cin>> n>>m;
    int n, k, m;
    cin>>n>>k>>m;

    graph.resize(n+2);
    parent.resize(n+2);
    parentEdge.resize(n+2);


    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        addEdge(u+1, v+1, 1);
    }

    for(int i=1; i<=k; i++) addEdge(0, i, 1);
    for(int i=k+1; i<=n; i++) addEdge(i, n+1, 1);

    int s, t;
    s=0;
    t=n+1;

    cout<<maxFlow(s, t)<<endl;

    for(int i=1; i<=k; i++){
    
        for(auto &e : graph[i]){
    
            if(e.capacity==0){
    
                cout<<i-1<<' '<<e.v-1<<endl;
    
            }
    
        }
    
    }
}