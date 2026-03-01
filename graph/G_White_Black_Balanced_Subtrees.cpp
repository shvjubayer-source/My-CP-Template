// https://codeforces.com/problemset/problem/1676/G
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
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))



int ans=0;


int dfs(int vertex, string &s, vi &visited, vector<vector<int>> &g){
   //Take action on vertex after entering the vertex
   visited[vertex]=1;
   int cnt=0;
   for(int &child : g[vertex]){
       if(visited[child]) continue;
       //Take action on child before entering the child node

       cnt+=dfs(child, s, visited, g);

       // Take action on child after exciting child node
   }
   if(s[vertex-1]=='W') cnt++;
   else cnt--;
   if(cnt==0) ans++;
   return cnt;
   //Take action on vertex before exciting the vertex
}

void solve(){
    int n;
    cin>>n;
    vi visited(n+2, 0);
    vv(g, int, n+2, 0);
    f(i, 2, n){
        int x; cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }
    string s;
    cin>>s;
    ans=0;
    int temp=dfs(1, s, visited, g);
    cout<<ans<<endl;
}

int main(){
    fastio;
    test solve();
    return 0;
}