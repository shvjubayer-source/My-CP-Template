// https://codeforces.com/contest/2070/problem/C
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

bool check(vll &a, string &s, ll n, ll k, ll mid){


    for(ll i=0; i<n; ){
        if(s[i]=='B'){

            if(a[i]>mid){
                if(k>0){
                    k--;
                    ll j=i;
                    for(;j<n; j++){
                        if(s[j]=='R'){
                            if(a[j]>mid){
                                j=j+1;
                                break;
                            }
                        }
                    }
                    i=j;
                }else{
                    return false;
                }
            }else{
                i++;
            }
        }else{
            i++;
        }
    }


    return true;
}


void solve(){
    ll n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    vll a(n);
    f(i, 0, n-1) cin>>a[i];

    ll l=0, r=2e9;

    while(l<r){
        ll mid=l+(r-l)/2;
        // watch(mid);

        if(check(a, s, n, k, mid)){
            // cout<<"true"<<nl;
            r=mid;

        }else{
            // cout<<"false"<<nl;
            l=mid+1;


        }



    }


    cout<<l<<nl;
//FFFFFFTTTTTT   <=x ar theke chuto othoba shoman rakha jay kina
    
}

int main(){
    fastio;
    test solve();
    return 0;
}