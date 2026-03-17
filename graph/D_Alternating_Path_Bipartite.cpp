// https://codeforces.com/contest/2204/problem/D
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

bool ok=true;
ll odd=0, even=0;

void bfs(int source, vi &level, vector<bool> &visited, vector<vector<int>> &g){
    queue<int> q;
    q.push(source);
    visited[source]=true;

    level[source] = 0;
    even = 1;  
    odd = 0;

    while(!q.empty()){
        int cur_v=q.front();
        q.pop();

        for(int child : g[cur_v]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[cur_v]+1;

                if(level[child]%2) odd++;
                else even++;
            }else{
                if(level[child]%2==level[cur_v]%2){
                    ok=false;
               
                }
            }
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    vv(g, int, n+2, 0);

    vi level(n+2, 0);
    vector<bool> visited(n+2);

    f(i, 1, m){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }

    ll ans=0;

    f(i, 1, n){
        if(!visited[i]){
            odd=0;
            even=0;
            ok=true;
            bfs(i, level, visited, g);

            if(ok==true){
                ans+=max(odd, even);
            } 
        }

    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}