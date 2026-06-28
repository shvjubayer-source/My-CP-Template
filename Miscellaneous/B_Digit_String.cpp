https://codeforces.com/contest/2230/problem/B
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

// remove all 4 
// odd before 2 is not allowed


void solve(){
    string s;
    cin>>s;

    vi a;

    int ans=0;

    for(char &i:s){
        int num=i-'0';
        if(num==4) ans++;
        else if(num==3 || num==1) a.push_back(3);
        else a.push_back(2);
    }




    int n=a.size();

    if(n==0){
        cout<<ans<<nl;
        return;
    }

    // watch(n);
    // watch(ans);

    vi prefix(n+1), suffix(n+1);

    prefix[0]=a[0]==2;
    suffix[n-1]=a[n-1]==3;

    
    f(i, 1, n-1) prefix[i]+=prefix[i-1]+(a[i]==2);
    for(int i=n-2; i>=0; i--) suffix[i]+=suffix[i+1]+(a[i]==3);
    
    int best=max(prefix[n-1], suffix[0]);

    f(i, 0, n-2) best=max(best, prefix[i]+suffix[i+1]);
    

    cout<<ans+(n-best)<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}