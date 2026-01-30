// https://codeforces.com/contest/2188/problem/C
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


bool isSortedIncreasing(vi a, int n){
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}




void solve(){
    int n;
    cin>>n;
    vi a(n), b(n);
    f(i, 0, n-1) cin>>a[i], b[i]=a[i];

    sort(all(b));

    int ok=1;
    int mx=b.back(), mn=b[0];
    int ans=INT_MAX;


    f(i, 0, n-1){
        if(b[i]!=a[i]){
            ok=0;
            
            ans=min(ans, max({mx-a[i], a[i]-mn}));
        }
    }

    if(ok){
        cout<<-1<<nl;
        return;
    }



    cout<<ans<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}