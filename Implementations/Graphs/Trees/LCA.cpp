// verify 342E
// based on Benq's

const int MX = 1e5 + 5;
int first_pos[MX], depth[MX];
vi adj[MX];
vector<pii> euler;

// min seg tree
Seg<pii> st;

int lca (int u, int v) {
    if (first_pos[u] > first_pos[v]) swap(u, v);
    return st.query(first_pos[u], first_pos[v]).second;
}

int dist (int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u,v)];
}

// Euler tour
void dfsE (int x, int p = -1) {
    first_pos[x] = sz(euler);
    euler.emplace_back(depth[x], x);
    for (auto &y : adj[x]) {
        if (y != p) {
            depth[y] = depth[x] + 1;
            dfsE(y, x);
            euler.emplace_back(depth[x], x);
        }
    }
}

