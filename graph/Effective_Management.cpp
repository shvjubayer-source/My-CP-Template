// https://vjudge.net/problem/QOJ-7528
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

ll dfs(ll vertex, vll &t, vector<vector<ll>> &g, vll &actual_time, vll &profit){

    // cout<<vertex<<" ";
    if(actual_time[vertex]!=-1) return actual_time[vertex];



    ll cur_time=t[vertex];

    for(auto &child : g[vertex]){
        
        cur_time=max(cur_time, dfs(child, t, g, actual_time, profit));

    }

    return actual_time[vertex]=cur_time;
}

void solve(){
    ll n;
    cin>>n;

    vll profit(n+1), t(n+1);

    f(i, 1, n) cin>>profit[i];
    f(i, 1, n) cin>>t[i];

    vv(g, ll, n+4, 0);

    
    f(i, 1, n){
        ll x; cin>>x;
        
        f(j, 1, x){
            ll y; cin>>y;
            g[i].push_back(y);
        }
    }
    
    vll actual_time(n+1, -1);
    
    f(i, 1, n){
        if(actual_time[i]==-1){
            
            dfs(i, t, g, actual_time, profit);
            
        }
    }
    // cout<<"fuck"<<nl;

    ll idx=1;


// profit/t > profit/t(idx)

    f(i, 1, n){

        if(profit[i]*actual_time[idx]>profit[idx]*actual_time[i]){

            idx=i;

        }


    }

    // watch(idx);

    f(i, 1, n){

        if(profit[i]*actual_time[idx]==profit[idx]*actual_time[i]){

            cout<<i<<' ';

        }


    }

    cout<<nl;

}

int main(){
    fastio;
    solve();
    return 0;
}