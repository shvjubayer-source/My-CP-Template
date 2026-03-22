// https://codeforces.com/contest/1167/problem/C
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


class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i<=n; i++)
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

    int printSize(int n){
        return size[n];
    }

};

void solve(){
    int n, m;
    cin>>n>>m;

    DSU d(n);


    f(i, 1, m){
        int k; 
        cin>>k;

        if(k!=0){
            int x;
            cin>>x;


            f(j, 2, k){
                int v;
                cin>>v;
                d.unite(x, v);
            }


        }

    }

    f(i, 1, n) cout<<d.printSize(d.find(i))<<" ";
    

    cout<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}