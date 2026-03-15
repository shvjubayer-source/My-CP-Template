// https://codeforces.com/contest/2167/problem/D
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



vll primenum;

void sieve(int n){
    vector<bool> isPrime(n+1,true); 
    isPrime[0]=isPrime[1]=false;   

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j]=false;
            }
        }
    }


    for (int i=2; i<=n; i++){
        if(isPrime[i]){
            primenum.pb(i);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    vll a(n);

    ll g=0;
    f(i, 0, n-1){
        cin>>a[i];
        g=__gcd(g, a[i]);
    }
    for(int i=0; i<primenum.size(); i++){
        if(g%primenum[i]!=0){
            cout<<primenum[i]<<endl;
            return;
        }
    }

    
}

int main(){
    fastio;
    sieve(100);
    test solve();
    return 0;
}