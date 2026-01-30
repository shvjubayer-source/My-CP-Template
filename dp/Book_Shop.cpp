// #include <bits/stdc++.h>
// using namespace std;
// #define f(i, st, ed) for(int i=st; i<=ed; i++)
// #define ll long long
// #define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
// #define test int t; cin>>t; while(t--)
// #define gcin(s) getline(cin, s);
// #define vi vector<int>
// #define vll vector<long long>
// #define pb push_back
// #define all(v) v.begin(), v.end()
// #define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define edge(v) g[v].size()
// #define yes cout<<"YES\n"
// #define no cout<<"NO\n"
// #define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
// //bit manipulation
// #define checkbit(x,n) (x&(1LL<<n))
// #define setbit(x,n) (x=(x|(1LL<<n)))
// #define unsetbit(x,n) (x=(x&(~(1LL<<n))))
// #define togglebit(x,n) (x=(x^(1LL<<n)))

// const ll M = 1000000007;



// void solve(){
//     int n, x;
//     cin>>n>>x;

//     vi price(n+1), pages(n+1);
//     f(i, 1, n) cin>>price[i];
//     f(i, 1, n) cin>>pages[i];

//     vll dp(x+1, 0);

//     f(i, 1, n){
//         for(int j=x; j>=0; j--){
//             if(j-price[i]>=0) dp[j]=max(dp[j], pages[i] + dp[j-price[i]])%M;
//         }
//     }

//     cout<<dp[x]<<endl;

// }

// int main(){
//     fastio;
//     solve();
//     return 0;
// }


