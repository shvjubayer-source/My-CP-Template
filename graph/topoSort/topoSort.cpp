#include <bits/stdc++.h>
using namespace std;

void topoSort(int vertex, stack<int> &st, vector<vector<int>> &g, vector<bool> &vis){
    vis[vertex]=true;


    for(auto child : g[vertex]){
        if(!vis[child]){
            topoSort(child, st, g, vis);
        }
    }


    st.push(vertex);
}


int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
    }

    vector<bool> vis(n+1);
    stack<int> st;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            topoSort(i, st, g, vis);
        }
    }

    vector<int> topoArray;

    while(!st.empty()){
        topoArray.push_back(st.top());
        st.pop();
    }

    for(auto &i:topoArray) cout<<i<<" ";

    cout<<endl;
    return 0;
}