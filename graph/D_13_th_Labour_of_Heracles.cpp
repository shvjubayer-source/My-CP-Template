// https://codeforces.com/problemset/problem/1466/D
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



void solve(){
    int n;
    cin>>n;

    vi Nodes(n+1);

    vv(g, int, n+1, 0);

    f(i, 1, n) cin>>Nodes[i];

    ll sum=accumulate(all(Nodes), 0LL);

    f(i, 1, n-1){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);

    }

    map<int,int> m;

    f(i, 1, n) m[Nodes[i]]+=edge(i)-1;

    for(auto it = m.begin(); it != m.end(); ) {
        if(it->second == 0)
            it = m.erase(it);
        else
            ++it;
    }

    // for(auto &i:m) cout<<i.first<<" "<<i.second<<endl;

    // cout<<endl;

    f(i,1,n-1){

        cout<<sum<<" ";

        if(m.empty()) continue;

        auto it = prev(m.end());

        sum += it->first;

        it->second--;

        if(it->second == 0)
            m.erase(it);
    }


    cout<<endl;
}

int main(){
    fastio;
    test solve();
    return 0;
}