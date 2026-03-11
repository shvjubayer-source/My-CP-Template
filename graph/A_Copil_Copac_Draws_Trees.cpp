// https://codeforces.com/problemset/problem/1830/A

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
#define nl '\n'
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;

void dfs(int vertex, int parent, vi &dp, vi &idx, vector<vector<pair<int,int>>> &g){


    for(auto &child:g[vertex]){
        if(child.first==parent) continue;

        if(idx[vertex]<=child.second) dp[child.first]=dp[vertex];
        else dp[child.first]=dp[vertex]+1;

        idx[child.first]=child.second;

        dfs(child.first, vertex, dp, idx, g);

    }


}


void solve(){
    int n;
    cin>>n;

    vector<vector<pair<int,int>>> g(n+5);
    vi idx(n+5, INT_MAX), dp(n+5, 0);


    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;

        g[v1].pb({v2, i});
        g[v2].pb({v1, i});

    }


    dp[1]=1;

    idx[1]=0;

    dfs(1, 0, dp, idx, g);

    int ans=1;

    f(i, 1, n) ans=max(ans, dp[i]);

    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}