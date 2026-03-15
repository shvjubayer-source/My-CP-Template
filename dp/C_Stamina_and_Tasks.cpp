// https://codeforces.com/contest/2208/problem/C
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



void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);

    f(i, 0, n-1) cin>>a[i].first>>a[i].second;

    double ans=a[n-1].first;

    for(int i=n-2; i>=0; i--){
        double f=(1-(double)a[i].second/100);
        int c=a[i].first;

        ans=max(ans, c+f*ans);
    }



    cout<<fixed<<setprecision(10)<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}


//another solution
#include <bits/stdc++.h>
using namespace std;

double dp[100010];

double solve(int idx, vector<pair<int,int>>& points)
{
    if(idx >= points.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    double survive = 1 - (points[idx].second / 100.0);

    double take = points[idx].first + survive * solve(idx+1, points);
    double notTake = solve(idx+1, points);

    return dp[idx] = max(take, notTake);
}

int main() {
    int t; 
    cin >> t;

    while(t--)
    {
        int n; 
        cin >> n;

        vector<pair<int,int>> points(n);

        for(int i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;

        for(int i = 0; i <= n; i++)
            dp[i] = -1;

        cout << fixed << setprecision(10);
        cout << max(1.0, solve(0, points)) << endl;
    }
}