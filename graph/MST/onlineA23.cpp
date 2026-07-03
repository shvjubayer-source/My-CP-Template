#include <bits/stdc++.h>
using namespace std;

int n, m;

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
    cin>>n;

    vector<int> cost(n+1);
    for(int i=1; i<=n; i++) cin>>cost[i];

    cin>>m;

    vector<Edge> edges;

    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;


        edges.push_back({u, v, wt});
    }

    for(int i=1; i<=n; i++){
        edges.push_back({0, i, cost[i]});
    }

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.wt<b.wt;
    });

    long long ans=0;

    DSU ds(n+1);

    for(auto &e:edges){

        if(ds.find(e.u)!=ds.find(e.v)){

            ans+=e.wt;

            ds.unite(e.u, e.v);
        }



    }



    cout<<ans<<endl;
}