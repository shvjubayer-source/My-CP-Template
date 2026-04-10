// https://codeforces.com/contest/1418/problem/C
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
const ll INF=1e10;


void solve(){
    int n;
    cin>>n;

    vi a(n+3);

    f(i, 1, n) cin>>a[i];

    vv(dp, ll, n+3, 2);


    dp[n][1]=a[n];

    for(int i=n-1; i>=1; i--){

        dp[i][0]=min(dp[i+1][1], dp[i+2][1]);
        dp[i][1]=min(dp[i+1][0]+a[i], dp[i+2][0]+a[i]+a[i+1]);

    }



    cout<<dp[1][1]<<nl; //because frind's turn is first
}

int main(){
    fastio;
    test solve();
    return 0;
}

//another solution

// #include <bits/stdc++.h>
// using namespace std;
// #define f(i, st, ed) for(int i=st; i<=ed; i++)
// #define ll long long
// #define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
// #define test int t; cin>>t; while(t--)
// #define gcin(s) getline(cin, s);
// #define vi vector<int>
// #define pb push_back
// #define all(v) v.begin(), v.end()
// #define vll vector<long long>
// #define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define ge(i) get<i>
// #define edge(v) g[v].size()
// #define yes cout<<"YES"<<endl
// #define no cout<<"NO"<<endl
// #define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
// //bit manipulation
// #define checkbit(x,n) (x&(1LL<<n))
// #define setbit(x,n) (x=(x|(1LL<<n)))
// #define unsetbit(x,n) (x=(x&(~(1LL<<n))))
// #define togglebit(x,n) (x=(x^(1LL<<n)))

// int n;

// int work(vi &v, int st, vector<vector<int>> &dp, int turn){
//     if(st>n) return 0;

//     if(dp[st][turn]!=-1) return dp[st][turn];


//     if(turn==0) return dp[st][turn] = min(work(v, st+1, dp, 1), work(v, st+2, dp, 1));
//     else return dp[st][turn] =  min(v[st]+work(v, st+1, dp, 0), v[st]+v[st+1]+work(v, st+2, dp, 0));
// }


// void solve(){
//     cin>>n;
//     vi v(n+3);
//     f(i, 1, n) cin>>v[i];

//     vv(dp, int, n+1, 2);
//     f(i, 0, n) f(j, 0, 1) dp[i][j]=-1;

//     int ans=work(v, 1, dp, 1);
//     cout<<ans<<endl;
// }   

// int main(){
//     fastio;
//     test solve();
//     return 0;
// }