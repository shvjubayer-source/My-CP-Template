// https://codeforces.com/problemset/problem/1878/E
//segmentree to calculate range AND
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

struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }


    SegTree(vi &a){
        this->n=a.size();
        tree.assign(4*n, 0);
        build(a);
    }

    void build(vector<int> &a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, idx*2, l, mid);
        build(a, idx*2+1, mid+1, r);
        tree[idx] = tree[idx*2] & tree[idx*2+1];
    }

    void build(vector<int> &a) {
        build(a, 1, 0, n-1);
    }

    // Point update: a[pos] = val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos, val);
        else update(idx*2+1, mid+1, r, pos, val);
        tree[idx] = tree[idx*2] & tree[idx*2+1];
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }


    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MAX; 
        if (ql <= l && r <= qr) return tree[idx];  
        int mid = (l + r) / 2;
        return query(idx*2, l, mid, ql, qr) &
               query(idx*2+1, mid+1, r, ql, qr);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve(){
    int n;
    cin>>n;

    vi a(n+1);
    f(i, 1, n) cin>>a[i];

    SegTree Tree(a);


    int q;
    cin>>q;

    while(q--){
        int l, k;
        cin>>l>>k;



        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }

        int left=l, right=n+1;
        while(left<right){
            int mid=(left+right)/2;
            int temp=Tree.query(l, mid);

            // watch(left);
            // watch(right);
            // watch(temp);
            
            if(temp>=k) left=mid+1;
            else right=mid;

        }

        cout<<left-1<<" ";
    }

    cout<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}