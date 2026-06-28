// https://codeforces.com/contest/166/problem/E
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

const int M = 1000000007;


void solve(){
    ll n;
    cin>>n;


    //0 in D
    //1 not in D

    ll D=1;
    ll ABC=0;

    f(i, 1, n){
        // dp[i][0]=(dp[i][0]+dp[i-1][1])%M;
        // dp[i][1]=(dp[i][1]+dp[i-1][0]*3LL)%M;

        // dp[i][1]=(dp[i][1]+dp[i-1][1]*2LL)%M;

        ll Dx=(ABC)%M;
        ll ABCx=(D*3+ABC*2)%M;


        D=Dx;
        ABC=ABCx;

    }


    cout<<D<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}