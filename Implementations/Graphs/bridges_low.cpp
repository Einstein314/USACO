//Verify with 118E 

//tin[u] = time entering vertex u 
//low[u] = min reachable tin[v] from subtree of u

int bridges, cur_time, tin[MX], low[MX];
vi adj[MX];

void dfs(int u, int p){
    ++cur_time; tin[u] = cur_time; low[u] = cur_time;

    for (int nxt : adj[u]){
        if (tin[nxt] == 0){
            //span edge
            dfs(nxt, u);
            low[u] = min(low[u], low[nxt]);
            if (low[nxt] > tin[u]){
                ++bridges;
            }
        }
        else if (nxt != p){
            //back edge
            low[u] = min(low[u], tin[nxt]);
        }


    }
}
