#include <bits/stdc++.h>
using namespace std;

struct State {
    long long d;
    int u;
    int usedM;
    int usedD;

    bool operator<(State const& other) const {
        return d > other.d; // min-heap
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n+1);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    int x, y, w;
    cin >> x >> y >> w;

    const long long INF = 1e18;

   
    long long dist[n+1][2][2];

    for(int i=0; i<=n; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++) dist[i][j][k]=INF;
        }
    }


    priority_queue<State> pq;

    dist[1][0][0] = 0;
    pq.push({0, 1, 0, 0});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(cur.d != dist[cur.u][cur.usedM][cur.usedD]) continue;

        for(auto [v, cost] : g[cur.u]) {

            int nm = cur.usedM;
            int nd = cur.usedD;

            if(cur.u == x && v == y && cost == w) {
                nm = 1;
            }

            // 1) no discount
            if(dist[v][nm][nd] > cur.d + cost) {
                dist[v][nm][nd] = cur.d + cost;
                pq.push({dist[v][nm][nd], v, nm, nd});
            }

            // 2) use discount
            if(nd == 0) {
                long long nc = cur.d + cost / 2;
                if(dist[v][nm][1] > nc) {
                    dist[v][nm][1] = nc;
                    pq.push({nc, v, nm, 1});
                }
            }
        }
    }

    long long ans = min(dist[n][1][0], dist[n][1][1]);

    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}