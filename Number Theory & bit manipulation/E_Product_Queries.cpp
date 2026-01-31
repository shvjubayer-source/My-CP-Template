// https://codeforces.com/contest/2193/problem/E
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
const int N=3e5+10;

vector<vector<int>> divisors(N+10);

void generate_div(){
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j+=i) divisors[j].push_back(i);
    }
}


void solve(){
    int n;
    cin>>n;
    vi a(n);

    map<int,int> m;
    f(i, 0, n-1) cin>>a[i], m[a[i]]++;

    vi dp(n+10, M);

    for(auto &i:m) dp[i.first]=1;

    f(i, 1, n){
        if(dp[i]==1) continue;

        for(auto &j:divisors[i]){
            if(j==1) continue;
            if(dp[j]<M && dp[i/j]<M){
                dp[i]=min(dp[i], dp[j]+dp[i/j]);
            }
        }

    }

    f(i, 1, n){
        if(dp[i]==M) cout<<-1<<' ';
        else cout<<dp[i]<<' ';
    }

    cout<<nl;
}

int main(){
    fastio;
    generate_div();
    test solve();
    return 0;
}