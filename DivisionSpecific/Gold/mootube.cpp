/*
 ID: konwoo.1
 LANG: C++
 TASK: nocows
 */


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
#define debug(x) cout << x << "\n"

//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//const int MX = 100001;
//double PI = 4*atan(1);

// CHECK ARRAY BOUNDS, precision errors, check ll vs int
// CHECK DEFINE AND MACROS

//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int INF = 1e9;

struct Edge {
    ll u, v, weight;
};

bool compw(const Edge& a, const Edge& b){
    return a.weight > b.weight;
}


ll N, Q, p, q, r, k, vid, ans[100500];
vector<Edge> edges;
vector< pair< pair<ll, ll>, ll> > qs;

ll parent[100500], size[100500]; //where n is number of vertices, note change this to n+1 if your vertices are numbered 1 to n

void make_set(ll v){
    parent[v] = v;
    size[v] = 1;
}

ll find_set(ll v){
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool same(ll a, ll b){
    return find_set(a) == find_set(b);
}

void union_sets(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
    
}


int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
    //     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
    //     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> Q;
    
    //process edges (reverse order)
    F0R(i, N-1){
        cin >> p >> q >> r;
        Edge temp = {p, q, r};
        edges.pb(temp);
    }
    sort(all(edges), compw);
    
    //process queries (reverse order)
    F0R(i, Q){
        cin >> k >> vid;
        qs.pb(mp(mp(k,vid),i));
    }
    sort(all(qs));
    reverse(all(qs));
    
    //DSU part
    F0R(i, N+1){
        make_set((ll) i);
    }
    ll ind = 0;
    F0R(i, Q){
        while (ind < N - 1 && edges[ind].weight >= qs[i].f.f){
            union_sets(edges[ind].u, edges[ind].v);
            ind++;
        }
        ans[qs[i].s] = size[find_set(qs[i].f.s)] - 1;
    }
    F0R(i, Q){
        cout << ans[i] << "\n";
    }
    
    
    
    
    
    
    return 0;
}

