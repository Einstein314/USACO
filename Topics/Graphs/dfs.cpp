typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

vi dfs_num;

void dfs(int u){
  dfs_num[u] = VISITED;
  for(int j = 0; j < (int)AdjList[u].size(); j++){
    pii v = AdjList[u][j];
    if (dfs_num[v.first] == UNVISITED){
      dfs(v.first);
    }
  }
}

//v.second is the weight of the edge
