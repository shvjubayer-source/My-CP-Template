//https://codeforces.com/problemset/problem/2114/C
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
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    
    a.erase(unique(a.begin(), a.end()), a.end());
    
    n=a.size();

    //i, 1 -->maximum array including i th element
    //i, 0 -->maximum array excluding i th element

    vv(dp, int, n, 2);

    dp[0][1]=1;
    dp[0][0]=0;


    f(i, 1, n-1){
        if(a[i-1]+1<a[i]){
            dp[i][1]=max(dp[i-1][1]+1, dp[i-1][0]+1);
            dp[i][0]=max(dp[i-1][1], dp[i-1][0]);
        }else{
            dp[i][1]=dp[i-1][0]+1;
        }

        dp[i][0]=max(dp[i-1][1], dp[i-1][0]);
    }

    cout<<max(dp[n-1][0], dp[n-1][1])<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}