// verify 321C
// based on benq

const int MX = 1e5 + 5;
vi adj[MX];
// rem[i] = if i has been removed
// subt[i] = size of subtree i 
// cpar[i] = parent of i in centroid tree
int rem[MX], subt[MX], cpar[MX];

// precompute size of subtrees
int dfs (int x, int p = -1) {
    subt[x] = 1;
    for (auto &y : adj[x]) {
        if (y != p && !rem[y]) {
            subt[x] += dfs(y,x);
        }
    }
    return subt[x];
}

// recursively calculate centroid
int gen_centroid (int x, int tot, int p = -1) {
    for (auto &y : adj[x]) {
        if (y != p && !rem[y]) {
            if (subt[y] * 2 > tot) {
                return gen_centroid(y, tot, x);
            }
        }
    }
    return x;
}

void centroid (int x = 0, int p = -1) {
    int C = gen_centroid(x, dfs(x));
    rem[C] = 1; cpar[C] = p;
    for (auto &y : adj[C]) {
        if (!rem[y]) {
            centroid(y, C);
        }
    }
}
