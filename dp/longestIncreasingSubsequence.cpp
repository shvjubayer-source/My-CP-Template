// https://cses.fi/problemset/task/1145?

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

// int LIS(vi &a){
//     int n=a.size();
//     vi dp(n, 1);
//     int ans=1;


//     for(int i=0; i<n; i++){
//         for(int j=0; j<i; j++){
//             if(a[j]<a[i]){
//                 dp[i]=max(dp[i], dp[j]+1);
//             }
//         }
//         ans=max(ans, dp[i]);

//     }

//     return ans;
// }

// void solve(){
//     int n;
//     cin>>n;

//     vi a(n);
//     f(i, 0, n-1) cin>>a[i];


//     cout<<LIS(a)<<nl;

// }

// int main(){
//     fastio;
//     solve();
//     return 0;
// }



int LIS(vector<int>& a) {
    vector<int> lis;

    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size();
}


void solve(){
    int n;
    cin>>n;

    vi a(n);
    f(i, 0, n-1) cin>>a[i];


    cout<<LIS(a)<<nl;

}


int main(){
    fastio;
    solve();
    return 0;
}