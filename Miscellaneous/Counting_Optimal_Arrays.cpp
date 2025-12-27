//https://www.codechef.com/problems/CNTARR7
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

const int M = 998244353;

void solve() {
    ll n, m;
    cin>>n>>m;


    if(n==1){
        cout<<(m+1)%M<<endl;
        return;
    }



    int k=0;
    ll temp=m;
    while(temp>>=1){
        k++;
    }

    ll pow2k=1LL<<k;


    ll count=(m-pow2k+1)%M;
    ll ans=(2*count)%M;

    cout<<ans<<endl;

}
int main(){
    fastio;
    test solve();
    return 0;
}