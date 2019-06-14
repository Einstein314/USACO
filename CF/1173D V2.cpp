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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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


const ll MOD = 998244353;
ll ans, fact[200500], arr[200500];
int n, u , v;
vi adj[200500];
bool visited[200500];

void dfs(int x){
	visited[x] = 1;
	for (auto a : adj[x]){
		if (!visited[a]){
			dfs(a);
			if (sz(adj[x]) == 1) arr[x] = 0;
			else arr[x] += 1;
		}
	}

}

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	cin >> n;
	F0R(i,n-1){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ans = n;
	fact[0] = 1;
	FOR(i,1,n){
		fact[i] = fact[i-1] * i % MOD;
	}
	dfs(1);
	FOR(i,1,n+1){
		if (i == 1) ans = (ans * fact[arr[i]]) % MOD;
		else ans = (ans * fact[arr[i] + 1]) % MOD;
	}
	cout << ans << newl;






    return 0;
}
