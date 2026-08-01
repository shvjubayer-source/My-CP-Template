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

Edge* give_edge1(int u, int v){
    for(auto &e : graph[u]){
        if(e.v == v)
            return &e;
    }

    return nullptr;
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

bool dfsFlow(int u, int t, vector<vector<Edge>> &flowGraph,
             vector<int> &path, vector<int> &edgeIndex){

    if(u==t){
        path.push_back(t);
        return true;
    }

    path.push_back(u);

    for(int i=0;i<flowGraph[u].size();i++){

        if(flowGraph[u][i].capacity<=0) continue;

        edgeIndex.push_back(i);

        if(dfsFlow(flowGraph[u][i].v,t,flowGraph,path,edgeIndex))
            return true;

        edgeIndex.pop_back();
    }

    path.pop_back();
    return false;
}

int main(){

    
    cin>> n>>m;

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

    vector<vector<Edge>> original = graph;
    int ans=maxFlow(s, t);




    cout<<"Maximum Flow = "<<ans<<"\n\n";

    vector<vector<Edge>> flowGraph(n+1);

    // Build graph containing actual flows
    for(int u=1;u<=n;u++){

        for(int i=0;i<original[u].size();i++){

            Edge &orig = original[u][i];

            // Ignore reverse edges
            if(orig.capacity==0) continue;

            Edge &res = graph[u][i];

            int flow = orig.capacity - res.capacity;

            if(flow>0)
                flowGraph[u].push_back({orig.v,flow,-1});
        }
    }

    cout<<"Flow Paths:\n";

    while(true){

        vector<int> path;
        vector<int> edgeIndex;

        if(!dfsFlow(s,t,flowGraph,path,edgeIndex))
            break;

        int pathFlow=INT_MAX;

        for(int i=0;i<edgeIndex.size();i++){
            int u=path[i];
            pathFlow=min(pathFlow,flowGraph[u][edgeIndex[i]].capacity);
        }

        for(int i=0;i<path.size();i++){
            cout<<path[i];
            if(i+1<path.size()) cout<<" -> ";
        }
        cout<<"   Flow = "<<pathFlow<<"\n";

        for(int i=0;i<edgeIndex.size();i++){
            int u=path[i];
            flowGraph[u][edgeIndex[i]].capacity-=pathFlow;
        }
    }

}