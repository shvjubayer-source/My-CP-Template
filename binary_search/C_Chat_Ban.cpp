// https://codeforces.com/problemset/problem/1612/C
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

ll Dist(ll n){return (n*(n+1))/2;}

void solve(){
    ll n, x;
    cin>>n>>x;



    ll l=1, r=2*n;
    while(l<r){
        ll mid=(l+r)/2;
        ll temp=mid;
        mid--;

        ll sum=0;
        if(mid<=n) sum+=Dist(mid);
        else sum+=Dist(n)+Dist(n-1)-Dist(n-1-(mid-n));
        
        // watch(mid);
        // watch(sum);


        if(sum<x) l=temp+1;
        else r=temp;
        // watch(l);

    }

    l--;
    cout<<l<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}