#include <bits/stdc++.h>
using namespace std;

int n;

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


struct Coord{
    int x;
    int y;
    int z;

    int node;

};


struct Edge{
    int u;
    int v;
    int wt;
};

int main(){
    cin>>n;

    vector<Coord> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
        arr[i].node=i;
    } 


    vector<Edge> edges;


    sort(arr.begin(), arr.end(), [](Coord &a, Coord &b){
        return a.x<b.x;
    });

    for(int i=1; i<n; i++){
        edges.push_back({arr[i].node, arr[i-1].node, abs(arr[i].x-arr[i-1].x)});
        // cout<<arr[i].node<<" "<<arr[i-1].node<<" "<<abs(arr[i].x-arr[i-1].x)<<endl;
    }



    sort(arr.begin(), arr.end(), [](Coord &a, Coord &b){
        return a.y<b.y;
    });

    for(int i=1; i<n; i++){
        edges.push_back({arr[i].node, arr[i-1].node, abs(arr[i].y-arr[i-1].y)});
    }


    sort(arr.begin(), arr.end(), [](Coord &a, Coord &b){
        return a.z<b.z;
    });

    for(int i=1; i<n; i++){
        edges.push_back({arr[i].node, arr[i-1].node, abs(arr[i].z-arr[i-1].z)});
    }


    long long ans=0;

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.wt<b.wt;
    });


    DSU ds(n+1);

    for(auto &e:edges){

        if(ds.find(e.u)!=ds.find(e.v)){
            // cout<<e.u<<" "<<e.v<<" "<<e.wt<<endl;


            ans+=e.wt;

            ds.unite(e.u, e.v);
        }
    }

    cout<<ans<<endl;

}