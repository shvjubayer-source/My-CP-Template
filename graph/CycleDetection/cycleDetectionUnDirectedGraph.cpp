//solution of cses round trip problem
// https://cses.fi/problemset/task/1669
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
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))
 
const ll M = 1000000007;
const int N = 1e5+10;
 
vector<int> g[N];
int parents[N];
bool visited[N];
 
 
int start=-1, endd=-1;
 
bool dfs(int vertex, int par){
    parents[vertex]=par;
    visited[vertex]=true;
 
    bool isCycle=false;
 
    for(int &child:g[vertex]){
        if(child==par) continue;
 
        if(visited[child]){
            start=vertex;
            endd=child;
            return true;
 
        }else{
 
            isCycle|=dfs(child, vertex);
 
        }
 
    }
 
 
    return isCycle;
 
}
 
 
 
 
void solve(){
    int n, m;
    cin>>n>>m;
    
    f(i, 1, m){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
 
    bool ok=false;
 
 
 
    f(i, 1, n){
        if(!visited[i]){
            if(dfs(i, -1)==true){
                ok=true;
                break;
            }
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE\n";
        return;
    }
 
 
 
    vi cycle;
 
    cycle.push_back(start);
 
    for(int v=endd; v!=start; v=parents[v]) cycle.push_back(v);
    
    cycle.push_back(start);
 
 
    cout<<cycle.size()<<endl;
    for(int &i:cycle) cout<<i<<' ';
 
    cout<<endl;
}
 
int main(){
    fastio;
    solve();
    return 0;
}