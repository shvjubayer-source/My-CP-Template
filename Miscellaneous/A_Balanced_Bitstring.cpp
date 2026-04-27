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
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;


    f(i, 0, k-1){
        if(s[i]=='?'){
            if(i+k<=n-1){
                if(s[i+k]!='?'){
                    s[i]=s[i+k];
                }
            }
        }
    }

    vi idx;
    int zero=0, one=0;


    f(i, 0, k-1){
        if(s[i]=='?'){
            int ok=-1;
            for(int j=i+k; j<n; j+=k){
                if(s[j]!='?'){
                    ok=j;
                    break;
                }
            }

            if(ok==-1) idx.push_back(i);
            else s[i]=s[ok];

        }
    }   

    f(i, 0, k-1){
        if(s[i]=='0') zero++;
        else if(s[i]=='1') one++;
    }

    if(one>k/2 || zero>k/2){
        no;
        return;
    }

    f(i, 1, (k/2)-zero){
        if(idx.empty()){ no; return; }
        s[idx.back()]='0';
        idx.pop_back();
    }

    f(i, 1, (k/2)-one){
        if(idx.empty()){ no; return; }
        s[idx.back()]='1';
        idx.pop_back();
    }


    f(i, k, n-1){
        if(s[i]=='?') s[i]=s[i-k];
        if(s[i]!=s[i-k]){
            no;
            return;
        }
    }




    yes;
    
}

int main(){
    fastio;
    test solve();
    return 0;
}