#include <bits/stdc++.h>
using namespace std;


int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1; i<=m; i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        g[v1].push_back({v2, w});
    }

    int source; cin>>source;

    // cout<<"working"<<endl;

    // int dis[n+1];
    vector<int> dis(n+1, INT_MAX), parent(n+1, -1);


    int src=source;
    dis[src]=0;

    priority_queue<pair<int,int>> pq;

    pq.push({0, src});

    int ok=1;

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int u=x.second;
        int d=-x.first;

        for(auto y:g[u]){
            int v = y.first;
            int w = y.second;

            if(dis[v] > d+w){
                dis[v]=d+w;
                pq.push({-dis[v], v});
                parent[v]=u;
            }

        }

        if(u==source && ok==1){

            dis[u]=INT_MAX; 
            ok=2;
        }
    }


    cout<<dis[source]<<endl;

    // vector<




    return 0;
}