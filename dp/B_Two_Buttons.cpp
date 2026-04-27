// https://codeforces.com/contest/520/problem/B
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
    int n, m;
    cin>>n>>m;

    if(n>=m){
        cout<<n-m<<nl;
        return;
    }

    int ans=0;

    while(m>n){
        if(m%2==0){
            m/=2;
        }else{
            m++;
            m/=2;
            ans++;
        }
        ans++;
    }

    // watch(n);
    // watch(m);
    // watch(ans);

    cout<<ans+(n-m)<<nl;

}

int main(){
    fastio;
    solve();
    return 0;
}



//graph solution
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define pl pair<ll,ll>
#define vl vector<ll>
#define dl deque<ll>
#define sl set<ll>
#define usl unordered_set<ll>
#define msl multiset<ll>
#define ml map<ll,ll>
#define mml multimap<ll,ll>
#define uml unordered_map<ll,ll>
#define vpl vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define endl "\n"
#define pi 3.14159265358979323846L

vector<vl> g(100000);
vl vis(100000),lvl(100000);

void bfs(ll n){
    queue<ll> q;
    q.push(n);
    vis[n]=1;
    while(!q.empty()){
        ll p=q.front();
        q.pop();
        for(auto c:g[p]){
            if(!vis[c]){
                q.push(c);
                vis[c]=1;
                lvl[c]=lvl[p]+1;
            }
        }
    }
}

int main() {
    fastio;
    ll n,m;
    cin >> n >> m;
    for(ll i=1;i<=100000;i++) g[i].pb(i-1);
    for(ll i=2;i<=100000;i+=2) g[i/2].pb(i);
    bfs(n);
    
    cout << lvl[m] << endl;
    
    return 0;
}


// dp solution

#include <bits/stdc++.h>
using namespace std;
const int N = 20107;
vector<int> dp(N,-1),used(N);
int solve(int x,int m)
{
    if(x >= m) return x-m;
    if(x < 0) return 100000;
    if(dp[x] != -1) return dp[x];
    if(used[x]) return 100000;
    used[x] = 1;
    return dp[x] = 1 + min(solve(x-1,m),solve(2*x,m));
}
int main() {
	int n,m; cin >> n >> m;
	
	if(n >= m) cout << n-m << endl;
	else 
	{
	    cout << solve(n,m) << endl;
	}
}
