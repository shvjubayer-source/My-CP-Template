// https://codeforces.com/contest/118/problem/D
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

const ll M = 100000000;

ll dp[110][110][11][11];

ll n1, n2, k1, k2;

ll solverX(ll n1, ll n2, ll f, ll h){
    if(n1==0 && n2==0) return 1;
    if(dp[n1][n2][f][h]!=-1) return dp[n1][n2][f][h];

    ll x=0, y=0;
    if(n1>0 && f>0) x=solverX(n1-1, n2, f-1, k2);
    if(n2>0 && h>0) y=solverX(n1, n2-1, k1, h-1);


    return dp[n1][n2][f][h] = (x+y)%M;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin>>n1>>n2>>k1>>k2;

    cout<<solverX(n1, n2, k1, k2)<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}