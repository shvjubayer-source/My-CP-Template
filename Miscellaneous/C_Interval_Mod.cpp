// https://codeforces.com/contest/2215/problem/A
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

// 1 minimum %p
// 2 minimum %q
// 3 minimum (%q)%p

void solve(){
    int n, k, p, q;
    cin>>n>>k>>p>>q;

    if(p>q) swap(p, q);

    ll ans=LLONG_MAX;

    vi a(n+1), mn(n+1);
    vll pSum(n+1);



    f(i, 1, n){
        cin>>a[i];
        mn[i]=min({a[i]%p, a[i]%q, (a[i]%q)%p});
        pSum[i]=mn[i]+pSum[i-1];
    }

    // 1

    ll sum=0;
    f(i, 1, k) sum+=a[i]%p;
    ans=min(ans, sum+pSum[n]-pSum[k]);

    for(int i=k+1, j=2; i<=n; i++, j++){
        sum+=a[i]%p;
        sum-=a[j-1]%p;

        ans=min(ans, sum+pSum[n]-pSum[i]+pSum[j-1]);
    }

    // 2
    sum=0;

    f(i, 1, k) sum+=a[i]%q;

    ans=min(ans, sum+pSum[n]-pSum[k]);

    for(int i=k+1, j=2; i<=n; i++, j++){
        sum+=a[i]%q;
        sum-=a[j-1]%q;

        ans=min(ans, sum+pSum[n]-pSum[i]+pSum[j-1]);
    }



    // 3
    sum=0;

    f(i, 1, k) sum+=(a[i]%q)%p;

    ans=min(ans, sum+pSum[n]-pSum[k]);

    for(int i=k+1, j=2; i<=n; i++, j++){
        sum+=(a[i]%q)%p;
        sum-=(a[j-1]%q)%p;

        ans=min(ans, sum+pSum[n]-pSum[i]+pSum[j-1]);
    }





    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}