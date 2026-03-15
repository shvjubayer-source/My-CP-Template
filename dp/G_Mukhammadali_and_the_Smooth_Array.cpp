// https://codeforces.com/contest/2167/problem/G
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
    vi a(n), c(n);
    f(i, 0, n-1) cin>>a[i];
    f(i, 0, n-1) cin>>c[i];

    ll total_cost=accumulate(all(c), 0LL);
    ll maxValid_cost=0;
    ll dp[n];


    f(i, 0, n-1){
        dp[i]=c[i];
        f(j, 0, i-1){
            if(a[j]<=a[i]) dp[i]=max(dp[i], c[i]+dp[j]);
        }
        maxValid_cost=max(maxValid_cost, dp[i]);
    }


    cout<<total_cost-maxValid_cost<<endl;
}

int main(){
    fastio;
    test solve();
    return 0;
}

 