// https://cses.fi/problemset/task/1675/
#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int wt;

};

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); 

        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return false;

        if(size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }

        return true;
    }
};


int main(){
    int n, m;
    cin>>n>>m;

    vector<Edge> edge;
    

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        edge.push_back({u, v, wt});
    }

    sort(edge.begin(), edge.end(), [](Edge &a, Edge &b){
        return a.wt<b.wt;
    });

    DSU d(n+1);

    long long cost=0;

    for(auto e:edge){

        if(d.find(e.u)!=d.find(e.v)){

            cost+=e.wt;
            d.unite(e.u, e.v);

        }
    }

    bool ok=true;

    for(int p=d.find(1), i=2; i<=n; i++){
        if(d.find(i)!=p){
            ok=false;
            break;
        }
    }

    if(ok) cout<<cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    // cout<<cost<<endl;
}