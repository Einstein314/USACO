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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


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

const int MAXN = 1e4 + 5;
int N, M, T, cows[MAXN], a, b, t;

pii cows2[MAXN];

const int INF = 1e9;
vi parent;
vector<ll> dist;
vector< pair<int, ll> > adj[MAXN];
vi paths[MAXN];

void dijkstra(int s, vector<ll> &d, vi &p){
    
    d.assign(N+1, INF);
    p.assign(N+1, -1);
    
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int v = pq.top().s;
        ll d_v = pq.top().f;
        pq.pop();
        if (d_v != d[v]) continue;
        
        for (auto edge : adj[v]){
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                pq.push({d[to],to});
            }
        }
    }
}


int main(){
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> T;
    FOR(i, 1, N+1){
        cin >> cows[i];
        cows2[i].f = cows[i];
        cows2[i].s = i;
    }
    sort(cows2+1, cows2+1+N);
    reverse(cows2+1, cows2+1+N);
    
    F0R(i, M){
        cin >> a >> b >> t;
        adj[a].pb({b,t});
        adj[b].pb({a,t});
    }
    
    dijkstra(1, dist, parent);

    
        
    FOR(i, 2, N+1){
        for (int v = i; v != 1; v = parent[v]){
            paths[v].pb(i);
        }
    }

    
    ll ans = 0;
    FORd(j, 2, N+1){
        ll temp = 0;
        if (dist[j] > T){
            trav(a, paths[j]){
                temp += cows[a] * (-T + dist[j]);
            }
        }
        ans = max(ans, temp);
    }
    pr(ans);
    
    
    //becareful about max value of N vs max value of M

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


