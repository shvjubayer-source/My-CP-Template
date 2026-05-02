// https://codeforces.com/contest/1633/problem/D
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

vi cost(1001, INT_MAX);
ll dp[1001][12*1001]; 
int n, k;

ll dpSolve(int idx, int w, vi &b, vi &c){
    if(idx==0) return 0;

    if(dp[idx][w]!=-1) return dp[idx][w];

    ll x=dpSolve(idx-1, w, b, c); // take

    ll y=-1;

    if(w>=cost[b[idx]]) y=dpSolve(idx-1, w-cost[b[idx]], b, c)+c[idx];



    return dp[idx][w] = max(x, y);
}

void solve(){
    cin>>n>>k;

    vi b(n+1), c(n+1);

    f(i, 1, n) cin>>b[i];
    f(i, 1, n) cin>>c[i];

    memset(dp, -1, sizeof(dp));

    ll ans=dpSolve(n, min(k, 12*n), b, c);

    cout<<ans<<nl;
}

int main(){
    fastio;

    cost[1]=0;

    f(i, 1, 1001){
        f(j, 1, i){
            if((i+i/j)<=1000) cost[i+i/j]=min(cost[i+i/j], cost[i]+1);
        }
    }

    test solve();
    return 0;
}