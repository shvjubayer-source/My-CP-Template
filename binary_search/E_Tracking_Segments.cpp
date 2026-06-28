// https://codeforces.com/contest/1843/problem/E
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

int n, m; 

//Sum(l to r)>length/2
//2*Sum(l to r)>length

bool check(int mid, vector<pair<int,int>> &ranges, vi &queries){
    vll pSum(n+1);

    f(i, 1, mid) pSum[queries[i]]++;

    f(i, 1, n) pSum[i]+=pSum[i-1];

    f(i, 1, m) if(2LL*(pSum[ranges[i].second]-pSum[ranges[i].first-1])>(ranges[i].second-ranges[i].first+1)) return true;

    return false;
}


void solve(){
    cin>>n>>m;

    vector<pair<int,int>> ranges(m+1);

    f(i, 1, m) cin>>ranges[i].first>>ranges[i].second;

    int q;
    cin>>q;

    vi queries(q+1);

    f(i, 1, q) cin>>queries[i];


    int l=0, r=q+1;

    while(l<r){
        int mid=l+(r-l)/2;

        if(check(mid, ranges, queries)) r=mid;
        else l=mid+1;

    }

    // watch(l);
    // watch(r);
    if(l==q+1) cout<<-1<<nl;
    else cout<<l<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}