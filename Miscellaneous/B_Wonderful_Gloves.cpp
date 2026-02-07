// https://codeforces.com/contest/2096/problem/B
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
    int n, k;
    cin>>n>>k;

    vi a(n), b(n);
    f(i, 0, n-1) cin>>a[i];
    f(i, 0, n-1) cin>>b[i];

    f(i, 0, n-1){
        int mx=max(a[i], b[i]);
        int mn=min(a[i], b[i]);
        a[i]=mx;
        b[i]=mn;
    } 

    sort(all(b), greater<int>());

    ll ans=accumulate(all(a), 0LL);

    f(i, 0, k-2) ans+=b[i];


    cout<<ans+1<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}


