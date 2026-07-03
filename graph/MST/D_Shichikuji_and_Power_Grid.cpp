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
#define nl endl
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;

struct Edges{
    ll to;
    ll from;
    ll d;

    bool operator<(const Edges &other) const{
        return d>other.d;
    }


};

void solve(){
    ll n;
    cin>>n;

    vector<pair<ll,ll>> a(n+1);
    f(i, 1, n) cin>>a[i].first>>a[i].second;

    vll c(n+1), k(n+1);
    f(i, 1, n) cin>>c[i];
    f(i, 1, n) cin>>k[i];


    vector<vector<pair<ll,ll>>> g(n+1);

    f(i, 1, n){
        f(j, i+1, n){
            ll dist=(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second))*(k[i]+k[j]);

            g[i].push_back({j, dist});
            g[j].push_back({i, dist});
        }
    }

    f(i, 1, n){
        g[0].push_back({i, c[i]});
        g[i].push_back({0, c[i]});
    }


    vector<bool> vis(n+1);
    vector<pair<ll,ll>> edges;
    vll power_grid_idx;

    priority_queue<Edges> pq;

    // s.insert({0,  0, 0});
    pq.push({0, 0, 0});

    ll cost=0;

    while(!pq.empty()){
        // auto it=s.begin();
        // ll wt=it->d;
        // ll v=it->to;
        // ll from=it->from;
        auto it=pq.top();
        ll wt=it.d;
        ll v=it.to;
        ll from=it.from;

        // s.erase(it);

        pq.pop();

        if(vis[v]) continue;

        vis[v]=true;
        cost+=wt;

        if((from==0 || v==0)){
            if(from!=0 || v!=0) power_grid_idx.push_back((v^from));
        }else{
            edges.push_back({v, from});
        }



        for(auto &child : g[v]){
            if(!vis[child.first]) pq.push({child.first, v, child.second});
        }
    }

    // for(int i=1; i<=n; i++){
    //     if(!vis[i]){
    //         cout<<"IMPOSSIBLE"<<endl;
    //         return 0;
    //     }
    // }

    cout<<cost<<endl;

    cout<<power_grid_idx.size()<<nl;
    for(auto &i:power_grid_idx) cout<<i<<" ";
    cout<<nl;


    cout<<edges.size()<<nl;
    for(auto &i:edges) cout<<i.first<<" "<<i.second<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}