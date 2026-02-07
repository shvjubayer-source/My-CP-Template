// https://codeforces.com/problemset/problem/1195/C
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define vll vector<long long>
#define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ge(i) get<i> // get<i>(t);
#define edge(v) g[v].size()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl;
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

ll dp[100005][3];

vi a(100005), b(100005);

ll solverX(int n, int x){
    if(n==0) return 0;

    if(dp[n][x]!=-1) return dp[n][x];


    ll ans=0;
    
    if(x==1){
        ans=max(ans, solverX(n-1, 2)+a[n]);
        ans=max(ans, solverX(n-1, 1));

    }else{
        ans=max(ans, solverX(n-1, 1)+b[n]);
        ans=max(ans, solverX(n-1, 2));
    }


    return dp[n][x] = ans;


}


void solve(){

    int n;
    cin>>n;

    f(i, 1, n) cin>>a[i];
    f(i, 1, n) cin>>b[i];


    memset(dp, -1, sizeof(dp));

    ll ans=max(solverX(n, 1), solverX(n, 2));

    cout<<ans<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}