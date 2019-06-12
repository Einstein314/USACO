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

const int MAXN = 1e5 + 100;
const int INF = 1e9;
int N, K, a, b, leaf[MAXN], dist[MAXN], ans;
vi adj[MAXN], cleaf(MAXN, INF);

void dfs(int s, int e){
    trav(u, adj[s]){
        if (u != e) {
            dist[u] = dist[s] + 1;
            dfs(u,s);
        }
    }
    
}

void fleaf(){
    FOR(i, 1, N+1){
        if (sz(adj[i]) == 1){
            leaf[i] = 1;
        }
    }
}

void bfs(){
    vi d(MAXN, INF); d[K] = 0; //Distances from source
    queue<int> q; q.push(K);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(v, adj[u]){
            if(cleaf[v] <= dist[v]){
                ans++;
                continue;
            }
            if(d[v] == INF){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void mbfs(){
    queue<int> q;
    FOR(i, 1, N+1){
        if (leaf[i]){
            cleaf[i] = 0;
            q.push(i);
        }
    }

    
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(v, adj[u]){
            if(cleaf[v] == INF){
                cleaf[v] = cleaf[u] + 1;
                q.push(v);
            }
        }
    }
   
}

void solve(){
    fleaf();
    dfs(K, 0);
    mbfs();
    bfs();
    pr(ans);
}



int main(){
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    F0R(i, N-1){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
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




