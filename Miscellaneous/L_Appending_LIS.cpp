// https://codeforces.com/gym/106619/problem/L
//LIS problem

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

ll nSum(int l, int r){
    l--;
    ll a=(1LL*r*(r+1))/2;
    ll b=(1LL*l*(l+1))/2;

    return a-b;
}


void solve(){
// LIS ar last element ar equal or chuto hole k*(LIS.len)
// LIS ar last element ar theke boro hole sum((LIS.len) theke (LIS.len)+k-1)
    int n, k;
    cin>>n>>k;

    vi a(n);

    f(i, 0, n-1) cin>>a[i];

    ll sum=0;

    vector<int> tail;
    vector<int> prefLen(n);
    vector<int> lastElement(n);

    for (int i = 0; i < n; i++) {
        sum+=a[i];
        auto it = lower_bound(tail.begin(), tail.end(), a[i]);

        if (it == tail.end())
            tail.push_back(a[i]);
        else
            *it = a[i];

        prefLen[i] = tail.size();
        lastElement[i] = tail.back();
        
        int L=prefLen[i], last_num=lastElement[i];
        // watch(L);
        // watch(last_num);
        // watch(sum);
        if(last_num>=L){

            cout<<sum+1LL*k*L<<" ";
        }else{
            cout<<sum+nSum(L, L+k-1)<<" ";

        }

    }




    cout<<nl;
    
}

int main(){
    fastio;
    test solve();
    return 0;
}