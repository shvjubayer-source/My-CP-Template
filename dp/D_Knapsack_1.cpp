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
// #define ge(i) get<i> // get<i>(t);
// #define edge(v) g[v].size()
// #define yes cout<<"YES"<<endl
// #define no cout<<"NO"<<endl;
// #define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
// //bit manipulation
// #define checkbit(x,n) (x&(1LL<<n))
// #define setbit(x,n) (x=(x|(1LL<<n)))
// #define unsetbit(x,n) (x=(x&(~(1LL<<n))))
// #define togglebit(x,n) (x=(x^(1LL<<n)))

// const int N=1000;

// vector<pair<int,int>> a(N);

// ll dp[104][100004];

// ll solverX(int n, int w){
//     if(n==0){
//         if(w>=0) return 0;
//         else return INT_MIN;   
//     }
//     if(w<0) return INT_MIN;


//     if(dp[n][w]!=-1) return dp[n][w];



//     ll x=solverX(n-1, w);
//     ll y=solverX(n-1, w-a[n].first)+a[n].second;

//     return dp[n][w] = max(x, y);

// }


// void solve(){
//     int n, w;
//     cin>>n>>w;
    
//     f(i, 1, n) cin>>a[i].first>>a[i].second;

//     memset(dp, -1, sizeof(dp));

//     ll ans=solverX(n, w);

//     cout<<ans<<endl;
// }

// int main(){
//     fastio;
//     solve();
//     return 0;
// }

//Didn't understand the iterative solution, will understand later. There are two iterative solutions available by the way

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int weight = W; weight >= w[i]; weight--) {
            dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;
}
