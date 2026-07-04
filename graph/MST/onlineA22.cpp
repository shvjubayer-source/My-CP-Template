#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) for Kruskal's Algorithm
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, w, id;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// Helper function to compute the product using standard long long
long long compute_product(const vector<int>& edge_indices, const vector<Edge>& edges) {
    long long res = 1;
    for (int idx : edge_indices) {
        res *= edges[idx].w;
    }
    return res;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    // Sort edges by weight in non-decreasing order
    sort(edges.begin(), edges.end());

    // Step 1: Find the Minimum Spanning Tree (Primary Plan)
    DSU dsu(N);
    vector<int> mst_edges;
    vector<bool> in_mst(M, false);

    for (int i = 0; i < M; ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst_edges.push_back(i);
            in_mst[i] = true;
        }
    }

    // If the graph is disconnected, no spanning tree exists
    if ((int)mst_edges.size() < N - 1) {
        cout << -1 << "\n";
        return 0;
    }

    long long min_prod = compute_product(mst_edges, edges);
    long long best_second = -1;
    bool found = false;

    auto update_best = [&](long long cand) {
        if (cand > min_prod) {
            if (!found || cand < best_second) {
                best_second = cand;
                found = true;
            }
        }
    };

    // Step 2: Method A - Fundamental Cycle 1-Edge Swaps from the MST
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int idx : mst_edges) {
        adj[edges[idx].u].push_back({edges[idx].v, idx});
        adj[edges[idx].v].push_back({edges[idx].u, idx});
    }

    for (int i = 0; i < M; ++i) {
        if (in_mst[i]) continue;

        // Find the unique path in the MST between edges[i].u and edges[i].v
        vector<int> path;
        auto dfs = [&](auto& self, int curr, int parent, int target) -> bool {
            if (curr == target) return true;
            for (auto& edge : adj[curr]) {
                int nxt = edge.first;
                int edge_idx = edge.second;
                if (nxt == parent) continue;
                path.push_back(edge_idx);
                if (self(self, nxt, curr, target)) return true;
                path.pop_back();
            }
            return false;
        };

        dfs(dfs, edges[i].u, -1, edges[i].v);

        // Try replacing each tree edge on the cycle with the non-tree edge i
        for (int tree_idx : path) {
            if (edges[tree_idx].w < edges[i].w) {
                vector<int> cand_indices = mst_edges;
                for (int& idx : cand_indices) {
                    if (idx == tree_idx) {
                        idx = i;
                        break;
                    }
                }
                update_best(compute_product(cand_indices, edges));
            }
        }
    }

    // Step 3: Method B & C - Force Inclusion and Exclusion for all edges
    for (int i = 0; i < M; ++i) {
        // Force Include edge i
        {
            DSU dsu_in(N);
            vector<int> tree_indices;
            dsu_in.unite(edges[i].u, edges[i].v);
            tree_indices.push_back(i);

            for (int j = 0; j < M; ++j) {
                if (i == j) continue;
                if (dsu_in.unite(edges[j].u, edges[j].v)) {
                    tree_indices.push_back(j);
                }
            }
            if ((int)tree_indices.size() == N - 1) {
                update_best(compute_product(tree_indices, edges));
            }
        }

        // Force Exclude edge i
        {
            DSU dsu_out(N);
            vector<int> tree_indices;
            for (int j = 0; j < M; ++j) {
                if (i == j) continue;
                if (dsu_out.unite(edges[j].u, edges[j].v)) {
                    tree_indices.push_back(j);
                }
            }
            if ((int)tree_indices.size() == N - 1) {
                update_best(compute_product(tree_indices, edges));
            }
        }
    }

    // Output Result
    if (!found) {
        cout << -1 << "\n";
    } else {
        cout << best_second << "\n";
    }

    return 0;
}