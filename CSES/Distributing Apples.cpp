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
const ll MX = 3e6 + 5;
ll n, a, b, fact[MX+1], inv[MX+1], finv[MX+1];

ll bc(ll m, ll k){
	return ((fact[m] * finv[k] % MOD) % MOD * finv[m-k] % MOD) % MOD;

}

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	
	fact[0] = 1;
	FOR(i, 1, MX) fact[i] = fact[i-1] * i % MOD;
	inv[1] = 1;
	FOR(i, 2, MX) inv[i] = (MOD - (MOD/i) * inv[MOD % i] % MOD) % MOD;
	finv[0] = 1, finv[1] = 1;
	FOR(i, 2, MX) finv[i] = finv[i-1] * inv[i]  % MOD;

	
	ll m;
	cin >> n >> m;
	cout << bc(n + m - 1, n - 1) << newl;
    
    
    
    

    return 0;
}
