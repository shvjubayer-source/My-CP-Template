// https://codeforces.com/contest/2225/problem/D
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

const ll M = 998244353;

// 1 == 1
// 3 == 0



ll zeroCal(ll n){
    if(n%4==3) return (n/4)+2;

    return (n/4)+1;

}

ll oneCal(ll n){
    if(n%4!=0) return (n/4)+1;

    return n/4;
}

void solve(){
    ll n, x;
    cin>>n>>x;

    ll l0=zeroCal(x-1);
    ll l1=oneCal(x-1);

    ll r0=zeroCal(n)-l0;
    ll r1=oneCal(n)-l1;

    ll ans=((l1%M)*(r1%M))%M;

    ans=(ans+((l0%M)*(r0%M))%M)%M;


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}