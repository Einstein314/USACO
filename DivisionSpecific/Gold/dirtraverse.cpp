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
const ll INF = 1e18;
int N;
string name[MAXN];
vi adj[MAXN];
ll ans, siz[MAXN];

ll dfs(int no, int cur){
    if (sz(adj[no]) == 0){
        siz[no] = 1;
        return cur + sz(name[no]);
    }
    if (no != 1) cur += sz(name[no]) + 1;
    ll z = 0;
    trav(a, adj[no]){
        z += dfs(a, cur);
        siz[no] += siz[a];
    }
    return z;
}

void dfs2(int no, ll cur){
    if (sz(adj[no]) == 0) return;
    ans = min(ans, cur);
    trav(a, adj[no]){
        dfs2(a, cur - siz[a]*(sz(name[a]) + 1) + (siz[1] - siz[a])*3);
    }
}

void input(){
    cin >> N;
    FOR(i, 1, N+1){
        cin >> name[i];
        int m; cin >> m;
        F0R(j, m){
            int x; cin >> x;
            adj[i].pb(x);
        }
    }
}

void solve(){
    ans = INF;
    dfs2(1, dfs(1,0));
}

int main(){
    freopen("dirtraverse.in","r",stdin);
    freopen("dirtraverse.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    pr(ans);

    
    

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}




