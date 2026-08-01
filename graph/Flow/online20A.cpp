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

vector<vector<int>> paths;


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

                if(e.v==t){
                    vector<int> emni;

                    for(int cur=t; cur!=s; cur=parent[cur]){
                        emni.push_back(cur);
                    }

                    emni.push_back(s);

                    reverse(emni.begin(), emni.end());


                    paths.push_back(emni);
                    return true;
                } 

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


// bool findPath(int u, vector<int>& path){

//     path.push_back(u);

//     if(u==n)
//         return true;


//     for(auto &e: graph[u]){

//         // only original edges
//         // and edge must have flow
//         if(e.original && e.capacity==0){

//             // remove this used flow
//             e.capacity= -1;


//             if(findPath(e.v,path))
//                 return true;

//             // backtrack
//             e.capacity=0;
//         }
//     }


//     path.pop_back();

//     return false;
// }




int main(){

    
    cin>>n>>m;

    graph.resize(n+m+2);
    parent.resize(n+m+2);
    parentEdge.resize(n+m+2);

    int my_total_stickers;
    cin>>my_total_stickers;

    vector<int> my_stickers(m+1);

    for(int i=1; i<=my_total_stickers; i++){
        int x; cin>>x;
        my_stickers[x]++;
    }

    // vector<vector<int>> friends_stickers(n+1);
    vector<vector<int>> friends_stickers(n+1, vector<int>(m+1));


    for(int i=1; i<=n; i++){
        int x;
        cin>>x;

        for(int j=1; j<=x; j++){
            int y;
            cin>>y;

            friends_stickers[i][y]++;
        }
    }

    //source=0
    //stickers 1 to m
    //friends m+1 to m+n
    //sink m+n+1
    
    //source to stickers
    for(int i=1; i<=m; i++){
        addEdge(0, i, my_stickers[i]);
    }


    // stikcers to friend

    for(int i=1; i<=m; i++){

        for(int j=1; j<=n; j++){
            int num=j+m;

            if(friends_stickers[j][i]==0){
                addEdge(i, num, 1);
            }else if(friends_stickers[j][i]>1){

                addEdge(num, i, friends_stickers[j][i]-1);

            }
        }
    }


    //sticker to sink
    for(int i=1; i<=m; i++){

        addEdge(i, m+n+1, 1);

    }






    int s, t;
    s=0;
    t=m+n+1;

    int ans=maxFlow(s, t);
    cout<<ans<<endl;
    




}