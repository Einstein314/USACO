//Verify with 118E 
//dp[u] = # of back edges going over edge u--p

const int MX = 1e5 + 5;
int lvl[MX], dp[MX], bridges;
vi adj[MX];

lvl[1] = 1;

void dfs(int u, int p){
    dp[u] = 0;
    for (int v : adj[u]){
        //unvisited
        if (lvl[v] == 0){
            lvl[v] = lvl[u] + 1;
            dfs(v,u);
            dp[u] += dp[v];
        }
        else if (lvl[v] < lvl[u] && v != p){
            //back edge going above
            ++dp[u];
        }
        else if (lvl[v] > lvl[u]){
            //back edge going below
            --dp[u];
        }
    }
    
    if (u > 1 && dp[u] == 0){
        ++bridges;
    }
}
