// https://codeforces.com/contest/1349/problem/A
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

vector<int> primeFactors(int n){
    vi ans;
    while(n%2==0){
        ans.push_back(2);
        n/=2;
    }


    for(int i=3; i*i<=n; i+=2){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }

    if(n>1){
        ans.push_back(n);
    }

    return ans;
}


ll helper(vi &a, vi &primefact){
    int n=a.size();
    ll ans=1;
    
    for(int &i:primefact){

        int cnt=0;

        f(j, 0, n-1){

            if(a[j]%i==0){
                cnt++;
            }

        }

        if(cnt>=n-1){
            ans=ans*i;

            f(j, 0, n-1){
                if(a[j]%i==0){
                    a[j]/=i;
                }
            }
        }


    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    ll ans=1;

    vi first=primeFactors(a[0]);
   
    ans*=helper(a, first);

    vi second=primeFactors(a[1]);

    ans*=helper(a, second);

    cout<<ans<<nl;
}

int main(){
    fastio;
    solve();
    return 0;
}

// 3 5 7
// 15 21 35


// 10 24 40 80 ans=1

// 5  12  20 40  ans=2

// 1  12  4  8  ans=2*5

// 1  6   2  4  ans=2*5*2

// 1  3   1  2  ans=2*5*2*2