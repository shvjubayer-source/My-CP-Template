// https://codeforces.com/problemset/problem/2094/E
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
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    int mx=*max_element(all(a));
    int mxlength=32-__builtin_clz(mx);

    ll ans=0;

    map<int,int> freq;

    f(i, 0, n-1){
        for(int j=mxlength-1; j>=0; j--){
            if(checkbit(a[i], j)){
                freq[j]++;
            }
        }
    }

    int val=a[0];

    f(i, 0, n-1){
        ll temp_ans=0;

        for(int j=mxlength-1; j>=0; j--){
            if(checkbit(a[i], j)){
                temp_ans+=1LL*(n-freq[j])*(1LL<<j);
            }else{
                temp_ans+=1LL*freq[j]*(1LL<<j);
            }
        }

        ans=max(ans, temp_ans);
    }   

    // watch(val);
    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}