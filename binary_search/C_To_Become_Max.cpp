// https://codeforces.com/problemset/problem/1856/C
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

bool check(ll mid, ll n, ll k, vll &a, vll &mx){
    // watch(mid);


    f(i, 1, n){

        if(mx[i]>=mid){
            // watch(i);

            if(a[i]>=mid) return true;

            ll remaining=k;
            ll banante_hobe=mid;



            f(j, i, n){
                // watch(j);
                // watch(banante_hobe);
                // watch(remaining);
                // watch(a[j]);
                if(remaining<=0){
                    if(banante_hobe<=a[j]) true;
                    else break;
                }


                if(banante_hobe<=a[j]) return true;
                else{
                    if(banante_hobe-a[j]<=remaining){

                        // watch(banante_hobe-a[j]);
                        remaining-=banante_hobe-a[j];
                        banante_hobe--;

                    }else break;

                }

            }




        }

    }


    return false;
}


void solve(){
    ll n, k;
    cin>>n>>k;
    vll a(n+1), mx(n+1);
    f(i, 1, n) cin>>a[i];

    for(ll i=n, prev=INT_MIN; i>=1; i--){
        prev=max(prev+1, a[i]);
        mx[i]=prev;
    }

    ll l=*max_element(all(a))+1, r=mx[1]+1;
    // watch(l);
    // watch(r);
    while(l<r){
        ll mid=l+(r-l)/2;
        
        // watch(l);
        // watch(r);
        // watch(mid);

        if(check(mid, n, k, a, mx)){
            // cout<<"true"<<nl;
            l=mid+1;
        }else{
            // cout<<"false"<<nl;
            r=mid;
        }
        // else r=mid;
    }

    // f(i, 1, n) cout<<mx[i]<<' ';
    // cout<<nl;

    cout<<l-1<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}