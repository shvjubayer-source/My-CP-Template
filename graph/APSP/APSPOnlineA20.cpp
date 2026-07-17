//solution of cses Shortest Routes II
#include <bits/stdc++.h>
using namespace std;

#define ll long long

 
const ll INF = 1e15; 

void vector_concat(vector<int> &a, const vector<int> &b){
    for(auto &i:b){
        a.push_back(i);
    }
}

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
    int n, m;
    cin>>n>>m;
    
    vector<vector<ll>> g(n+1, vector<ll>(n+1, INF));
    vector<vector<int>> nxt(n+1, vector<int>(n+1, -1));

    for(int i=1; i<=n; i++) g[i][i]=0, nxt[i][i]=i;
 
    for(int i=1; i<=m; i++){
        int v1, v2;
        ll w;

        cin >> v1 >> v2 >> w;

        g[v1][v2] = min(g[v1][v2], w);
        g[v2][v1] = min(g[v2][v1], w);

        nxt[v1][v2]=v2;
        nxt[v2][v1]=v1;
    }
 
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(g[i][k] != INF && g[k][j] != INF && g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        
    int w1, w2;
    cin>>w1>>w2;


    while(true){
        int l, r;
        cin>>l>>r;

        if(l==-1 && r==-1) return;

        ll ans=INF;

        ll cost1 = g[l][w1]+g[w1][w2]+g[w2][r];
        ll cost2 = g[l][w2]+g[w2][w1]+g[w1][r];

        ans=min({ans, cost1, cost2});

        if(ans==INF){
            cout<<"No path from "<<l<<" to "<<r<<" through the Wall Street"<<endl;
            cout<<endl;
            continue;
        }

        cout<<"Shortest Path Weight: "<<ans<<endl;

        vector<int> pathWay;

        if(cost1<cost2){
            vector_concat(pathWay, getPath(l, w1, nxt));
            vector_concat(pathWay, getPath(w1, w2, nxt));
            vector_concat(pathWay, getPath(w2, r, nxt));
        }else{
            vector_concat(pathWay, getPath(l, w2, nxt));
            vector_concat(pathWay, getPath(w2, w1, nxt));
            vector_concat(pathWay, getPath(w1, r, nxt));
        }

        cout<<"Path: ";

        for (int j = 0; j < pathWay.size(); j++) {
            if(j>0 && pathWay[j-1]==pathWay[j]) continue;
            if (j) cout << " ->";
            cout << pathWay[j];
        }

        cout<<endl<<endl;
    }
}
 
int main() {
    solve();
    return 0;
}