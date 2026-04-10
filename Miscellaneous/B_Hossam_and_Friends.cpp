// https://codeforces.com/problemset/problem/1771/B

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

    map<int,int> emni;

    f(i, 1, m){
        int x, y;
        cin>>x>>y;

        if(x>y) emni[x]=max(emni[x], y);
        else emni[y]=max(emni[y], x);
    }

    ll ans=0;

    vi dp(n+2);

    

    for(int i=1, temp=0; i<=n; i++){
        temp=max(temp, emni[i]);
        dp[i]=temp;

    }





    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}