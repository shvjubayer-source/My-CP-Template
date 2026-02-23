// https://codeforces.com/contest/2195/problem/E
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

void dfs1(int vertex, int parent, vector<vector<int>> &g, vll &children){


    for(int child : g[vertex]){
        if(child==parent) continue;


        dfs1(child, vertex, g, children);


        children[vertex]+=1+children[child];
   }

}

void dfs2(int vertex, int parent, vector<vector<int>> &g, vll &children, vll &dp){

    dp[vertex]=(2LL*children[vertex]+1+dp[parent])%M;
    for(int child : g[vertex]){
        if(child==parent) continue;


        dfs2(child, vertex, g, children, dp);

        
   }

}


void solve(){
    int n;
    cin>>n;

    vv(g, int, n+1, 0);

    f(i, 1, n){
        int x, y;
        cin>>x>>y;
        if(x==0 && y==0) continue;
        g[i].push_back(x);
        g[i].push_back(y);
        g[x].push_back(i);
        g[y].push_back(i);
    }

    vll dp(n+1, 0);
    vll children(n+1, 0);



    dfs1(1, 0, g, children);
    dfs2(1, 0, g, children, dp);



    f(i, 1, n) cout<<dp[i]<<' ';


    cout<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}