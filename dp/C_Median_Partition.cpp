// https://codeforces.com/contest/2222/problem/C
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



void solve(){
    int n;
    cin>>n;

    vi a(n+1);

    f(i, 1, n) cin>>a[i];

    vi temp=a;

    sort(all(temp));

    int med=temp[n/2+1];

    vi pS(n+1), pL(n+1), pE(n+1); //smaller, larger, equal

    f(i, 1, n){
        pE[i]+=pE[i-1]+(a[i]==med);
        pS[i]+=pS[i-1]+(a[i]<med);
        pL[i]+=pL[i-1]+(a[i]>med);
    }

    // watch(med);

    // f(i, 1, n) cout<<pS[i]<<" ";
    // cout<<nl;
    // f(i, 1, n) cout<<pE[i]<<" ";
    // cout<<nl;
    // f(i, 1, n) cout<<pL[i]<<" ";
    // cout<<nl<<nl;


    vi dp(n+1, -1);

    dp[0]=0;

    f(i, 0, n){
        if(dp[i]==-1) continue;

        f(j, i+1, n){

            if((j-i)%2==0) continue;

            int smaller=pS[j]-pS[i];
            int greater=pL[j]-pL[i];
            int equal=pE[j]-pE[i];

            if(equal>0 && (abs(smaller-greater)==0 || abs(smaller-greater)<equal)){

                dp[j]=max(dp[j], dp[i]+1);

            }

        }

    }

    cout<<((dp[n]==-1)? 0 : dp[n])<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}