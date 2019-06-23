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
ll n, ans;
vector<array<ll,3>> intervs;



ll f(ll k){
	return n/k;
}

void rec(ll from, ll to, function<ll(ll)> f, ll &i, ll &p, ll q, vector<array<ll,3>> &ints){
	if (p == q) return;
	if (from == to){
		ints.pb({i, to, p});
		i = to;
		p = q;
	}
	else{
		ll mid = (from + to) >> 1;
		rec(from, mid, f, i , p, f(mid), ints);
		rec(mid + 1, to, f, i, p, q, ints);
	}
}

void constantIntervals(ll from, ll to, function<ll(ll)> f, vector<array<ll,3>> &ints){
	if (to <= from) return;
	ll i = from;
	ll p = f(i), q = f(to - 1);
	rec(from, to - 1, f, i , p ,q, ints);
	ints.pb({i,to, q});
}


int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	cin >> n;
	constantIntervals(1,n+1,f,intervs);
	for (auto &a : intervs){
		ll lo = a[0];
		ll hi = a[1];
		lo %= MOD;
		hi %= MOD;
		a[2] %= MOD;
		ll tmplo = lo * (lo - 1)/2 % MOD;
		ll tmphi = hi * (hi - 1)/2 % MOD;
		ll td = (tmphi - tmplo + MOD) % MOD;
		ans = (ans + (td * a[2]) % MOD) % MOD;
	}
	cout << ans << newl;
    
    
    
    
    
    
    

    return 0;
}
