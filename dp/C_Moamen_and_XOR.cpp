// https://codeforces.com/problemset/problem/1557/C
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

ll add(ll a, ll b){
    return ((a % M) + (b % M)) % M;
}

ll mull(ll a, ll b){
    return ((a % M) * (b % M)) % M;
}

ll multiIter(ll n, ll x){
    ll result = 1;
    while(x > 0){
        if(x % 2 == 1) result = (result * n) % M;
        n = (n * n) % M;
        x = x / 2;
    }
    return result;
}


void solve(){
    int n, k;
    cin >> n >> k;

    vv(dp, ll, k + 1, 2);

    // dp[][0] and > xor
    // dp[][1] and = xor

    dp[k][1] = 1;

    for(ll i = k - 1; i >= 0; i--){

        dp[i][0] = mull(multiIter(2, n), dp[i + 1][0]);

        if(n % 2 == 0) dp[i][0] = add(dp[i][0], dp[i + 1][1]);

        dp[i][1] = mull(multiIter(2, n - 1) - (n % 2 == 0), dp[i + 1][1]);

        if(n % 2 == 1) dp[i][1] = add(dp[i][1], dp[i + 1][1]);

    }

    cout << add(dp[0][1], dp[0][0]) << nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}