// https://codeforces.com/problemset/problem/1475/E
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

ll add(ll a, ll b, ll m=M) { return ((a%m) + (b%m) + m) % m;} // (a+b)%m
ll sub(ll a, ll b, ll m=M) { return ((a%m) - (b%m) + m) % m;} // (a-b)%m
ll mul(ll a, ll b, ll m=M) { return ((a%m) * (b%m)) % m;}     // (a*b)%m

ll modexp(ll a, ll e, ll m=M){ // (a^e)%m
    a%=m; ll r=1;

    while(e){
        if(e&1) r=mul(r, a, m);
        a=mul(a, a, m);
        e>>=1;
    }

    return r;
}

ll inv(ll a, ll m=M) { return modexp(a, m-2, m);} // (a^-1)%m


ll fact(ll n){
    ll ans=1;
    for(ll i=1; i<=n; i++){
        ans=mul(ans, i);
    }

    return ans;
}


ll nCr(ll n, ll r){
    ll up=fact(n);
    ll down=mul(fact(r), fact(n-r));

    return mul(up, inv(down));
}

void solve(){
    int n, k;
    cin>>n>>k;

    map<int, int> m;

    f(i, 1, n){
        int x; cin>>x;
        m[x]++;
    }

    ll ans=1;

    for(auto it=m.rbegin(); it!=m.rend(); it++){
        if(k<=0) break;
        int freq=it->second;

        if(freq<=k){
            k-=freq;
        }else{
            ans=nCr(freq, k);
            break;
        }


    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}