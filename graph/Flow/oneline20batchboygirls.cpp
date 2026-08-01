

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

Edge& give_edge2(int u, int v, vector<vector<Edge>> &org_graph){
    for(auto &e : org_graph[u]){
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

    
    cin>>m>>n;

    int x, y;
    cin>>y>>x;

    graph.resize(x+y+2);

    parent.resize(x+y+2);
    parentEdge.resize(x+y+2);

    int p;
    cin>>p;

    for(int i=0; i<p; i++){
        int u, v;
        cin>>u>>v;
        addEdge(u+1, x+v, m);
    }

    for(int i=0; i<y; i++){


        addEdge(0, i+1, n);

    }

    for(int i=0; i<x; i++){
        addEdge(y+1+i, x+y+1, n);
    }



    vector<vector<Edge>> org_graph=graph;

    int s, t;
    s=0;
    t=x+y+1;

    cout<<maxFlow(s, t)<<endl;


    for(int i=1; i<=y; i++){

        for(auto &e : org_graph[i]){

            auto &f=give_edge1(i, e.v);

            int flow=e.capacity-f.capacity;

            if(flow > 0) printf("(%d,%d) -> %d dances\n", i - 1, e.v - y - 1, flow);
            


        }


    }


}