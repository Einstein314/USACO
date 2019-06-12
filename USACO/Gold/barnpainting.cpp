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
//#define s second
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
const ll MOD = 1e9 + 7;
ll N, K, color[MAXN], x, y, b, c, dp[MAXN][4];
vi adj[MAXN];

void dfs(int s, int e){
    if (!color[s]) dp[s][1] = dp[s][2] = dp[s][3] = 1;
    else dp[s][color[s]] = 1;
    trav(u, adj[s]){
        if (u != e){
            dfs(u, s);
            dp[s][1] *= (dp[u][2] + dp[u][3]);
            dp[s][2] *= (dp[u][3] + dp[u][1]);
            dp[s][3] *= (dp[u][1] + dp[u][2]);
            FOR(i, 1,4){
                dp[s][i] %= MOD;
            }
            
        }
    }
    
}

int main(){
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    F0R(i, N-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    F0R(i, K){
        cin >> b >> c;
        color[b] = c;
    }
    dfs(1, 0);
    ll ans = 0;
    FOR(i, 1,4){
        ans += dp[1][i];
        ans %= MOD;
    }
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




