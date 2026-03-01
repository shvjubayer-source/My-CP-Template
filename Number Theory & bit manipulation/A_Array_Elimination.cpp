// https://codeforces.com/contest/1601/problem/A
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

    map<int,int> m;
    f(i, 1, n){
        int x; cin>>x;
        f(j, 0, 30) if(checkbit(x, j)) m[j]++;
    }

    int g=0;
    for(auto &i:m) g=__gcd(g, i.second);

    if(g==0){
        f(i, 1, n) cout<<i<<' ';
        cout<<nl;
    }else{
        vi temp;
        for(int i=1; i*i<=g; i++){
            if(g%i==0){
                temp.push_back(i);
                if(i!=g/i) temp.push_back(g/i);  
            }
        }      
        
        sort(all(temp));

        for(auto &i:temp) cout<<i<<' ';
        cout<<nl;
    }

}

int main(){
    fastio;
    test solve();
    return 0;
}