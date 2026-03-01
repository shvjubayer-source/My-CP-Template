// https://codeforces.com/contest/2200/problem/E
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

bool isPrime(int n){
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

bool isSorted(vi &a){
    int n=a.size();

    f(i, 1, n-1){
        if(a[i-1]>a[i]) return false;
    }

    return true;
}


void solve(){
    int n;
    cin>>n;
    vi a(n);
    f(i, 0, n-1) cin>>a[i];

    if(isSorted(a)){
        cout<<"Bob"<<nl;
        return;
    }


    for(int i=n-1, mn=INT_MAX; i>=0; i--){
        if(isPrime(a[i])){
            if(a[i]>mn){
                // watch(i);
                cout<<"Alice"<<nl;
                return;
            }else mn=min(a[i], mn);
        }else{
            int temp=a[i];


            for(int j=2; j*j<=temp; j++){
                if(temp%j==0){

                    while(temp%j==0) temp=temp/j;
                    
                    if(temp!=1){
                        // watch(i);
                        cout<<"Alice"<<nl;
                        return;
                    }else{
                        if(j>mn){
                            // watch(i);
                            cout<<"Alice"<<nl;
                            return;
                        }else{
                            // cout<<"fuck"<<nl;.
                            mn=min(j, mn);
                        }
                    }

                    break;
                }
            }

            mn=min(a[i], mn);
        }


    }


    cout<<"Bob"<<nl;


}

int main(){
    fastio;
    test solve();
    return 0;
}