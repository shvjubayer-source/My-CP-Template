// https://atcoder.jp/contests/dp/tasks/dp_g
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

int cnt=0;

void dfs(int vertex, vector<vector<int>> &g, vi &dp){
    if(dp[vertex]!=0) return;


    int cnt=0;

    for(auto &child : g[vertex]){

        dfs(child, g, dp);
        cnt=max(cnt, dp[child]);
    }

    dp[vertex]=1+cnt;
}



void solve(){
    int n, m;
    cin>>n>>m;

    vv(g, int, n+1, 0);
    vi indegree(n+1);


    f(i, 1, m){
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        indegree[v]++;
    }

    vi dp(n+1);
    int ans=0;

    f(i, 1, n){
        if(indegree[i]==0){
            dfs(i, g, dp);
            ans=max(ans, dp[i]);
        }
    }


    cout<<ans-1<<nl;
    
}

int main(){
    fastio;
    solve();
    return 0;
}