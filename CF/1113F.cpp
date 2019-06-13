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


const ll MOD = 1e9 + 7;
const ll MXN = 1e6;
ll n, m, a, b, ans, fact[MXN + 1], inv[MXN + 1], pm[MXN + 1], pn[MXN + 1], finv[MXN + 1];

ll bc(ll n, ll k){
	return ((fact[n] * finv[k] % MOD) % MOD * finv[n-k] % MOD) % MOD;
}
int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	cin >> n >> m >> a >> b;

	fact[0] = 1;
	FOR(i, 1, MXN+1){
		fact[i] = fact[i-1] * i % MOD;
	}
	inv[1] = 1;
	FOR(i, 2, MXN+1){
		inv[i] = (MOD - (MOD/i) * inv[MOD % i] % MOD) % MOD;
	}
	finv[0] = 1;
	finv[1] = 1;
	FOR(i, 2, MXN+1){
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
	pm[0] = 1;
	FOR(i, 1, MXN+1){
		pm[i] = pm[i-1] * m % MOD;
	}
	pn[0] = 1;
	FOR(i, 1, MXN+1){
		pn[i] = pn[i-1] * n % MOD;
	}
	FOR(k, 1, min(n, m+1)){
		ll tmp = (bc(m-1, k-1) * fact[k-1]) % MOD;
		ll tmp2 = pm[n-1-k] % MOD;
		ll tmp3 = bc(n-2, k-1) % MOD;
		ll tmp4 = 0;
		if (k == n-1) tmp4 = 1;
		else tmp4 = (k+1) * pn[n-k-2] % MOD;

		tmp = (tmp * tmp2) % MOD;
		tmp3 = (tmp3 * tmp4) % MOD;
		tmp = (tmp * tmp3) % MOD;
		ans = (ans + tmp) % MOD;
	}
	cout << ans << newl;






    return 0;
}