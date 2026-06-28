// https://codeforces.com/contest/2086/problem/B
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

// ll sum(ll )

void solve(){
    ll n, k, x;
    cin>>n>>k>>x;

    vll a(n+1), pSum(n+1);

    f(i, 1, n) cin>>a[i], pSum[i]=pSum[i-1]+a[i];

    ll ans=0;

    f(i, 1, n){

        ll sum;
        ll l=i, r=n*k+1;
        while(l<r){
            ll mid=l+(r-l)/2;

            // sum
            if(mid<=n) sum=pSum[mid]-pSum[i-1];
            else{
                sum=pSum[n]-pSum[i-1];
                ll temp=mid-n;

                ll x1=temp%n;
                ll x2=temp/n;

                sum+=pSum[x1]+pSum[n]*x2;

            }

            //condition
            if(sum<x) l=mid+1;
            else r=mid;
            
        }

        if(l<=n) sum=pSum[l]-pSum[i-1];
        else{
            sum=pSum[n]-pSum[i-1];
            ll temp=l-n;

            ll x1=temp%n;
            ll x2=temp/n;

            sum+=pSum[x1]+pSum[n]*x2;

        }


        //total ans starting from i
        if(sum>=x && l!=n*k+1){
            ll temp=n*k-l+1;
            ll x1=temp%n;
            ll x2=temp/n;
            // watch(i);
            // watch(l);
            // watch(x2+1);
            ans+=x2+(x1!=0);
            // cout<<nl;
        }



    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}


// p + 3n
// p + 2n
// p +  n
// p 