// https://codeforces.com/contest/2192/problem/C
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
    ll n, h, k;
    cin>>n>>h>>k;

    vll a(n+1), sufMax(n+2);
    f(i, 1, n) cin>>a[i];
    for(int i=n; i>=1; i--) sufMax[i]=max(sufMax[i+1], a[i]);

    ll sum=accumulate(all(a), 0LL);

    if(h%sum==0){
        cout<<(h/sum)*n+(h/sum-1)*k<<nl;
        return;
    }

    ll ans=(h/sum)*(n+k);
    h=h%sum;

    sum=0;
    ll mn=INT_MAX;
    
    f(i, 1, n){
        sum+=a[i];
        mn=min(mn, a[i]);
        if(sufMax[i+1]>mn) sum=sum+sufMax[i+1]-mn;


        if(sum>=h){
            ans+=i;
            break;
        }

        if(sufMax[i+1]>mn) sum=sum-sufMax[i+1]+mn;
    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}