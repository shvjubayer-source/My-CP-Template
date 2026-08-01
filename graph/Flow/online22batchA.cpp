#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
    bool original;
};

vector<vector<Edge>> graph;
vector<int> parent;
vector<int> parentEdge;
int n, m;

void addEdge(int u, int v, int cap){

    graph[u].push_back({v, cap, (int)graph[v].size(), true});

    graph[v].push_back({u, 0, (int)graph[u].size()-1, false});
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

bool findPath(int u, vector<int>& path){

    path.push_back(u);

    if(u==n)
        return true;


    for(auto &e: graph[u]){

        // only original edges
        // and edge must have flow
        if(e.original && e.capacity==0){

            // remove this used flow
            e.capacity= -1;


            if(findPath(e.v,path))
                return true;

            // backtrack
            e.capacity=0;
        }
    }


    path.pop_back();

    return false;
}

void solve(int t){

    cin>>n>>m;

    graph.assign(n+1,{});
    parent.assign(n+1,-1);
    parentEdge.assign(n+1,-1);


    for(int i=0;i<m;i++){

        int u,v;

        cin>>u>>v;

        addEdge(u,v,1);
    }


    int ans=maxFlow(1,n);


    cout<<"Case "<<t<<": "<<ans<<"\n";


    if(ans==0){

        cout<<"No escape route possible! The Professor needs a new plan.\n";
        return;
    }


    for(int i=0;i<ans;i++){

        vector<int> path;

        findPath(1,path);


        for(int j=0;j<path.size();j++){

            if(j)
                cout<<" -> ";

            cout<<path[j];
        }

        cout<<"\n";
    }
}


int main(){
    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        solve(i);
    }

}