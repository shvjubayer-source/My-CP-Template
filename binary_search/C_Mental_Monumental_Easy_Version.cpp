// https://codeforces.com/contest/2226/problem/C
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
#define nl endl
#define pvec(a) do{for(auto &x:a) cout<<x<<" "; cout<<endl;}while(0)
//bit manipulation
#define checkbit(x,n) (x&(1LL<<n))
#define setbit(x,n) (x=(x|(1LL<<n)))
#define unsetbit(x,n) (x=(x&(~(1LL<<n))))
#define togglebit(x,n) (x=(x^(1LL<<n)))

const ll M = 1000000007;

bool check(int k, vi &a){
    // watch(k);

    multiset<int> s(all(a));

    for(int i=k-1; i>=0; i--){
        // watch(i);


        if(s.empty()) return false;

        auto it=s.find(i);



        if(it!=s.end()){
            // watch(*it);
            s.erase(it);
            continue;
        }

        auto it1=s.rbegin();

        if(*it1<=2*i) return false;


        // watch(*it1);

        s.erase(s.find(*it1));

    }

    // cout<<"true\n";
    return true;

}


void solve(){
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];




    int l=1, r=n+1;
    while(l<r){
        int mid=l+(r-l)/2;


        if(check(mid, a)) l=mid+1;
        else r=mid;
    }
    

    cout<<l-1<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}