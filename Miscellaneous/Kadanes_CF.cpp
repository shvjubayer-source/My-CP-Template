//https://codeforces.com/contest/2158/problem/C
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

    vll L(n), R(n);

    f(i, 0, n-1){
        if(i==0) L[i]=a[i];
        else{
            if(L[i-1]>=0) L[i]=L[i-1]+a[i];
            else L[i]=a[i];
        }
    }

    for(int i=n-1; i>=0; i--){
        if(i==n-1) R[i]=a[i];
        else{
            if(R[i+1]<0) R[i]=a[i];
            else R[i]=R[i+1]+a[i];
        }
    }

    if(k%2==0){
        cout<<*max_element(all(L))<<nl;
    }else{
        ll sum=LLONG_MIN;
        f(i, 0, n-1) sum=max(sum, L[i]+R[i]-a[i]+b[i]);


        cout<<sum<<nl;
    }

}

int main(){
    fastio;
    test solve();
    return 0;
}