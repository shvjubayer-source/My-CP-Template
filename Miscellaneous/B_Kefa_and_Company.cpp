// https://codeforces.com/contest/580/problem/B
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

ll range_sum(vll &psum, ll l, ll r){
    if(l==0) return psum[r];
    return psum[r]-psum[l-1];
}

void solve(){
    ll n, d;
    cin>>n>>d;

    vector<pair<ll, ll>> friends(n);

    f(i, 0, n-1) cin>>friends[i].first>>friends[i].second;

    sort(all(friends));

    ll ans=0;
    vll pSum(n); pSum[0]=friends[0].second;

    f(i, 1, n-1) pSum[i]=pSum[i-1]+friends[i].second;
    

    for(int l=0, r=0; r<n && l<n; ){

        while(r<n && friends[r].first-friends[l].first<d){
            ans=max(ans, range_sum(pSum, l, r));
            r++;
        }

        l++;
    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}