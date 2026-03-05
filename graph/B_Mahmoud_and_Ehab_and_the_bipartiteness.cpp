// https://codeforces.com/contest/862/problem/B
#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define watch(x) cout<<(#x)<<" = " <<(x)<<endl;
#define test int t; cin>>t; while(t--)
#define gcin(s) getline(cin, s);
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define vll vector<long long>
#define vv(name, type, rows, cols) vector<vector<type>> name(rows, vector<type>(cols))
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ge(i) get<i>
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))



void dfs(int &l, int &r, vector<vector<int>> &g, int p, int vertex, int parent){
   //Take action on vertex after entering the vertex
   if(p%2==1) r++;
   else l++;

   for(int child : g[vertex]){
       if(child==parent) continue;
       //Take action on child before entering the child node
       dfs(l, r, g, p+1, child, vertex);

       // Take action on child after exciting child node
   }
   //Take action on vertex before exciting the vertex
}


void solve(){
    int n;
    cin>>n;
    vv(g, int, n+1, 0);

    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    int l=0, r=0;
    dfs(l, r, g, 1, 1, 0);
    cout<<(1LL*l*r)-(n-1)<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}
