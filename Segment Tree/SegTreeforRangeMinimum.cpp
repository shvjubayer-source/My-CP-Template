#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }


    void build(vector<long long> &a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, idx*2, l, mid);
        build(a, idx*2+1, mid+1, r);
        tree[idx] = min(tree[idx*2] , tree[idx*2+1]);
    }

    void build(vector<long long> &a) {
        build(a, 1, 0, n-1);
    }


    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos, val);
        else update(idx*2+1, mid+1, r, pos, val);
        tree[idx] = min(tree[idx*2] , tree[idx*2+1]);
    }

    void update(int pos, long long val) {
        update(1, 0, n-1, pos, val);
    }


    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return INT_MAX;  
        if (ql <= l && r <= qr) return tree[idx];  
        int mid = (l + r) / 2;
        return min(query(idx*2, l, mid, ql, qr) , query(idx*2+1, mid+1, r, ql, qr));
    }

    long long query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};





int main(){
    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    SegTree st(n);
    st.build(arr);

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;

        if(t == 1){
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r-1) << endl;
        }
    }
}
