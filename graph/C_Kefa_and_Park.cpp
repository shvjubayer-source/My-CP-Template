// https://codeforces.com/contest/580/problem/C
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

int n, m, ans=0;

vector<bool> has_cat(200009);
vector<vector<int>> g(200009);

void dfs(int vertex, int parent, int cats){
    if(cats>m) return;


    bool isleaf=true;

    for(int child:g[vertex]){
        if(parent==child) continue;

        isleaf=false;


        if(has_cat[child]==true) dfs(child, vertex, cats+1);
        else dfs(child, vertex, 0);


    }

    if(isleaf) ans++;

}



void solve(){
    cin>>n>>m;

    f(i, 1, n){
        int x; cin>>x;
        if(x==1) has_cat[i]=true;
    }

    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;

        g[v1].pb(v2);
        g[v2].pb(v1);
    }

    dfs(1, 0, has_cat[1]);

    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}