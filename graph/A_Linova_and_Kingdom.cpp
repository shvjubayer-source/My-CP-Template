// https://codeforces.com/contest/1336/problem/A
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define edge(v) g[v].size()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl endl
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;

void dfs(int vertex, int parent, vi &depth, vector<vector<int>> &g, vi &childrens, vi &emni){


    for(int &child:g[vertex]){
        if(child==parent) continue;

        depth[child]=depth[vertex]+1;

        dfs(child, vertex, depth, g, childrens, emni);

        childrens[vertex]+=childrens[child]+1;
    }
    // childrens[vertex]++;

    emni[vertex]=depth[vertex]-childrens[vertex];

}


void solve(){
    int n, k;
    cin>>n>>k;

    vv(g, int, n, 0);

    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;

        v1--; v2--;
        // watch(v1);
        // watch(v2);
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // f(i, 1, n){
    //     cout<<i<<" : ";

    //     for(int &j:g[i]) cout<<j<<" ";

    //     cout<<nl;
    // }

    vi depth(n);
    vi childrens(n);
    vi emni(n);

    dfs(0, -1, depth, g, childrens, emni);    

    sort(all(emni), greater<int>());

    ll ans=0;

    f(i, 0, k-1) ans+=emni[i];

    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}

// 1 -1  1  -1   1

// -1 1  -1  -1 1