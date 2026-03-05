// https://codeforces.com/problemset/problem/1294/C
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

    vi ans;

    int i=2;

    for(; i*i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            n/=i;
            break;
        }
    }

    for(i=i+1; i*i<=n; i++){
        if(n%i==0){
            ans.push_back(i);
            n=n/i;
            break;
        }
    }


    if((ans.size()<2) || n==ans[0] || n==ans[1] ) no;
    else{
        yes;
        cout<<ans[0]<<' '<<ans[1]<<' '<<n<<nl;
    }


}

int main(){
    fastio;
    test solve();
    return 0;
}