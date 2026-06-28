// https://codeforces.com/problemset/problem/1730/B

#include <bits/stdc++.h>
using namespace std;
#define f(i, st, ed) for(int i=st; i<=ed; i++)
#define ll long long
#define ld long double
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

ll n;
ld ans=0;

vector<ld> getIntersection(ld a, ld b, ld c, ld d){
    if(a>b) swap(a, b);
    if(c>d) swap(c, d);

    ld l=max(a, c);
    ld r=min(b, d);

    if(l<=r) return {l, r};
    return {};
}



bool check(vll &posX, vll &shomoy, ld m){

    ld l=-1e18, r=1e18;

    f(i, 0, n-1){
        if(shomoy[i]>m) return false;

        ld remaining=m-shomoy[i];

        vector<ld> temp=getIntersection(l, r, posX[i]-remaining, posX[i]+remaining);

        if(temp.size()==0) return false;

        l=temp[0];
        r=temp[1];
    }

    // watch(l);
    // watch(r);

    ans=l;
    return l<=r;
}


void solve(){
    cin>>n;

    vll posX(n), shomoy(n);

    f(i, 0, n-1) cin>>posX[i];
    f(i, 0, n-1) cin>>shomoy[i];

    ld l=0, r=2e13;

    f(i, 1, 80){
        ld mid=l+(r-l)/2;

        // watch(mid);
        // watch(l);
        // watch(r);
        if(check(posX, shomoy, mid)) r=mid;
        else l=mid;

    }


    cout << fixed << setprecision(6) << ans << nl;

}

int main(){
    fastio;
    test solve();
    return 0;
}