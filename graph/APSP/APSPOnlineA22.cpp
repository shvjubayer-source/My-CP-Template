//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF=1e11;
const ll N = 530;

vector<int> getPath(int u, int v, vector<vector<int>> &nxt) {

    vector<int> path;

    if (nxt[u][v] == -1)
        return path;

    while (u != v) {
        path.push_back(u);
        u = nxt[u][v];
    }

    path.push_back(v);

    return path;
}

 
void solve() {
    ll n, m, k, x;
    cin>>n>>m>>k>>x;

    vector<ll> lord_basha(k+1);
    vector<ll> basha_lor(n+1);
    vector<ll> h_rate(k+1);

    vector<vector<int>> nxt(n + 1, vector<int>(n + 1, -1));
    vector<vector<ll>> g(n+1, vector<ll>(n+1, INF));

    for(int i=1; i<=k; i++){
        cin>>lord_basha[i];
        basha_lor[lord_basha[i]]=i;
    } 

    for(int i=1; i<=k; i++) cin>>h_rate[i];
    
    for(int i=1; i<=n; i++) g[i][i]=0, nxt[i][i]=i;
 
    for(int i=1; i<=m; i++){
        ll v1, v2;
        ll w;
        cin >> v1 >> v2 >> w;

        g[v1][v2] = min(g[v1][v2], w);
        g[v2][v1] = min(g[v2][v1], w);

        nxt[v1][v2]=v2;
        nxt[v2][v1]=v1;
    }
 

    // for(int k=1; k<=n; k++){
    //     for(int i=1; i<=n; i++){

    //         for(int j=1; i<=n; j++){

    //         }

    //     }
    // }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if (g[i][k] != INF && g[k][j] != INF && g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
    

    ll X=-1;
    ll minimum_cost=INF;
    ll last_time=INT_MAX;

    for(int i=1; i<=n; i++){

        bool ok=true;
        ll cost=0;
        ll cur_time=0;

        for(int j=1; j<=k; j++){

            ll pos=lord_basha[j];

            if(g[pos][i]>x){
                ok=false;
                break;
            }

            cur_time=max(cur_time, g[pos][i]);
            cost+=g[pos][i]*h_rate[j];
        }


        if(ok && cost<minimum_cost){
            X=i;
            minimum_cost=cost;
            last_time=cur_time;
        }
    }
    
    if(X==-1){
        cout<<"No meeting"<<endl;
        return;
    }

    cout<<X<<" "<<minimum_cost<<" "<<last_time<<endl;

    for (int i = 1; i <= k; i++) {

        vector<int> path = getPath(lord_basha[i], X, nxt);

        for (int j = 0; j < path.size(); j++) {
            if (j) cout << " -> ";
            cout << path[j];
        }

        cout << " " << g[lord_basha[i]][X] * h_rate[i] << "\n";
    }
    // while(q--){
    //     int l, r;
    //     cin>>l>>r;

    //     if(g[l][r]>=INF) cout<<-1<<"\n";
    //     else cout<<g[l][r]<<"\n";
    // }
}
 
int main() {
    solve();
    return 0;
}