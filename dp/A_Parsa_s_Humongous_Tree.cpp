// https://codeforces.com/problemset/problem/1528/A
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



void dfs(ll vertex, ll parent, vector<vector<ll>> &g, vector<vector<ll>> &a, vector<vector<ll>> &dp){


    for(auto &child: g[vertex]){
        if(child==parent) continue;

        dfs(child, vertex, g, a, dp);

        dp[vertex][0] += max( abs( a[vertex][0] - a[child][0]) + dp[child][0], abs( a[vertex][0] - a[child][1]) + dp[child][1]);
        dp[vertex][1] += max( abs( a[vertex][1] - a[child][0]) + dp[child][0], abs( a[vertex][1] - a[child][1]) + dp[child][1]);

    }


}


void solve(){
    int n;
    cin>>n;


    vv(a, ll, n+1, 2);

    f(i, 1, n) cin>>a[i][0]>>a[i][1];

    vv(g, ll, n+1, 0);

    f(i, 1, n-1){
        ll v1, v2;
        cin>>v1>>v2;

        g[v1].pb(v2);
        g[v2].pb(v1);
    }

    vv(dp, ll, n+1, 2);

    dfs(1, -1, g, a, dp);

    cout<<max(dp[1][0], dp[1][1])<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}