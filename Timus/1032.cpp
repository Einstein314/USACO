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

int N;
vi adj[10000];

// check int vs ll and precision
// check logic
int main(){ FAST
    //freopen ("/Users/konwoo/input.txt", "r", stdin);
    //freopen ("/Users/konwoo/output.txt", "w", stdout);



	cin >> N;
	vi nums(N), pref(N), rnums(N);
	F0R(i,N) {
		cin >> rnums[i]; nums[i] = rnums[i]; nums[i] %= N;
		pref[i] = nums[i] + (!i ? 0 : pref[i-1]);
		pref[i] %= N;
		adj[pref[i]].pb(i);
	}
	if (sz(adj[0]) > 0) {
		int ind = adj[0][0];
		cout << ind + 1 << newl;
		F0R(i,ind+1) {
			cout << rnums[i] << newl;
		}
	}
	else {
		F0R(i,N) {
			if (sz(adj[i]) > 1) {
				int u = adj[i][0], v = adj[i][1];
				if (u > v) swap(u,v);
				cout << v - u << newl;
				FOR(j,u+1,v+1) {
					cout << rnums[j] << newl;
				}
				return 0;
			}
		}
	}





    
    
    return 0;
}

