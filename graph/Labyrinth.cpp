// https://cses.fi/problemset/task/1193
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
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))
 
const ll M = 1000000007;
 
pair<int,int> posA, posB;
 
int dx[4] ={ 1,  -1,   0,   0};
int dy[4] ={ 0,   0,   1,  -1};
char dc[4]={'D', 'U', 'R', 'L'};
 
 
 
 
vector<char> ans;
 
const int N = 1e3+10;
vv(a, char, N, N);
vv(visited, bool, N, N);
vv(parents, char, N, N);
 
int level[N][N];
 
bool ok=false;
 
 
void bfs(int i, int j){
    queue<pair<int,int>> q;
 
    q.push({i, j});
    visited[i][j]=true;
 
    while(!q.empty()){
        pair<int,int> cur_v=q.front();
        int r=cur_v.first;
        int c=cur_v.second;
        q.pop();
        if(a[r][c]=='B'){
            posB.first=r;
            posB.second=c;
            ok=true;
            return;
        }
 
        for(int k=0; k<4; k++){
            
            if((a[r+dx[k]][c+dy[k]]=='.' || a[r+dx[k]][c+dy[k]]=='B') && !visited[r+dx[k]][c+dy[k]]){
                parents[r+dx[k]][c+dy[k]]=dc[k];
                q.push({r+dx[k], c+dy[k]});
                visited[r+dx[k]][c+dy[k]]=true;
                level[r+dx[k]][c+dy[k]]=level[r][c]+1;
            }
        }
 
 
    }
}
 
 
void solve(){
    int n, m;
    cin>>n>>m;
 
    f(i, 1, n) f(j, 1, m) cin>>a[i][j];
 
    
 
    f(i, 1, n){
        f(j, 1, m){
            if(a[i][j]=='A'){
                bfs(i, j);
                posA.first=i;
                posA.second=j;
                break;
            }
        }
    }
 
    if(!ok){
        no;
        return;
    }
    yes;
 
 
    pair<int,int> temp;
    temp.first=posB.first;
    temp.second=posB.second;
 
    int k=0;
 
    while(true){
        if(temp.first==posA.first && temp.second==posA.second) break;
        char letter=parents[temp.first][temp.second];
 
        // watch(temp.first);
        // watch(temp.second);
        // watch(letter);
        // cout<<endl;
 
        ans.push_back(letter);
 
        if(letter=='U') temp.first=temp.first+1;
        else if(letter=='D') temp.first=temp.first-1;
        else if(letter=='R') temp.second=temp.second-1;
        else temp.second=temp.second+1;
        
    }
 
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto &i:ans) cout<<i<<"";
 
    cout<<endl;
}
 
int main(){
    fastio;
    solve();
    return 0;
}