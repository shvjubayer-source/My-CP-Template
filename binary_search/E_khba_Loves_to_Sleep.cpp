// https://codeforces.com/contest/2167/problem/E
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


bool check(int n, int k, int x, int mid, vi &a){

    ll cnt=0;

    cnt+=max(0LL, 1LL*a[0]-mid+1);

    f(i, 1, n-1){

        cnt+=max(0LL, 1LL*(a[i]-mid)-(a[i-1]+mid)+1);

        if(cnt>=k) return true;
    }


    cnt+=max(0LL, 1LL*x-(a[n-1]+mid)+1);

    return cnt>=k;
}


set<int> helper(int n, int k, int x, int mid, vi &a){

    set<int> s;

    f(i, 0, a[0]-mid){
        s.insert(i);
        if(s.size()==k) return s;
    }


    f(i, 1, n-1){

        if(a[i-1]+mid<=a[i]-mid){
            f(j, a[i-1]+mid, a[i]-mid){
                s.insert(j);
                if(s.size()==k) return s;
            }
        }
    }

    f(i, a[n-1]+mid, x){
        s.insert(i);
        if(s.size()==k) return s;
    }


    return s;
}



void solve(){
    int n, k, x;
    cin>>n>>k>>x;

    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    sort(all(a));

    int lo=0, hi=x+10;

    while(lo<hi){
        int mid=(lo+hi)/2;

        if(check(n, k, x, mid, a)) lo=mid+1;
        else hi=mid;

    }

    lo--;

    set<int> ans=helper(n, k, x, lo, a);

    for(auto &i:ans) cout<<i<<' ';

    cout<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}