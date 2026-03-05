// https://codeforces.com/contest/378/problem/C
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
int n, m, k;

void dfs(int r, int c, int &emni, vector<vector<char>> &temp, vector<vector<char>> &a){
 
    if(a[r][c]=='#' || temp[r][c]=='4' || emni<=0) return;



    temp[r][c]='4'; 
    emni--;

    if(emni<=0) return;




    if(r+1<=n) dfs(r+1, c, emni, temp, a);
    if(r-1>=1) dfs(r-1, c, emni, temp, a);
    if(c+1<=m) dfs(r, c+1, emni, temp, a);
    if(c-1>=1) dfs(r, c-1, emni, temp, a);



}



void solve(){

    cin>>n>>m>>k;

    int cnt=0;


    vv(a, char, n+1, m+1);
    vv(temp, char, n+1, m+1);

    f(i, 1, n) f(j, 1, m) cin>>a[i][j];
    f(i, 1, n) f(j, 1, m) if(a[i][j]=='.') cnt++;


    
    int emni=cnt-k;

    

    f(i, 1, n){
        int f=0;
        f(j, 1, m){
            if(a[i][j]=='.'){
                dfs(i, j, emni, temp, a);
                f=1;
                break;
            }
        }
        if(f) break;
    }

    f(i, 1, n){
        f(j, 1, m){
            if(a[i][j]=='.'){
                if(temp[i][j]=='4') cout<<a[i][j];
                else cout<<'X';
            }else cout<<a[i][j];
        }
        cout<<nl;
    }



}

int main(){
    fastio;
    solve();
    return 0;
}