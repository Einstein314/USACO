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
typedef vector<pii> vii;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;


#define FOR(i,a,b) for (int i = a; i < b; i++)
#define F0R(i,a) for (int i = 0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i>=0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define f first
#define s second
#define newl '\n'
#define mp make_pair

const int MX = 2e5 + 5;
//check this!!
//const int MOD = 1e9 + 7;



//Remember to check int vs ll!!

int n, m, a, b, st[100001], par[1000001], beg, cyend;
vi adj[100001];
bool acyclic;

bool dfs(int v){
	st[v] = 1;
	for (auto &vert : adj[v]){
		if (st[vert] == 0){
			par[vert] = v;
			if (dfs(vert)) return 1;
		}
		else if (st[vert] == 1){
			acyclic = 0;
			beg = vert;
			cyend = v;
			return 1;
		}
	}
	st[v] = 2;
	return 0;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");
    
	cin >> n >> m;
	memset(par, -1, sizeof(par));
	F0R(i,m){
		cin >> a >> b;
		adj[a].pb(b);
	}
	acyclic = 1;
	FOR(i,1,n+1){
		if (st[i] == 0) dfs(i);
		if (!acyclic) break;
	}
	if (acyclic) return cout << "IMPOSSIBLE" << newl, 0;
	vi ans;
	par[beg] = -1;
	for (int i = cyend; i != beg; i = par[i]){
		ans.pb(i);
	}
	ans.pb(beg);
	reverse(all(ans));
	ans.pb(beg);
	cout << sz(ans) << newl;
	for (auto &c : ans) cout << c << " ";




    return 0;

}
