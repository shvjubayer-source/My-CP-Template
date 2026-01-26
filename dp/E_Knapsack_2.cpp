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

int wt[105], val[105];

ll dp[105][100005];

ll solverX(int idx, int value_left){ //this function returns minimum weight requires to achieve value
    if(value_left==0) return 0;
    if(idx<1) return INT_MAX;

    if(dp[idx][value_left]!=-1) return dp[idx][value_left];


    //don't choose
    ll ans=solverX(idx-1, value_left);

    //choose
    if(value_left-val[idx]>=0){
        ans=min(ans, solverX(idx-1, value_left-val[idx])+wt[idx]);
    }

    return dp[idx][value_left]=ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));

    int n, w;
    cin>>n>>w;

    f(i, 1, n) cin>>wt[i]>>val[i];

    int max_val=1e5;
    for(int i=max_val; i>=0; i--){
        if(solverX(n, i)<=w){
            cout<<i<<nl;
            return;
        }
    }


}

int main(){
    fastio;
    solve();
    return 0;
}