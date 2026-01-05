// https://atcoder.jp/contests/dp/tasks/dp_a
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



void solve(){
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    vll dp(n, 1000000000);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=2; j++){
            if(i-j>=0){
                dp[i]=min(dp[i], abs(a[i]-a[i-j])+dp[i-j]);
            }
        }
    }

    cout<<dp[n-1]<<nl;

}

int main(){
    fastio;
    solve();
    return 0;
}


// ll solverX(int n, vi &a, vll &dp){
//     if(n==0) return 0;

//     if(dp[n]!=-1) return dp[n];

//     ll ans=LLONG_MAX;
//     ans=min(ans, abs(a[n]-a[n-1])+solverX(n-1, a, dp));
//     if(n-2>=0) ans=min(ans, abs(a[n]-a[n-2])+solverX(n-2, a, dp));

//     return dp[n]=ans;

// }


// void solve(){
//     int n;
//     cin>>n;    

//     vi a(n);
//     f(i, 0, n-1) cin>>a[i];

//     vll dp(n, -1);

//     cout<<solverX(n-1, a, dp)<<nl;
// }


// int main(){
//     fastio;
//     solve();
//     return 0;
// }