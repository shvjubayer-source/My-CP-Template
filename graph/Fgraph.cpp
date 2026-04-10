// https://codeforces.com/contest/2218/problem/F
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



void solve(){
    int x, y;
    cin>>x>>y;

    int mx=(x+y)/2;
    int mn=((x+y)%2)? 0:1;

    if(x<mn || mx<x){
        no;
        return;
    }

    yes;

    vector<pair<int,int>> ans;


    int diff=mx-x;


    diff=((x+y+1)/2)-diff;



    int odd=((x+y)%2)? 2*diff-1: 2*diff;


    f(i, 1, odd-1) ans.push_back({i, i+1});
    f(i, odd+1, x+y) ans.push_back({odd, i});

    for(auto &i:ans) cout<<i.first<<" "<<i.second<<nl;



}

int main(){
    fastio;
    test solve();
    return 0;
}