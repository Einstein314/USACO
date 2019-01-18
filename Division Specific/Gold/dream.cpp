#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;


#define FOR(i,a,b) for (int i =a; i<b;i++)
#define F0R(i,a) for (int i =0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1;i >=a;i--)
#define F0Rd(i,a) for (int i = (a)-1;i >=0; i--)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pr(x) cout << x << "\n"
#define bug(x) cout << x << " "
#define trav(a,x) for (auto& a : x)


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}


const int MAXN = 1e3 + 5;
int N, M, maze[MAXN][MAXN], ans;

bool visited[MAXN][MAXN][5][2];

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

struct state {
    int r;
    int c;
    int dist;
    int ld;
    bool smell;
    
    state(int r, int c, int dist, int ld, bool smell) :
    r(r), c(c), dist(dist), ld(ld), smell(smell){
    }
};

bool isv(int row, int col){
    return (row >= 0) && (row < N) && (col >= 0) && (col < M);
}

void input(){
    cin >> N >> M;
    F0R(i, N){
        F0R(j, M){
            cin >> maze[i][j];
        }
    }
}

int bfs(){
    memset(visited, 0, sizeof(visited));
    visited[0][0][0][0] = 1;
    
    queue<state> q;
    state st = {0, 0, 0, -1, 0};
    q.push(st);
    
    while(!q.empty()){
        state curr = q.front();
        q.pop();
        
        if (curr.r == N-1 && curr.c == M-1 ){
            return curr.dist;
        }
        
        //sliding case
        if (maze[curr.r][curr.c] == 4 && curr.ld != -1){
            int row = curr.r + dr[curr.ld];
            int col = curr.c + dc[curr.ld];
            if (isv(row, col) && maze[row][col] != 0 && maze[row][col] != 3){
                if (visited[row][col][curr.ld+1][maze[row][col] == 2] != 0){
                    continue;
                }
                visited[row][col][curr.ld+1][maze[row][col] == 2] = 1;
                state tmp = {row, col, curr.dist + 1, curr.ld, maze[row][col] == 2};
                q.push(tmp);
                continue;
            }
            
//            if (isv(row, col) && !visited[row][col][curr.ld+1][curr.smell] && maze[row][col] != 0 && ((maze[row][col] != 3) || (maze[row][col] == 3 && curr.smell == 1))){
//                if (maze[row][col] == 4){
//                    visited[row][col][curr.ld+1][0] = 1;
//                    q.push(tmp);
//                    continue;
//                }
//                else if (maze[row][col] == 2){
//                    visited[row][col][curr.ld+1][1] = 1;
//                    state tmp = {row, col, curr.dist + 1, curr.ld, 1};
//                    q.push(tmp);
//                    continue;
//                }
//                else{
//                    visited[row][col][curr.ld+1][curr.smell] = 1;
//                    state tmp = {row, col, curr.dist + 1, curr.ld, curr.smell};
//                    q.push(tmp);
//                    continue;
//                }
//            }
        }
        
        //adjacent cases
        F0R(i, 4){
            int row = curr.r + dr[i];
            int col = curr.c + dc[i];
            if (!isv(row, col) || maze[row][col] == 0 || (maze[row][col] == 3 && !curr.smell)){
                continue;
            }
            int tp = maze[row][col] == 2 ? true : maze[row][col] == 4 ? false : curr.smell;
            if (visited[row][col][curr.ld+1][tp] != 0){
                continue;
            }
            visited[row][col][curr.ld+1][tp] = 1;
            state tmp = {row, col, curr.dist + 1, i, tp};
            q.push(tmp);
//            
//            if (isv(row, col) && !visited[row][col][curr.ld+1][curr.smell]){
//                if (maze[row][col] == 0){
//                    continue;
//                }
//                else if (maze[row][col] == 1 || (maze[row][col] == 3 && curr.smell)){
//                    visited[row][col][curr.ld+1][curr.smell] = 1;
//                    state tmp = {row, col, curr.dist + 1, i, curr.smell};
//                    q.push(tmp);
//                }
//                else if (maze[row][col] == 2){
//                    visited[row][col][curr.ld+1][1] = 1;
//                    state tmp = {row, col, curr.dist + 1, i, 1};
//                    q.push(tmp);
//                }
//                else if (maze[row][col] == 4){
//                    visited[row][col][curr.ld+1][0] = 1;
//                    state tmp = {row, col, curr.dist + 1, i, 0};
//                    q.push(tmp);
//                }
//            }
        }
        
    }
    
    return -1;
}

void solve(){
    pr(bfs());
    
}

int main(){
        freopen("dream.in","r",stdin);
        freopen("dream.out","w",stdout);
//    freopen("/Users/konwoo/Desktop/input.txt", "r", stdin);
//    freopen("/Users/konwoo/Desktop/output.txt", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    F0R(i, N){
        F0R(j, M){
            cin >> maze[i][j];
        }
    }
    //    input();
    solve();
    
    
    
    
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


