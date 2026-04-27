// https://codeforces.com/problemset/problem/1498/C
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

int n, k;

ll dp[1005][1005][2];

ll dpSolve(int grid, int i, int r){
    if(grid==0 || grid>n) return 0;
    if(i==1) return 0;


    if(dp[grid][i][r]!=-1) return dp[grid][i][r];

    ll ans=0;

    if(r==1){
        ans=(ans+1+dpSolve(grid-1, i-1, 0))%M;
        ans=(ans+dpSolve(grid+1, i, r))%M;
    }else{
        ans=(ans+1+dpSolve(grid+1, i-1, 1))%M;
        ans=(ans+dpSolve(grid-1, i, r))%M;
    }


    return dp[grid][i][r] = ans;
}

void solve(){
    cin>>n>>k;

    memset(dp, -1, sizeof(dp));

    ll ans=(1+dpSolve(1, k, 1))%M;

    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}