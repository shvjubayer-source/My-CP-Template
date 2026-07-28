#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;


int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1; i<=m; i++){
        int v1, v2, w;
        g[v1].push_back({v2, w});
    }

    int dis[n+1];
    
    for(int i=1; i<=n; i++) dis[i]=INT_MAX;

    int src=1;
    dis[src]=0;

    priority_queue<pair<int,int>> pq;

    pq.push({0, src});


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
            }

        }
    }

    for(int i=1; i<=n; i++){
        cout<<i<<' '<<dis[i]<<endl;
    }

    return 0;
}