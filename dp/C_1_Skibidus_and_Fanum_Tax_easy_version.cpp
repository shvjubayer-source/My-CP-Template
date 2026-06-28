// https://codeforces.com/contest/2065/problem/C1
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



void solve(){
    int n, m;
    cin>>n>>m;

    vll a(n+1, INT_MIN);
    vector<vector<bool>> dp(n+1, vector<bool>(2, false));
    dp[0][0]=true;
    dp[0][1]=true;

    f(i, 1, n) cin>>a[i];

    cin>>m;

    f(i, 1, n){
        ll prev_changed=m-a[i-1];
        ll prev=a[i-1];

        ll current_changed=m-a[i];
        ll current=a[i];

        // watch(prev);
        // watch(prev_changed);
        // watch(current);
        // watch(current_changed);

        //unchanged
        if(prev<=current && dp[i-1][0]) dp[i][0]=true;
        if(prev_changed<=current && dp[i-1][1]) dp[i][0]=true;

        //changed
        if(prev<=current_changed && dp[i-1][0]) dp[i][1]=true;
        if(prev_changed<=current_changed && dp[i-1][1]) dp[i][1]=true;



    }


    if(dp[n][1] || dp[n][0]) yes;
    else no;

}

int main(){
    fastio;
    test solve();
    return 0;
}