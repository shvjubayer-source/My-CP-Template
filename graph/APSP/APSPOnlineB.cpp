
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll INF = 1e11; 

 
void solve() {
    ll n, m;
    cin >> n >> m;

    ll g[n+1][n+1][2];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<2; k++) g[i][j][k]=INF;

    
    f(i, 0, n-1) g[i][i][0] = 0;

 
    f(i, 1, m) {
        ll v1, v2, w;
        cin >> v1 >> v2 >> w;

        
        g[v1][v2][0] = min(g[v1][v2][0], w);
    }
    
    ll x, y;
    cin>>x>>y;

    f(i, 0, n-1){
        f(j, 0, n-1){
            if(i==x || i==y || j==x || j==y){
                g[i][j][1]=g[i][j][0];
            }
        }
    }


    f(k, 0, n-1)
        f(i, 0, n-1)
            f(j, 0, n-1){

                ll a = g[i][k][0];
                ll b = g[k][j][0];
                ll c = g[i][k][1];
                ll d = g[k][j][1];
                    
                g[i][j][0]=min(g[i][j][0], a+b);
                
                g[i][j][1]=min(g[i][j][1], c+b);
                g[i][j][1]=min(g[i][j][1], a+d);
                g[i][j][1]=min(g[i][j][1], c+d);
            }

    ll q;
    cin>>q;
 
    while(q--){
        ll l, r;
        cin>>l>>r;

        if(g[l][r][1]>=INF) cout<<-1<<"\n";
        else cout<<g[l][r][1]<<"\n";
    }
}
 
int main() {
    fastio;
    solve();
    return 0;
}


// second solution (better one)
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll INF = 1e15; 
const int N = 530;
vector<vector<ll>> g(N, vector<ll>(N, INF));
 
void solve() {
    int n, m;
    cin>>n>>m;
    


    f(i, 0, n-1) g[i][i]=0;
 
    f(i, 1, m){
        int v1, v2;
        ll w;
        cin >> v1 >> v2 >> w;

        g[v1][v2] = min(g[v1][v2], w);
    }
    
    int x, y;
    cin>>x>>y;



    f(k, 1, n)
        f(i, 1, n)
            f(j, 1, n)
                g[i][j]=min(g[i][j], g[i][k] + g[k][j]);
    
    
    int q;
    cin>>q;


    while(q--){
        int l, r;
        cin>>l>>r;

        ll ans=INF;

        ans=min(ans, g[l][x]+g[x][r]);
        ans=min(ans, g[l][y]+g[y][r]);

        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;

    }

}
 
int main() {
    fastio;
    solve();
    return 0;
}