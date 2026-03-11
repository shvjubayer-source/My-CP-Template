// https://codeforces.com/problemset/problem/414/B
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
int n, k;

int dp[2005][2005];

ll dpSolve(int idx, int num){
    if(idx==k) return 1;
    if(dp[idx][num]!=-1) return dp[idx][num];
    
    ll ans=0;

    for(int i=num; i<=n; i+=num){

        ans=(ans+dpSolve(idx+1, i))%M;

    }


    return dp[idx][num]=ans;
}

void solve(){
    cin>>n>>k;

    ll ans=0;

    memset(dp, -1, sizeof(dp));

    f(i, 1, n) ans=(ans+dpSolve(1, i))%M;
    

    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}