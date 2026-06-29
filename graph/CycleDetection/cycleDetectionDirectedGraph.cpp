#include <bits/stdc++.h>
using namespace std;

bool isCycle(int v, vector<vector<int>> &g, vector<int> &vis){
 
    vis[v] = 1; // visiting, in DFS recursion stack
    //state[v] = 0 // not visited 
 
    for(auto &child : g[v]){
 
        if(vis[child] == 1) return true; // back edge
 
        if(vis[child] == 0){
            if(isCycle(child, g, vis)) return true;
        }
    }
 
    vis[v] = 2; // already visted, not in DFS recursion stack
 
    return false;
}
 


int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> vis(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    int is_cycle=false;

    for(int i=1; i<=n; i++){
        if(isCycle(i, g, vis)){
            is_cycle=true;
        }
    }

    if(is_cycle) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle Found"<<endl;


}