#include <bits/stdc++.h>
using namespace std;

int n, m;

int INF=1e9;

struct State{
    int d;
    int to;
    int used;

    bool operator<(const State &other) const{
        return d > other.d;
    }


};


int main(){
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        g[u].push_back({v, wt});
    }

    vector<vector<int>> dist(n+1, vector<int>(3, INF));

    priority_queue<State> pq;
    dist[1][0]=0;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int d=it.d;
        int u=it.to;
        int used=it.used;

        if(d>dist[u][used]) continue; // lazy detetion

        for(auto &i : g[u]){
            int vertex=i.first;
            int cost=i.second;


            // no coupon
            if(dist[vertex][used]>cost+d){
                dist[vertex][used]=cost+d;

                pq.push({dist[vertex][used], vertex, used});
            }

            // use one coupon
            if(used<2){
                if(dist[vertex][used+1]>d+(cost/2)){
                    dist[vertex][used+1]=d+(cost/2);
                    pq.push({dist[vertex][used+1], vertex, used+1});
                }
            }

            // use both coupon
            if(used==0){
                if(dist[vertex][2]>d+((cost/2)/2)){

                    dist[vertex][2]=d+((cost/2)/2);
                    pq.push({dist[vertex][2], vertex, 2});
                }

            }
        }

    }

    int ans=min({dist[n][0], dist[n][1], dist[n][2]});

    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}