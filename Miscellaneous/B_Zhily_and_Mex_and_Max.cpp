// https://codeforces.com/contest/2224/problem/B
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

vector<int> prefixMex(vector<int>& arr) {
    int n = arr.size();

    vector<int> vis(n + 1, 0);
    vector<int> ans(n);

    int mex = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= n)
            vis[arr[i]] = 1;

        while (vis[mex])
            mex++;

        ans[i] = mex;
    }

    return ans;
}

vector<int> prefixMax(vi &a){
    int n=a.size();
    
    vi ans(n);

    ans[0]=a[0];

    f(i, 1, n-1) ans[i]=max(a[i], ans[i-1]);


    return ans;
}


void solve(){
    int n;
    cin>>n;

    vi a;


    map<int, int> m;
    int mx=-1, idx=-1;

    f(i, 0, n-1){
        int x; cin>> x;

        m[x]++;

        if(m[x]<=1){
            a.push_back(x);
            if(mx<x){
                mx=x;
                idx=a.size()-1;
            }
        }

    }

    swap(a[idx], a[0]);

    sort(a.begin()+1, a.end());


    for(auto &i:m){
        f(j, 2, i.second) a.push_back(i.first);
    }

    // pvec(a);

    vi preMex=prefixMex(a);
    vi preMax=prefixMax(a);

    // pvec(preMex);
    // pvec(preMax);

    ll ans=0;

    f(i, 0, n-1){
        ans+=preMex[i]+preMax[i];    
    }

    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}