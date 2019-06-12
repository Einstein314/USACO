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


const int MAXN = 1e5 + 10;
int N, M, ind[MAXN];
vi adj[MAXN], inp[MAXN], res;


//function for topo sort
vi topo(int bin){
    
    res.clear();
    
    FOR(i, 1, N+1){
        ind[i] = 0;
        adj[i].clear();
    }
    
    F0R(i, bin){
        F0R(j, sz(inp[i])-1){
            ind[inp[i][j+1]]++;
            adj[inp[i][j]].pb(inp[i][j+1]);
        }
    }
    
    priority_queue<int,vi,greater<int>> pq;
    FOR(i, 1, N+1) if(!ind[i]) pq.push(i);
    
    while(!pq.empty()){
        int z = pq.top(); pq.pop();
        res.pb(z);
        trav(u, adj[z]){
            ind[u]--;
            if(!ind[u]) pq.push(u);
            
        }
        
    }
    
    return res;
}


int main(){
        freopen("milkorder.in","r",stdin);
        freopen("milkorder.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    F0R(i, M){
        int l; cin >> l;
        F0R(j, l){
            int k;
            cin >> k;
            inp[i].pb(k);
        }
    }
    
    //bin search with lexo topo sort
    int lo = 0, hi = M;
    F0R(i, 17){
        int mid = (lo + hi + 1)/2;
        if (sz(topo(mid)) == N) lo = mid;
        else hi = mid - 1;
    }
    vi tmp = topo(lo);
    F0R(i, sz(tmp) - 1){
        bug(tmp[i]);
    }
    cout << tmp[sz(tmp)-1] << "\n";
    
   
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


