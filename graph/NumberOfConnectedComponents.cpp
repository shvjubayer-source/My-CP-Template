#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
int vis[N];
vector<int> graph[N];

void dfs(int vertex){
    vis[vertex]=true;
    for(int child:graph[vertex]){
        if(vis[child]) continue;

        dfs(child);

    }

}

int main(){
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        cnt++;
        dfs(i);
    }
    cout<<cnt<<endl;

}



//with the connected component itself
// const int N = 1e5 + 5;
// int vis[N];
// vector<int> graph[N];
// vector<vector<int>> connected_components;

// vector<int> current_cc;

// void dfs(int vertex){
//     vis[vertex]=true;
//     current_cc.push_back(vertex);
//     for(int child:graph[vertex]){
//         if(vis[child]) continue;

//         dfs(child);

//     }

// }

// int main(){
//     int n, e;
//     cin>>n>>e;
//     for(int i=0; i<e; i++){
//         int v1, v2;
//         cin>>v1>>v2;
//         graph[v1].push_back(v2);
//         graph[v2].push_back(v1);
//     }

//     int cnt=0;
//     for(int i=1; i<=n; i++){
//         if(vis[i]) continue;
//         cnt++;
//         dfs(i);
//         connected_components.push_back(current_cc);
//         current_cc.clear();
//     }
//     cout<<cnt<<endl;
//     for(auto &i:connected_components){
//         for(int &j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }