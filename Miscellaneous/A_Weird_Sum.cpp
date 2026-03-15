// https://codeforces.com/problemset/problem/1648/A
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



void solve(){
    int n, m;
    cin>>n>>m;

    vv(a, int, n+1, m+1);
    // map<pair<int,int>, int> cnt_row; //<pair<key, row>, cnt> stores how many elements in a particular row
    // map<pair<int,int>, int> cnt_col;

    f(i, 0, n-1) f(j, 0, m-1){
        cin>>a[i][j];
        // cnt_row[{a[i][j], i}]++;
        // cnt_col[{a[i][j], j}]++;
    }


    


    map<int, int> prev_row;
    map<int, ll> prev_distance_row;
    map<int,int> freq_row;
    // map<int, 

    ll row=0;

    f(i, 0, n-1){
        f(j, 0, m-1){


            if(prev_row.find(a[i][j])!=prev_row.end()){

                if(prev_row[a[i][j]]==i){
    
                    row+=prev_distance_row[a[i][j]];
                }else{
    
                    prev_distance_row[a[i][j]]=prev_distance_row[a[i][j]]+abs(i-prev_row[a[i][j]])*freq_row[a[i][j]];
                    row+=prev_distance_row[a[i][j]];
                }
                
            }
            // watch(a[i][j])
            // watch(row);
            
            prev_row[a[i][j]]=i;

        }

        f(j, 0, m-1) freq_row[a[i][j]]++;
    }

    map<int, int> prev_col;
    map<int, ll> prev_distance_col;
    map<int,int> freq_col;

    ll col=0;

    f(j, 0, m-1){
        f(i, 0, n-1){
            if(prev_col.find(a[i][j])!=prev_col.end()){
                if(prev_col[a[i][j]]==j){
                    col+=prev_distance_col[a[i][j]];
                }else{
                    prev_distance_col[a[i][j]]=prev_distance_col[a[i][j]]+abs(j-prev_col[a[i][j]])*freq_col[a[i][j]];
                    col+=prev_distance_col[a[i][j]];
                }
            }
            prev_col[a[i][j]]=j;
        }

        f(i, 0, n-1) freq_col[a[i][j]]++;

    }


    cout<<row+col<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}