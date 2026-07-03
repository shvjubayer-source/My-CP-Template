#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    
    vector<bool> vis(n+1);

    set<pair<int,int>> s;

    s.insert({0,  1});

    long long cost=0;

    while(!s.empty()){
        auto it=s.begin();
        int wt=it->first;
        int v=it->second;

        s.erase(it);

        if(vis[v]) continue;

        vis[v]=true;

        cost+=wt;

        for(auto &child : g[v]){
            if(!vis[child.first]) s.insert({child.second, child.first});
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    cout<<cost<<endl;

}