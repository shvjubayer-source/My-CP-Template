// https://codeforces.com/problemset/problem/1701/C
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

bool check(vi &workers, vi &tasks, int t, int m, int n){
    ll total_tasks=0;


    f(i, 1, n){
        if(workers[i]>t){
            total_tasks+=t;
        }else{
            total_tasks+=workers[i]+(t-workers[i])/2;
        }


    }

    return total_tasks>=m;

}

void solve(){
    int n, m;

    cin>>n>>m;

    vi workers(n+1), tasks(m+1);
    f(i, 1, m){
        cin>>tasks[i];
        workers[tasks[i]]++;
    }

    int lo=0, high=2*m+5;
    while(lo<high){
        int mid=(lo+high)/2;

        if(check(workers, tasks, mid, m, n)) high=mid;
        else lo=mid+1;

    }


    cout<<lo<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}