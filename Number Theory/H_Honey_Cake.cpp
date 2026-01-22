// https://codeforces.com/contest/2181/problem/H
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

vector<long long> divisors(long long n) {
    vector<long long> d;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    return d;
}


void solve(){
    ll w, h, d, n;
    cin>>w>>h>>d>>n;

    vll wd=divisors(w), hd=divisors(h), dd=divisors(d);

    for(auto &i:wd){

        for(auto &j:hd){

            for(auto &k:dd){

                if((w/i)*(h/j)*(d/k)==n){
                    cout<<w/i-1<<' '<<h/j-1<<' '<<d/k-1<<nl;
                    return;
                }

            }

        }

    }


    cout<<-1<<nl;

}

int main(){
    fastio;
    solve();
    return 0;
}