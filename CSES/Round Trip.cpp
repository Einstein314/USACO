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

const int MX = 3e5 + 5;
//check this!!
//const int MOD = 1e9 + 7;



//Remember to check int vs ll!!

int n, m, a, b, col[100001], beg, cyend, pre[100001];
vi adj[100001];
bool cyclic;

void dfs(int v){
	col[v] = 1;
	for (auto &vert : adj[v]){
		if (col[vert] == 0){
			pre[vert] = v;
			dfs(vert);
		}
		else if (pre[v] != vert && col[vert] == 1){
			cyclic = 1;
			cyend = vert;
			beg = v;
			break;
		}
	}
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");
    
	cin >> n >> m;
	F0R(i,m){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(i, 1, n+1){
		if (col[i] == 0){
			dfs(i);
		}
		if (cyclic) break;
	}
	pre[beg] = -1;
	if (!cyclic) return cout << "IMPOSSIBLE" << newl, 0;
	vi ans;
	for (int i = cyend; i != -1; i = pre[i]){
		ans.pb(i);
	}
	reverse(all(ans));
	ans.pb(beg);
	cout << sz(ans) << newl;
	for (auto &vert : ans) cout << vert << " ";
	








    return 0;

}
