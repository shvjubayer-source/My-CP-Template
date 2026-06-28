// https://codeforces.com/problemset/problem/1778/C
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

// Q = h a b
// 10 3
// lkwujonuqa
// qoiujoncja

int numberOfSetBits(int n){
    int ans=0;
    f(i, 0, 31){
        if(checkbit(n, i)) ans++;
    }

    return ans;
}


void solve(){
    ll n, k;
    cin>>n>>k;

    string a, b;
    cin>>a>>b;

    vll idx(27, -1);
    vector<char> uni_c;

    f(i, 0, n-1){
        if(idx[a[i]-'a']==-1){
            idx[a[i]-'a']=uni_c.size();
            uni_c.push_back(a[i]);
        }
    }

    if(k>=uni_c.size()){
        cout<<1LL*(n*(n+1)/2)<<nl;
        return;
    }

    ll ans=0;

    // cout<<idx[0]<<nl;
    // cout<<idx[1]<<nl;
    // cout<<idx[2]<<nl;
    // cout<<idx[3]<<nl;
    


    int emni=uni_c.size();
    for(int i=0; i<((1LL)<<(emni)); i++){
        if(numberOfSetBits(i)!=k) continue;
        // watch(i);

        ll cur_lenth=0, cur_ans=0;

        f(j, 0, n-1){
            // watch(j);
            
            if((a[j]==b[j]) || (i & (i & (1LL << idx[a[j]-'a'])))) cur_lenth++;
            else{
                cur_ans+=(1LL*cur_lenth*(cur_lenth+1))/2;
                cur_lenth=0;
            }
            // watch(cur_ans);
            // watch(cur_lenth);

        }
        cur_ans+=(1LL*cur_lenth*(cur_lenth+1))/2;
        // watch(cur_ans);
        ans=max(ans, cur_ans);
        // watch(ans);
    }



    cout<<ans<<nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}