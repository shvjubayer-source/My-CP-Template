// https://codeforces.com/contest/2207/problem/C
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

ll getVal(vll &a, vll &left, vll &right, int i, int h){
    return left[i]+right[i]-(h-a[i]);
}

struct SegTree {
    int n;
    vector<pair<long long,int>> tree;

    SegTree(vector<long long> &a){
        n = a.size();
        tree.assign(4*n, {0,-1});
        build(a,1,0,n-1);
    }

    void build(vector<long long> &a, int idx, int l, int r) {
        if(l==r){
            tree[idx] = {a[l], l};
            return;
        }

        int mid=(l+r)/2;

        build(a,idx*2,l,mid);
        build(a,idx*2+1,mid+1,r);

        tree[idx]=max(tree[idx*2],tree[idx*2+1]);
    }

    void update(int idx,int l,int r,int pos,long long val){
        if(l==r){
            tree[idx]={val,pos};
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid) update(idx*2,l,mid,pos,val);
        else update(idx*2+1,mid+1,r,pos,val);

        tree[idx]=max(tree[idx*2],tree[idx*2+1]);
    }

    void update(int pos,long long val){
        update(1,0,n-1,pos,val);
    }

    pair<long long,int> query(int idx,int l,int r,int ql,int qr){
        if(qr<l || ql>r) return {LLONG_MIN,-1};

        if(ql<=l && r<=qr) return tree[idx];

        int mid=(l+r)/2;

        return max(
            query(idx*2,l,mid,ql,qr),
            query(idx*2+1,mid+1,r,ql,qr)
        );
    }

    pair<long long,int> query(int l,int r){
        return query(1,0,n-1,l,r);
    }
};



void solve(){
    int n, h;
    cin>>n>>h;

    vll a(n+5); a[0]=h; a[n+1]=h;

    f(i, 1, n) cin>>a[i];


    vll left(n+5), right(n+5);


    f(i, 1, n){
        int j=i-1;
        while(j>=1 && a[j]<a[i]) j--;
        left[i]=left[j]+(i-j)*(h-a[i]);

    }

    for(int i=n; i>=1; i--){
        int j=i+1;
        while(j<=n && a[j]<a[i]) j++;

        right[i]=right[j]+(j-i)*(h-a[i]);
    }


    SegTree st(a);

    ll ans=0;
    
    f(i, 1, n){
        f(j, i, n){
            auto it=st.query(i, j);

            ll temp=getVal(a, left, right, i, h)+getVal(a, left, right, j, h)-getVal(a, left, right, it.second, h);

            ans=max(ans, temp);
        }
    }



    cout<<ans<<nl;
}

int main(){
    fastio;
    test solve();
    return 0;
}