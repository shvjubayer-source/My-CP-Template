// https://codeforces.com/contest/2203/problem/D
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

    vi cnt(n+m+1, 0), c(n+m+1, 0);

    f(i, 1, n){
        int x; cin>>x;
        cnt[x]++;
    }


    f(i, 1, m+n){
        if(cnt[i]>0){
            for(int j=i; j<=n+m; j+=i) c[j]+=cnt[i];
        }
    }

    int alice=0, bob=0, common=0;

    f(i, 1, m){
        int x; cin>>x;

        if(c[x]==n) alice++;
        else if(c[x]==0) bob++;
        else common++;
    }



    alice+=(common+1)/2;
    bob+=common/2;

    

    if(alice>bob) cout<<"Alice\n";
    else cout<<"Bob\n";


}

int main(){
    fastio;
    test solve();
    return 0;
}