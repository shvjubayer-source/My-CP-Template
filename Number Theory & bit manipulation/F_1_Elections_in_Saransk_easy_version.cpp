// https://codeforces.com/contest/2236/problem/F1
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

ll mul(ll a, ll b, ll m=M) { return ((a%m) * (b%m)) % m;} 

void solve(){
    ll n, x;
    cin>>n>>x;

    vll a(n);
    f(i, 0, n-1) cin>>a[i];

    ll ans=1;

    map<ll, ll> m;

    f(i, 0, n-1){
        ll x=a[i];

        while(x%2==0){
            m[2]++;
            x/=2;
        }

        for(ll i=3; i*i<=x; i+=2){
            while(x%i==0){
                m[i]++;
                x/=i;
            }
        }

        if(x>1) m[x]++;
    }


    for(auto &i:m) ans=mul(ans, (1+i.second));

    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}