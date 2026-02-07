// https://cses.fi/problemset/task/1192
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
 
const int N=1004;
 
vv(a, char, N, N);
 
 
void dfs(int i, int j){
    a[i][j]='#';
 
    if(a[i+1][j]=='.') dfs(i+1, j);
    if(a[i][j+1]=='.') dfs(i, j+1);
    if(a[i-1][j]=='.') dfs(i-1, j);
    if(a[i][j-1]=='.') dfs(i, j-1);
 
 
}
 
 
void solve(){
    int n, m;
    cin>>n>>m;
 
    f(i, 1, n) f(j, 1, m) cin>>a[i][j];
 
    int ans=0;
    f(i, 1, n){
        f(j, 1, m){
            if(a[i][j]=='.'){
                ans++;
                dfs(i, j);
            }
        }
    }
 
    cout<<ans<<endl;
 
}
 
int main(){
    fastio;
    solve();
    return 0;
}