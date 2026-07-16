//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e15; 

void solve() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<ll>> dist0(n, vector<ll>(n, INF));
    vector<vector<ll>> dist1(n, vector<ll>(n, INF));

    for(int i=0; i<n; i++) dist0[i][i]=0;
    for(int i=0; i<n; i++) dist1[i][i]=0;
 
    for(int i=0; i<m; i++){
        ll u, v, wt;
        cin>>u>>v>>wt;

        dist0[u][v]=min(dist0[u][v], wt);
        dist1[u][v]=min(dist1[u][v], wt-1);
    }
 
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                dist0[i][j]=min(dist0[i][j], dist0[i][k]+dist0[k][j]);
                dist1[i][j]=min(dist1[i][j], dist1[i][k]+dist1[k][j]);
            }
    
    int V;
    cin>>V;

    int q;
    cin>>q;

    while(q--){
        int l, r;
        cin>>l>>r;

        ll ans=dist0[l][r];

        ans=min(ans, dist1[l][V]+dist1[V][r]);

        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
 
int main() {
    solve();
    return 0;
}