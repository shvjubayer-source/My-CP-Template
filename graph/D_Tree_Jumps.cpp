https://codeforces.com/contest/2070/problem/D
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

const ll M = 998244353;


void bfs(vector<vector<int>>& tree, int root, vi &depth, vll &ans, vll &child_ans) {
    int n = tree.size();
    vector<bool> visited(n, false);
    queue<int> q;

    int height=0;

    q.push(root);
    visited[root] = true;
    depth[root]=0;
    ans[0]=1;
    child_ans[1]=1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // cout << node << nl;

        for (int child : tree[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
                depth[child]=depth[node]+1;
                // watch(child);

                if(node==1){
                    // cout<<"f1"<<nl;
                    ans[1]+=1;
                    child_ans[child]=1;
                }else{
                    // cout<<"f2"<<nl;
                    ans[depth[child]]=((ans[depth[child]])+ans[depth[child]-1]-child_ans[node]+M)%M;

                    child_ans[child]=(ans[depth[child]-1]-child_ans[node]+M)%M;

                }
                // watch(depth[child]);
                // watch(ans[depth[child]]);
                // watch(child_ans[child]);
                // cout<<nl;
            }
        }

    }
}

void solve(){
    int n;
    cin>>n;

    vv(g, int, n+2, 0);

    f(i, 2, n){
        int x; cin>>x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    vi depth(n+2);
    vll ans(n+2);
    vll child_ans(n+2);

    bfs(g, 1, depth, ans, child_ans);

    ll sum=0;

    f(i, 0, n+1) sum=(sum+ans[i])%M;


    cout<<sum<<nl;


}

int main(){
    fastio;
    test solve();
    return 0;
}