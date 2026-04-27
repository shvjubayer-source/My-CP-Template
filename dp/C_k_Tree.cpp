// https://codeforces.com/contest/431/problem/C
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

int n, k, d;

int dp[101][2];

ll dpSolve(int sum, int f){
    if(sum<0) return 0;

    if(sum==0){
        if(f==0) return 0;
        else return 1;
    }

    if(dp[sum][f]!=-1) return dp[sum][f];

    ll ans=0;

    f(i, 1, k){

        int v=f;

        if(i>=d) v=1;

        ans=(ans+dpSolve(sum-i, v))%M;
        if(sum-i<0) break;
    }

    

    return  dp[sum][f]=ans;;

}


void solve(){
    cin>>n>>k>>d;

    memset(dp, -1, sizeof(dp));

    ll ans=dpSolve(n, 0);


    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}