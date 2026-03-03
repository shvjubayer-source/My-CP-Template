// https://codeforces.com/contest/1498/problem/B
// Data Structure
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
    int n, w;
    cin>>n>>w;

    multiset<int> s;
    f(i, 0, n-1){
        int x; cin>>x;
        s.insert(x);
    }

    ll ans=0;

    while(!s.empty()){
        int temp=w;

        while(!s.empty() && temp>0){
            auto it=s.upper_bound(temp);
            if(it==s.begin()) break;
            else it--;

            temp-=*it;
            s.erase(it);

        }
        ans++;
    }


    cout<<ans<<nl;
}   

int main(){
    fastio;
    test solve();
    return 0;
}