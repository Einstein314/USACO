//FOR DFS, inside int main()

numCC = 0;
dfs_num.assign(V, UNVISITED) //label all vertices as unvisited
for (int i = 0; i < V; i++){
  if (dfs_num[i] == UNVISITED){
    printf("CC %d:", ++numCC), dfs(i), printf("\n");
  }
}

Ex:
CC 1: 0 1 2 3 4
CC 2: 5 
CC 3: 6 7 8 

Graph:
0 - 1 - 3 - 4 5
    |  /
    2   7 - 6 - 8
