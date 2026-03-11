// https://codeforces.com/problemset/problem/1365/D
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
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define nl '\n'
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;

int n, m;

int dfs(int i, int j, vector<vector<char>> &a, vector<vector<char>> &vis){
    if(i<=0 || j<=0 || i>n || j>m || vis[i][j]=='1') return 0;
    if(a[i][j]=='#') return 0;
    
    vis[i][j]='1';

    int ans=(a[i][j]=='G')? 1:0;

    ans+=dfs(i+1, j, a, vis);
    ans+=dfs(i-1, j, a, vis);
    ans+=dfs(i, j+1, a, vis);
    ans+=dfs(i, j-1, a, vis);

    return ans;
}



void solve(){
    cin>>n>>m;

    vv(a, char, n+5, m+5);
    vv(vis, char, n+5, m+5);

    f(i, 1, n) f(j, 1, m) cin>>a[i][j];

    int good_people=0;

    f(i, 1, n) f(j, 1, m) if(a[i][j]=='G') good_people++;


    bool isBadGoodAdjacent=false;

    f(i, 1, n){
        f(j, 1, m){
            if(a[i][j]=='B'){
                if(a[i+1][j]=='.') a[i+1][j]='#';
                if(a[i-1][j]=='.') a[i-1][j]='#';
                if(a[i][j+1]=='.') a[i][j+1]='#';
                if(a[i][j-1]=='.') a[i][j-1]='#';


                if(a[i+1][j]=='G') isBadGoodAdjacent=true;
                if(a[i-1][j]=='G') isBadGoodAdjacent=true;
                if(a[i][j+1]=='G') isBadGoodAdjacent=true;
                if(a[i][j-1]=='G') isBadGoodAdjacent=true;

                if(isBadGoodAdjacent){
                    no;
                    return;
                }

            }
        }
    }


    

    int good_people_escaped=dfs(n, m, a, vis);


    if(good_people==good_people_escaped) yes;
    else no;


    

}

int main(){
    fastio;
    test solve();
    return 0;
}