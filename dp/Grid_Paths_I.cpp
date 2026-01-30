// https://cses.fi/problemset/task/1638
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

int dx[2]={ 1, 0};
int dy[2]={ 0, 1};

int n;
vv(a, char, 1010, 1010);
vector<vector<ll>> dp(1010, vector<ll>(1010, -1));

ll solverX(int i, int j){
    if(i==n && j==n) return 1;
    if(i<=0 || j<=0 || i>n || j>n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=0;

    f(k, 0, 1) if(a[i+dx[k]][j+dy[k]]!='*') ans=(ans+solverX(i+dx[k], j+dy[k]))%M;

    return dp[i][j] = ans;


}

void solve(){
    cin>>n;

    f(i, 1, n) f(j, 1, n) cin>>a[i][j];

    if(a[1][1]=='*') cout<<0<<endl;
    else cout<<solverX(1, 1)<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}



// void solve(){
//     int n;
//     cin>>n;
 
//     vv(a, char, n+3, n+3);
//     vv(dp,  ll, n+3, n+3);
 
//     f(i, 1, n) f(j, 1, n) cin>>a[i][j];
 
//     if(a[1][1]!='*') dp[1][1]=1;
 
//     f(i, 1, n){
//         f(j, 1, n){
//             if(a[i][j]=='*') continue;
//             f(k, 0, 1){
//                 dp[i][j]=(dp[i][j]+dp[i+dx[k]][j+dy[k]])%M;
//             }
//         }
//     }
 
 
 
//     cout<<dp[n][n]<<endl;
// }
 
// int main(){
//     fastio;
//     solve();
//     return 0;
// }