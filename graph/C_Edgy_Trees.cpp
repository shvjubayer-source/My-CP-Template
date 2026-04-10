// https://codeforces.com/problemset/problem/1139/C
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


ll multiIter(ll n, ll x){
    ll result=1;
    while(x>0) {
        if(x%2==1) result=(result*n)%M;
        n=(n*n)%M;
        x/=2;
    }
    return result;
}

ll dfs(int vertex, vector<bool> &vis, vector<vector<int>> &g){

    vis[vertex]=true;

    ll ans=0;

    for(auto child:g[vertex]){
        if(vis[child]) continue;

        ans+=dfs(child, vis, g);

    }


    return ans+1;
}


void solve(){
    ll n, k;
    cin>>n>>k;

    vv(g, int, n+2, 0);
    vector<bool> vis(n+2, false);

    f(i, 1, n-1){
        int v1, v2, x;
        cin>>v1>>v2>>x;

        if(x==0){
            g[v2].push_back(v1);
            g[v1].push_back(v2);
        }


    }

    ll ans=multiIter(n, k);

    f(i, 1, n){
        if(vis[i]) continue;

        ans=(ans-multiIter(dfs(i, vis, g), k)+M)%M;

    }



    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}