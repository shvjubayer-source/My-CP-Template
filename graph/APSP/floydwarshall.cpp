//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;

#define ll long long

 
const ll INF = 1e15; // much bigger than any possible path
const int N = 530;

 
void solve() {
    int n, m, q;
    cin>>n>>m>>q;
    
    vector<vector<ll>> g(n, vector<ll>(n, INF));

    for(int i=1; i<=n; i++) g[i][i]=0;
 
    for(int i=1; i<=m; i++){
        int v1, v2;
        ll w;
        cin >> v1 >> v2 >> w;
        g[v1][v2] = min(g[v1][v2], w);
        g[v2][v1] = min(g[v2][v1], w);
    }
 
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                g[i][j]=min(g[i][j], g[i][k] + g[k][j]);
    


    while(q--){
        int l, r;
        cin>>l>>r;

        if(g[l][r]>=INF) cout<<-1<<"\n";
        else cout<<g[l][r]<<"\n";
    }
}
 
int main() {
    solve();
    return 0;
}