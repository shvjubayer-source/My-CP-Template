// https://codeforces.com/contest/2220/problem/D1
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

int ask1(int l, int r){
    // cout<<"f"<<endl;

    cout << "? " << r - l + 1 << " ";

    f(i, l, r) cout << i <<" ";

    cout << endl;

    int n;

    cin >> n;


    return n;
}       


int leftIdx(int n){
    int left = 1, right = 2 * n + 1;

    while(left < right){
        int mid = left + (right - left) / 2;

        int total_distinct = ask1(mid, 2 * n + 1);

        int total_num = (2 * n + 1) - mid + 1;

        int total_remaining = total_num - total_distinct;

        if(total_remaining % 2 == 1) left = mid + 1;
        else right = mid;
    }

    return left - 1;
}


int rightIdx(int n){
    int left = 1, right = 2 * n + 1;

    while(left < right){
        int mid = left + (right - left) / 2;
        
        int total_distinct = ask1(1, mid);

        int total_num = mid;

        int total_remaining = total_num - total_distinct;

        if(total_remaining % 2 == 1) right = mid;
        else left = mid + 1;
    }


    return left;
}


bool checkRight(int leftIdx, int rightIdx, int l, int r){
    // cout<<"checkright"<<endl;0

    cout << "? " << 2 + r - l + 1 << " " << leftIdx << " ";

    f(i, l, r) cout << i <<" ";

    cout << rightIdx << endl;


    int n;
    cin >> n;

    int total_num = 2 + r - l + 1;
    int total_remainin = total_num - n;


    return total_remainin % 2 == 1;

}

// n = 5

// 2*n+1

// 1 2 3 3 1 2 3 4 5 4 5
//    1 2 3 4 5 6 7 8 9 10 11
// 4 5 9 11

// 3 1 5 5
// 2



void solve(){
    int n;
    cin >> n;

    // finding the leftmost index 
    int left = leftIdx(n);


    // finding the rightmost index
    int right = rightIdx(n);


    // finding the middle index

    int l = left + 1, r = right - 1;

    if(l == r){
        cout << "! " << left << " " << l << " " << right << endl;
        return;
    }

    while(l < r){
        if(l + 1 == r){
            if(checkRight(left, right, l, l)) l=l;
            else l=r;

            break;
        }

        int mid = l + (r - l) / 2;


        if(checkRight(left, right, mid, r)) l = mid;
        else r = mid;



    }




    
    cout << "! " << left << " " << l << " " << right << endl;
}

int main(){
    fastio;
    test solve();
    return 0;
}

// 1 1 1 2 2

// 1 2 1 2 1