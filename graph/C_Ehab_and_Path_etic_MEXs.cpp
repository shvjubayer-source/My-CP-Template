// https://codeforces.com/contest/1325/problem/C
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

void dfs(int vertex, int par, vector<vector<int>> &g, map<pair<int,int>, pair<int,int>> &m, int &l, int &r){

    for(auto &child:g[vertex]){

        if(child==par) continue;

        int temp1=vertex;
        int temp2=child;

        if(temp1<temp2) swap(temp1, temp2);

        if(m[{temp1, temp2}].second==-1){
            m[{temp1, temp2}].second=r--;
        }


        dfs(child, vertex, g, m, l, r);


    }

}



void solve(){
    int n;
    cin>>n;

    vv(g, int, n+3, 0);
    map<pair<int,int>, pair<int,int>> m;
    vi ans(n);
    

    f(i, 0, n-2){
        int v1, v2;
        cin>>v1>>v2;

        g[v1].pb(v2);
        g[v2].pb(v1);

        if(v1<v2) swap(v1, v2);

        m[{v1, v2}]={i, -1};

    }

    int l=0, r=n-2;

    f(i, 1, n){
        if(edge(i)>2){
            // watch(i);

            f(j, 0, 2){
                int temp1=i;
                int temp2=g[i][j];

                if(temp1<temp2) swap(temp1, temp2);

                
                
                m[{temp1, temp2}].second=l++;
                
            //     watch(temp1);
            //     watch(temp2);

            //    cout<< m[{temp1, temp2}].second<<nl;

            }


            break;
        }
    }

    cout<<nl;

    dfs(1, 0,  g, m, l, r);


    for(auto &i:m) ans[i.second.first]=i.second.second;
    

    f(i, 0, n-2) cout<<ans[i]<<nl;


}

int main(){
    fastio;
    solve();
    return 0;
}