// https://cses.fi/problemset/task/1679
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
 
stack<int> st;
 
 
void dfs(int vertex, vector<vector<int>> &g, vector<bool> &vis){
    vis[vertex]=true;
 
 
    for(auto &i:g[vertex]){
        if(vis[i]) continue;
 
        dfs(i, g, vis);
 
    }
 
    st.push(vertex);
 
}
 
bool isCycle(int v, vector<vector<int>> &g, vector<int> &state){
 
    state[v] = 1; // visiting, in DFS recursion stack
    //state[v] = 0 // not visited 
 
    for(auto &child : g[v]){
 
        if(state[child] == 1) return true; // back edge
 
        if(state[child] == 0){
            if(isCycle(child, g, state)) return true;
        }
    }
 
    state[v] = 2; // already visted, not in DFS recursion stack
 
    return false;
}
 
 
void solve(){
    int n, m;
    cin>>n>>m;
 
    vv(g, int, n+2, 0);
    vector<bool> vis(n+2, false);
 
    f(i, 1, m){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
    }
 
 
 
    vector<int> vis2(n+2);
 
    f(i, 1, n){
        if(!vis2[i]){
            if(isCycle(i, g, vis2)){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
 
 
    f(i, 1, n){
        if(!vis[i]){
            dfs(i, g, vis);
        }
    }
 
    
 
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
 
}
 
int main(){
    fastio;
    solve();
    return 0;
}