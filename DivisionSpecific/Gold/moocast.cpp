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


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}



const int MX = 1050;
int N, x, y, ans;
pii coords[MX];


int parent[MX], size[MX];

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool same(int a, int b){
    return find_set(a) == find_set(b);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
    
}

struct Edge {
    int u, v, weight;
};

bool compw(const Edge& a, const Edge& b){
    return a.weight < b.weight;
}

vector<Edge> edges;



int main(){
    //    ifstream fin("/Users/konwoo/input.txt");
    //    ofstream fout("/Users/konwoo/output.txt");
    //    freopen("/Users/konwoo/desktop/input","r",stdin);
    //    freopen("/Users/konwoo/desktop/output","w",stdout);
    
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    
    cin >> N;
    F0R(i,N) cin >> x, cin >> y, coords[i].f = x, coords[i].s = y;
    F0R(i, N){
        FOR(j, i+1, N){
            Edge newe;
            newe.u = i;
            newe.v = j;
            newe.weight = pow(coords[j].f - coords[i].f,2) + pow(coords[j].s - coords[i].s,2);
            edges.pb(newe);
        }
    }
    sort(all(edges),compw);
    F0R(i,N) make_set(i);
    for (Edge e : edges){
        if (!same(e.u, e.v)){
            ans = max(ans, e.weight);
            union_sets(e.u, e.v);
        }
    }
    
    cout << ans << "\n";
    
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // Check array bounds (be careful about assummptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}

