// https://codeforces.com/problemset/problem/1907/D
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


vi intersection(int a, int b, int c, int d){
    int l=max(a, c);
    int r=min(b, d);

    if(l<=r) return {l, r};
    return {};
}


bool check(vector<pair<int,int>> &a, int n){

    int mn=-n, mx=n;
    for(auto &i:a){
        vi temp=intersection(mn, mx, i.first, i.second);
        if(temp.empty()) return false;

        mn=temp[0]-n;
        mx=temp[1]+n;

    }

    return true;

}


void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);
    f(i, 0, n-1) cin>>a[i].first>>a[i].second;

    int l=0, r=2e9;
    while(l<r){
        int mid=(l+r)/2;

        if(check(a, mid)) r=mid;
        else l=mid+1;

    }


    cout<<l<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}