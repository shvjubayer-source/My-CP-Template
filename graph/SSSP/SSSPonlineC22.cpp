#include <bits/stdc++.h>
using namespace std;

int n, m, f, total_students;



int main(){
    cin>>n>>m>>f;


    vector<int> capacity(n+1);
    vector<vector<pair<int,int>>> g(n+1);

    for(int i=1; i<=n; i++) cin>>capacity[i];

    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        g[u].push_back({v, wt});
    }

    cin>>total_students;


    // int dist[n+1];
    vector<pair<int,int>> dis(n+1);
    
    for(int i=1; i<=n; i++){
        dis[i].first=INT_MAX;
        dis[i].second=i;
    }

    int src=1;
    dis[src].first=0;

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

            if(dis[v].first > d+w){
                dis[v].first=d+w;
                pq.push({-dis[v].first, v});
            }

        }
    }

    sort(dis.begin()+1, dis.end());


    for(int i=1; i<=n; i++){
        if(total_students<=0) break;

        int mn=min(total_students, capacity[dis[i].second]);

        for(int j=1; j<=mn; j++) cout<<dis[i].first+f<<" ";

        total_students-=mn;
    }

    // for(int i=1; i<=n; i++){
    //     cout<<i<<' '<<dis[i]<<endl;
    // }


    return 0;
}