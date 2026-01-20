//in each query find how many numbers in the array is between l-r
//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

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

    sort(all(a));


    int q;
    cin>>q;

    f(i, 1, q){
        int l, r;
        cin>>l>>r;

        int left=lower_bound(all(a), l)-a.begin();
        int right=upper_bound(all(a), r)-a.begin();

        cout<<right-left<<' ';
        
    }

    cout<<nl;

}

int main(){
    fastio;
    solve();
    return 0;
}