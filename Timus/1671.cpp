#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0;}

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " <<

const ll MOD = 998244353;
const ll INF = 1e9 + 7;

const int MX = 1e5 + 5;
int n, m, Q, parent[MX], sz[MX], tcnt;
pii threads[MX];

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
	++tcnt;
}

int find_set(int v){
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a), b = find_set(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a,b);
		parent[b] = a;
		sz[a] += sz[b];
		--tcnt;
	}
}

// check int vs ll and precision
// check logic
int main(){ FAST
    //freopen ("/Users/konwoo/input.txt", "r", stdin);
    //freopen ("/Users/konwoo/output.txt", "w", stdout);
    
    cin >> n >> m;
    set<pii> edges;
    F0R(i,m) {
    	int a, b;
    	cin >> a >> b;
    	edges.insert({a,b});
    	threads[i+1] = {a,b};
    }
    cin >> Q;
    vi q(Q), ans(Q);
    F0R(i,Q) {
    	cin >> q[i];
    	auto [u,v] = threads[q[i]];
    	edges.erase({u,v});
    }

    FOR(i,1,n+1) make_set(i);
    for (auto &[u,v] : edges) {
    	union_sets(u,v);
    }

    for (int i = Q - 1; i >= 0; --i) {
    	auto [u,v] = threads[q[i]];
    	ans[i] = tcnt;
    	union_sets(u,v);
    }

    F0R(i,Q) {
    	cout << ans[i] << " ";
    }




    
    
    return 0;
}

