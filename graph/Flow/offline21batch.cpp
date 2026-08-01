//max flow through a vertex

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
};

vector<vector<Edge>> graph;
vector<int> parent;
vector<int> parentEdge;
int n, m;

void addEdge(int u, int v, int cap){
    graph[u].push_back({v, cap, (int)graph[v].size()});
    graph[v].push_back({u, 0, (int)graph[u].size()-1});
}

Edge& give_edge1(int u, int v){
    for(auto &e : graph[u]){
        if(e.v == v)
            return e;
    }

    // throw runtime_error("Edge not found");
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

    
    cin>>n>>m;

    graph.resize(n+1);
    parent.resize(n+1);
    parentEdge.resize(n+1);


    for(int i=0; i<m; i++){
        int u, v, capacity;
        cin>>u>>v>>capacity;
        addEdge(u, v, capacity);
    }

    int s, t;
    cin>>s>>t;

    vector<pair<int,int>> node_flow(n+1);
    for(int i=1; i<=n; i++) node_flow[i].second=i;
    
    vector<vector<Edge>> org_graph=graph;

    int ans=maxFlow(s, t);
    
    for(int i=1; i<=n; i++){

        if(i==s || i==t) 
            continue;

        for(auto &e : org_graph[i]){

            // ignore reverse edges
            if(e.capacity == 0)
                continue;

            Edge &residual = give_edge1(i, e.v);

            int used_flow = e.capacity - residual.capacity;

            node_flow[i].first += used_flow;
        }
    }

    
    sort(node_flow.begin(), node_flow.end());

    int mx_flow=node_flow[n].first;

    for(int i=n; i>=1; i--){
        if(node_flow[i].first==mx_flow){
            printf("%d %d\n", node_flow[i].second, mx_flow);

        }else break;;
    }




    // cout<<maxFlow(s, t)<<endl;
}