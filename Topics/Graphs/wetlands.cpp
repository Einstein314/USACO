#include "/Users/konwoo/stdc++.h"
//#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;


#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

//#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<vii> AdjList;



int N;
int R = 100, C = 100;
char grid[105][105];



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


int main(){
    ifstream fin("/Users/konwoo/input.txt");
    ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("measurement.in");
//    ofstream fout("measurement.out");
    fin >> N;
    F0R(i, N){
        F0R(j, N){
            fin >> grid[i][j];
        }
    }
    int x, y;
    fin >> x >> y;
    int a = floodfill(x-1, y-1, 'W', '.');
    fout << a;


    return 0;
}
