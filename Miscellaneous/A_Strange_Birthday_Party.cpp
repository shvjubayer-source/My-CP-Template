//https://codeforces.com/problemset/problem/1470/A
//greedy, implementation
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
    int n, m;
    cin>>n>>m;

    vi a(n+1), b(m+1);




    f(i, 1, n) cin>>a[i];
    f(i, 1, m) cin>>b[i];

    
    sort(all(a));

    ll ans=0;

    int r=n;
    int l=1;


    while(r>=1 && l<=m && b[l]<b[a[r]]){
        ans+=b[l];
        l++;
        r--;
    }

    while(r>=1) ans+=b[a[r]], r--;


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}