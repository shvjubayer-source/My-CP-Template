#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1, 0);

    // build graph + compute indegree
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // push all nodes with indegree 0
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int child : g[node]) {
            indegree[child]--;

            if (indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    // cycle detection
    if ((int)topo.size() != n) {
        cout << "Cycle detected\n";
    } else {
        for (int x : topo) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}