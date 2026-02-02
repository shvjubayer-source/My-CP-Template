// https://codeforces.com/problemset/problem/2193/F

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

ll dist(ll a, ll b, ll c, ll d){
    return abs(a-c)+abs(b-d);
}


void solve(){
    int n, Ax, Ay, Bx, By;
    cin>>n>>Ax>>Ay>>Bx>>By;
    
    vi x(n), y(n);
    f(i, 0, n-1) cin>>x[i];
    f(i, 0, n-1) cin>>y[i];

    map<int, int> top, bottom;

    top[Ax]=Ay;
    top[Bx]=By;
    bottom[Ax]=Ay;
    bottom[Bx]=By;


    f(i, 0, n-1){
        top[x[i]]=max(top[x[i]], y[i]);
        if(bottom[x[i]]==0){
            bottom[x[i]]=y[i];
        }else{
            bottom[x[i]]=min(bottom[x[i]], y[i]);
        }
    }


    vector<pair<int,int>> bottoms, tops;
    for(auto &i:bottom) bottoms.push_back({i.first, i.second});
    for(auto &i:top) tops.push_back({i.first, i.second});

    // watch(tops.size());
    // watch(bottoms.size());

    // f(i, 0, tops.size()-1){
    //     // cout<<tops[i].first<<" "<<tops[i].second<<" "<<bottoms[i].second<<endl;
    //     cout<<tops[i].first<<" "<<bottoms[i].first<<endl;

    // }


    // cout<<endl;
    vector<vector<ll>> dp(bottoms.size()+10, vector<ll>(2, LLONG_MAX));

    dp[0][0]=0;
    dp[0][1]=0;

    //  |
    //  |                               (a1, b1)
    //  |
    //  |
    //  |           (c1, d1)
    //  |
    //  |                               (a2, b2)
    //  |
    //  |           (c2, d2)
    //  |
    //  |__________________________________________


    f(i, 1, bottoms.size()-1){
        ll c1=tops[i-1].first;
        ll d1=tops[i-1].second;
        ll c2=bottoms[i-1].first;
        ll d2=bottoms[i-1].second;

        ll a1=tops[i].first;
        ll b1=tops[i].second;
        ll a2=bottoms[i].first;
        ll b2=bottoms[i].second;
        //top
        dp[i][0]=min(dp[i][0], dp[i-1][0]+dist(c1, d1, a2, b2)+dist(a1, b1, a1, b2));
        dp[i][0]=min(dp[i][0], dp[i-1][1]+dist(c2, d2, a2, b2)+dist(a1, b1, a1, b2));

        //bottom
        dp[i][1]=min(dp[i][1], dp[i-1][0]+dist(c1, d1, a1, b1)+dist(a1, b1, a1, b2));
        dp[i][1]=min(dp[i][1], dp[i-1][1]+dist(c2, d2, a1, b1)+dist(a1, b1, a1, b2));



    }


    cout<<min(dp[bottoms.size()-1][1], dp[bottoms.size()-1][0])<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}