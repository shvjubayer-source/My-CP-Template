#include <bits/stdc++.h>
using namespace std;

int INF=1e9;

int n, m, steps;

void bellmanford(vector<vector<pair<int,int>>> &g, int source, vector<int> &dist0, vector<int> &dist1){
    dist0[source]=0;

    for(int i=1; i<=steps; i++){

        vector<int> new0=dist0;
        vector<int> new1=dist1;

        for(int j=1; j<=n; j++){

  


            for(auto &k:g[j]){
                int vertex=k.first;
                int wt=k.second;

                if(dist0[j]!=INF && new0[vertex]>dist0[j]+wt){

                    new0[vertex]=dist0[j]+wt;

                }

                if(dist0[j]!=INF && new1[vertex]>dist0[j]+wt/2){
                    new1[vertex]=dist0[j]+wt/2;
                }


                if(dist1[j]!=INF && new1[vertex]>dist1[j]+wt){
                    new1[vertex]=dist1[j]+wt;
                }

            }

        }

        dist1=new1;
        dist0=new0;


    }

}


int main(){
    // int n, m, k;
    cin>>n>>m>>steps;

    vector<vector<pair<int,int>>> g(n+1);


    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;


        g[u].push_back({v, wt});
    }

    vector<int> dist0(n+1,INF), dist1(n+1,INF);



    bellmanford(g, 1, dist0, dist1);


    if(dist1[n]==INF) cout<<"Not possible"<<endl;
    else cout<<dist1[n]<<endl;

    return 0;
}