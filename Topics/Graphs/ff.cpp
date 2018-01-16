//Trick for 2d graph traversal

int dr[] = {1,1,0,-1,-1,-1,0,1}; //Rows are moving down vertically, columns are moving across 
int dc[] = {0,1,1,1,0,-1,-1,-1}; //S,SE,E,NE,N,NW,W,SW

int floodfill (int r, int c, char c1, char c2){
  if (r < 0 || r >= R || c < 0 || c >= C) return 0;
  if (grid[r][c] != c1) return 0;
  int ans = 1; //adds 1 to ans because vertex (r,c) has c1 as color
  grid[r][c] = c2; //to avoid cycling
  for (int d = 0; d < 8; d++){
    ans += floodfill(r + dr[d], c + dc[d], c1, c2);
  }
  return ans;
}
