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
#define d(x) cout << x << "\n"
#define bug(x) cout << x << " "
#define trav(a,x) for (auto& a : x)


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int MAXN = 1e5 + 100;
const ll INF = 1e10;
int N, M, K, a, b, t, hay[MAXN], ind, yum;


vector<ll> dist;
//----------------------------------------------------
//parent is unncessary

vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int s, vector<ll> &d){
    
    d.assign(N+1, INF);
    
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int v = pq.top().s;
        int d_v = pq.top().f;
        pq.pop();
        if (d_v != d[v]) continue;

        for (auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]){
                d[to] = d[v] + len;
                pq.push({d[to],to});
            }
        }
    }
}


//----------------------------------------------------

vector<ll> mdist;

void mdijkstra(vector<ll> &d){
    
    d.assign(N+1, INF);
    
    FOR(i, 1,N+1){
        if (hay[i]){
            d[i] = dist[i] - hay[i];
            pq.push({d[i], i});
        }
    }
    
    while(!pq.empty()){
        int v = pq.top().s;
        int d_v = pq.top().f;
        pq.pop();
        if (d_v != d[v]) continue;
        
        for (auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]){
                d[to] = d[v] + len;
                pq.push({d[to],to});
            }
        }
    }
}

//----------------------------------------------------

int main(){
    //freopen("dining.in","r",stdin);
    //freopen("dining.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    F0R(i,M) {
        cin >> a >> b >> t;
        adj[a].pb({b,t});
        adj[b].pb({a,t});
    }
    FOR(i,1,K+1){
        cin >> ind >> yum;
        hay[ind] = max(hay[ind], yum);
    }
    dijkstra(N, dist);
    mdijkstra(mdist);
    FOR(i, 1, N){
        if (dist[i] >= mdist[i]){
            d(1);
        }
        else d(0);
    }
    

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}




