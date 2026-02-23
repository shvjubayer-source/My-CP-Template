// https://cses.fi/problemset/task/1668
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
const int N=1e5+10;
 
vector<int> g[N];
bool visited[N];
int level[N];
 
bool ok=true;
 
void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]=true;
 
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        for(int child : g[cur_v]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[cur_v]+1;
            }else{
                if(level[child]==level[cur_v]){
                    ok=false;
                    return;
                }
            }
        }
 
    }
 
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
 
    f(i, 1, n){
        if(!visited[i]){
            bfs(i);
        }
    }
 
    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
 
    f(i, 1, n){
        if(level[i]%2) cout<<1<<' ';
        else cout<<2<<' ';
    }
    cout<<endl;
}
 
int main(){
    fastio;
    solve();
    return 0;
}