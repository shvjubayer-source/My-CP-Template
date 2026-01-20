// https://codeforces.com/contest/2144/problem/C
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

const ll M=998244353;

map<tuple<int,int,int>, ll> dp;

vi a(106), b(106);


ll solverX(int prev_a, int prev_b, int n){

    if(n<0) return 1;


    auto it=make_tuple(prev_a, prev_b, n);
    if(dp.count(it)) return dp[it];

    ll ans=0;

    if(a[n]<=prev_a && b[n]<=prev_b){
        ans=(ans+solverX(a[n], b[n], n-1))%M;
    }

    if(b[n]<=prev_a &&  a[n]<=prev_b){

        ans=(ans+solverX(b[n], a[n], n-1 ))%M;
    
    }

    if(a[n]>prev_a && b[n]>=prev_b) return 0;

    if(b[n]>prev_a && a[n]>prev_b) return 0;

    return dp[it]= ans;
}



void solve(){
    int n;
    cin>>n;

    f(i, 0, n-1) cin>>a[i];
    f(i, 0, n-1) cin>>b[i];

    dp.clear();

    ll ans=solverX(1e9, 1e9, n-1);


    cout<<ans<<endl;
}

int main(){
    fastio;
    test solve();
    return 0;
}