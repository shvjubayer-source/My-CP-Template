// https://codeforces.com/problemset/problem/1920/C
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

vector<int> getFactors(int n){
    vector<int> factors;
    for(int i=1; i*i<=n; i++){
        if(n%i==0) {
            factors.push_back(i);
            if(i!=n/i) factors.push_back(n/i);
        }
    }

    return factors;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    vi factors=getFactors(n);


    int ans=0;


    for(auto &j:factors){

        int g=0;

        f(i, j, n-1) g=__gcd(g, abs(a[i]-a[i-j]));

        
        if(g==0 || g>=2) ans++;

    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}