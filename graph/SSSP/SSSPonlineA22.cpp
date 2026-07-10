#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int k, n, m;

vector<pair<int,int>> g[N];



int main(){
    cin>>k>>n>>m;

    for(int i=0; i<m; i++){
        int u, v, t, c;
        cin>>u>>v>>t>>c;


        int real_cost=k*(t)+c;

        g[u].push_back({v, real_cost});
        g[v].push_back({v, real_cost});
    }

    int source, dest;
    cin>>source>>dest;

    int dis[n+1];
    
    for(int i=1; i<=n; i++) dis[i]=INT_MAX;

    int src=source;
    dis[src]=0;

    priority_queue<pair<int,int>> pq;

    pq.push({0, src});

    vector<int> parent(n+1, -1);


    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int u=x.second;
        int d=-x.first;

        for(auto y:g[u]){
            int v = y.first;
            int w = y.second;

            if(u==source){

                if(dis[v]>d+w){
                    dis[v]=d+w;
                    pq.push({-dis[v], v});
                    parent[v]=u;
                }
            }else{

                if(dis[v]>d+w+k){
                    dis[v]=d+w+k;
                    pq.push({-dis[v], v});
                    parent[v]=u;
                }
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     cout<<i<<' '<<dis[i]<<endl;
    // }

    vector<int> ans={dest};

    for(int cur=dest; parent[cur]!=-1; cur=parent[cur]){

        ans.push_back(parent[cur]);

    }

    reverse(ans.begin(), ans.end());

    for(int i=0; i<(int)ans.size()-1; i++){
        cout<<ans[i]<<"->";
    }

    cout<<dest<<endl;

    cout<<dis[dest]<<endl;

    return 0;
}