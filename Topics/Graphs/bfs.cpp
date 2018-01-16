vi d(V, INF); d[s] = 0;
queue<int> q; q.push(s);

while (!q.empty()){
  int u = q.front(); q.pop();
 
  for (int j = 0; j < (int)AdjList[u].size(); j++){
    ii v = AdjList[u][j];
    if (v.first == INF){
      d[v.first] = d[u] + 1;
      q.push(v.first);
    }
  }
}
