//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll INF = 1e15; // much bigger than any possible path
const int N = 530;
vector<vector<double>> g(N, vector<double>(N, 0));
 
void solve() {
    int n;
    cin>>n;

    vector<string> name(n+1);
    map<string, int> id;

    for(int i=1; i<=n; i++){
        cin>>name[i];

        id[name[i]]=i;
    }

    int m;
    cin>>m;

    for(int i=1; i<=m; i++){
        string a, b;
        double r;
        cin>>a>>r>>b;

        int u=id[a];
        int v=id[b];


        g[u][v]=max(g[u][v], r);
    }


    f(k, 1, n)
        f(i, 1, n)
            f(j, 1, n)
                g[i][j]=max(g[i][j], g[i][k] * g[k][j]);
 

    bool found=false;

    for(int i=1; i<=n; i++){
        if(g[i][i]>1){
            cout<<name[i]<<endl;
            found=true;
        }
    }

    if(!found) cout<<"No Arbitrage"<<endl;
    
}
 
int main() {
    fastio;
    solve();
    return 0;
}