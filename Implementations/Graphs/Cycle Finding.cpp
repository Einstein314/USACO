//From https://cp-algorithms.com/graph/finding-cycle.html, Check: CSES Round Trip

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
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;


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
#define trav(a,b) for (auto a : b)

const int MX = 1e5 + 5;
//check this!!
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;


vi adj[N];
int col[N], par[N], cycend, cycstart;
//0 if not processed, 1 while processing, 2 done processing

bool dfs(int x){
	col[x] = 1;
	for (auto &a : adj[x]){
		if (col[a] == 0){
			par[a] = x;
			if (dfs(a)) return 1;
		}
		if (col[a] == 1){
			// for undirected when you don't want edges to count as cycles
			if (par[x] != a){
				cycend = x;
				cycstart = a;
				return 1;
			}

		}
	}
	col[x] = 2;
	return 0;
}


//Remember to check int vs ll!!
int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
//   ifstream cin("/Users/konwoo/input.txt");
 //   ofstream cout("/Users/konwoo/output.txt");
	 
	 cycstart = -1;
	 
	 F0R(i,n){
		 if (dfs(i)) break;
	 }
	 vi cyc;
	 par[cycstart] = -1;
	 while (cycend != -1){
		 cyc.pb(cycend);
		 cycend = par(cycend);
	 }
	 reverse(all(cyc));
	 for (auto & a : cyc){
		 cout << a << " ";
	 }

	 
	 








    return 0;
}

