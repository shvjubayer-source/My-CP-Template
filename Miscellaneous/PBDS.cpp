// https://codeforces.com/problemset/problem/1703/F
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const ll M = 1000000007;



void solve(){
    int n;
    cin>>n;

    ll ans=0;
    ordered_set<int> s;


    f(i, 1, n){
        int x; cin>>x;
        if(x<i){
            int cnt=s.order_of_key(x);
            ans+=cnt;
            s.insert(i);
        }
    }


    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}



// Everything about ordered set
// It is same as set with extra functionalities
// same operation of sets are insert(), erase(), find(), clear(), size(), empty()
// Extra Operations are order_of_key(), find_by_order()

// cnt=s.order_of_key(x);
// gives the index of x or how many elements smaller than x

// auto it = s.find_by_order(x);
// Returns the k-th smallest element it works like index of array and vector Example: a[0]


// how to store unique elements
// ordered_set<pair<int,int>> s;
// int id = 0;

// s.insert({10, id++});
// s.insert({10, id++});


// count elements in range [l, r]
// int cnt = s.order_of_key(r + 1) - s.order_of_key(l);

