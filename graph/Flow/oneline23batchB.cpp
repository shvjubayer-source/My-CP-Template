//min cut solution
#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
};

struct newEdge{
    int u, v, capacity;
};

vector<vector<Edge>> graph;
vector<int> parent;
vector<int> parentEdge;
int n, m;

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

    cin>>n>>m;

    graph.resize(n+1);
    parent.resize(n+1);
    parentEdge.resize(n+1);

    for(int i=0; i<m; i++){
        int u, v, capacity;
        cin>>u>>v>>capacity;
        addEdge(u, v, capacity);
    }

    int p;
    cin>>p;

    vector<newEdge> extraEdge(p);

    for(int i=0; i<p; i++) cin>>extraEdge[i].u>>extraEdge[i].v>>extraEdge[i].capacity;


    maxFlow(1, n);

    //finding min-cut
    set<int> s;

    queue<int> q;
    s.insert(1);
    q.push(1);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for (int i=0; i<graph[u].size(); i++) {
            Edge &e=graph[u][i];

            if(e.capacity>0 && s.find(e.v)==s.end()){
                s.insert(e.v);
                q.push(e.v);
            } 
        }
    }

    for(int i=0; i<p; i++){
        if(s.find(extraEdge[i].u)!=s.end() && s.find(extraEdge[i].v)==s.end()){
            cout<<i+1<<endl;
            return 0;
        }
    }
}





// Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// struct Edge{
//     int v, capacity, rev;
// };

// struct newEdge{
//     int u, v, capacity;
// };

// vector<vector<Edge>> graph;
// vector<int> parent;
// vector<int> parentEdge;
// int n, m;

// void addEdge(int u, int v, int cap){
//     graph[u].push_back({v, cap, (int)graph[v].size()});
//     graph[v].push_back({u, 0, (int)graph[u].size()-1});
// }

// bool bfs(int s, int t){
//     for(auto &i:parent) i=-1;

//     queue<int> q;
//     q.push(s);
//     parent[s]=s;

//     while(!q.empty()){
//         int u=q.front();
//         q.pop();

//         for (int i=0; i<graph[u].size(); i++) {
//             Edge &e=graph[u][i];

//             if(parent[e.v]==-1 && e.capacity>0) {
//                 parent[e.v]=u;
//                 parentEdge[e.v]=i;

//                 if(e.v==t) return true;

//                 q.push(e.v);
//             }
//         }
//     }

//     return false;
// }

// int maxFlow(int s, int t){
//     int flow=0;

//     while(bfs(s, t)){

//         int pathFlow=INT_MAX;

//         for (int v=t; v!=s; v=parent[v]) {
//             int u=parent[v];
//             Edge &e=graph[u][parentEdge[v]];
//             pathFlow=min(pathFlow, e.capacity);
//         }

//         for (int v=t; v!=s; v=parent[v]) {
//             int u=parent[v];

//             Edge &e=graph[u][parentEdge[v]];
//             e.capacity-=pathFlow;

//             graph[v][e.rev].capacity+=pathFlow;
//         }

//         flow+=pathFlow;
//     }

//     return flow;
// }

// int main(){

    
//     cin>>n>>m;

//     // graph.resize(n+1);
//     // parent.resize(n+1);
//     // parentEdge.resize(n+1);

//     vector<newEdge> edges(m);

//     for(int i=0; i<m; i++){
//         cin>>edges[i].u>>edges[i].v>>edges[i].capacity;
//         // addEdge(edges[i].u, edges[i].v, 0);
//     } 

//     int p;
//     cin>>p;

//     vector<newEdge> extraEdge(p);

//     for(int i=0; i<p; i++){
//         cin>>extraEdge[i].u>>extraEdge[i].v>>extraEdge[i].capacity;
//         // addEdge(extraEdge[i].u, extraEdge[i].v, 0);
//     } 
    
//     int ans=INT_MIN;
//     int idx=-1;

//     for(int i=0; i<p; i++){
//         graph.clear();
//         parent.clear();
//         parentEdge.clear();

//         graph.resize(n+1);
//         parent.resize(n+1);
//         parentEdge.resize(n+1);

//         for(int j=0; j<m; j++) addEdge(edges[j].u, edges[j].v, edges[j].capacity);

//         addEdge(extraEdge[i].u, extraEdge[i].v, extraEdge[i].capacity);

//         int temp=maxFlow(1, n);
//         if(temp>ans){
//             idx=i+1;
//             ans=temp;
//         }
//         // ans=max(ans, maxFlow(1, n));
//     }


//     cout<<idx<<endl;
// }