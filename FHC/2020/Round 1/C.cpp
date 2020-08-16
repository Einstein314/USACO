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

int T, N, K;
ll A, B, C, m1, m2, m1cnt, m2cnt, mval, mval_cnt;
vector<vi> adj;
vector<ll> safe, parent, sz, subt_sz, safe_cnt, m1_vec, m2_vec;

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find_set(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a), b = find_set(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a,b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

void init() {
	safe.assign(N+5,0);
	parent.assign(N+5,0);
	sz.assign(N+5,1);
	adj.assign(N+5,vi(0));
	subt_sz.assign(N+5,0);
	safe_cnt.assign(N+5,0);
	m1_vec.assign(N+5,0);
	m2_vec.assign(N+5,0);
	F0R(i,N+5) make_set(i);
    m1 = 0; m1cnt = 0; m2 = 0; m2cnt = 0;
	mval = 0; mval_cnt = 0;
}

ll choose2(ll x) {
	return x * (x - 1LL) / 2LL;
}

pair<ll,ll> dfs_allsafe(int u, int p) {
	subt_sz[u] = 1;
	safe_cnt[u] = safe[u];
	for (auto &v : adj[u]) {
		if (v != p) {
			auto [csz, ccnt] = dfs_allsafe(v, u);
			subt_sz[u] += csz;
			safe_cnt[u] += ccnt;
		}
	}

	if (p != -1) {
		if (!safe[u] || !safe[p]) {
			ll tmp = (1LL * subt_sz[u]) * (1LL * ((1LL * N) - subt_sz[u]));
			mval_cnt += tmp;
		}
		else {
			assert(safe[u] && safe[p]);
			ll tmp = (1LL * safe_cnt[u]) * (1LL * ((1LL * m1) - safe_cnt[u]));
			mval_cnt += tmp;
		}
	}

	return {subt_sz[u],safe_cnt[u]};
}

ll dfs_allmax(int u, int p) {
	if (safe[u]) {
		if ((p == -1 || !safe[p]) && sz[find_set(u)] == m1) {
			m1_vec[u] = m1;
		}
	}
	for (auto &v : adj[u]) {
		if (v != p) {
			m1_vec[u] += dfs_allmax(v, u);
		}
	}
	if (p != -1) {
		if (!safe[u] || !safe[p]) {
			ll tot_m1cnt = m1cnt * m1;
			ll tmp = m1_vec[u] * ((1LL * tot_m1cnt) - m1_vec[u]);
			mval_cnt += tmp;
		}
	}
	return m1_vec[u];
}

pair<ll,ll> dfs_somemax(int u, int p) {
	if (safe[u]) {
		if (p == -1 || !safe[p]) {
			if (sz[find_set(u)] == m1) {
				m1_vec[u] = m1;
			}
			if (sz[find_set(u)] == m2) {
				m2_vec[u] = m2;
			}
		}
	}
	for (auto &v : adj[u]) {
		if (v != p) {
			//auto [m1v, m2v] = dfs_somemax(v, u);
			dfs_somemax(v,u);
			m1_vec[u] += m1_vec[v];
			m2_vec[u] += m2_vec[v];
		}
	}
	if (p != -1) {
		if (!safe[u] || !safe[p]) {
			ll tot_m1cnt = m1cnt * m1, tot_m2cnt = m2cnt * m2;
			ll tmp = m1_vec[u] * (tot_m2cnt - m2_vec[u]) + m2_vec[u] * (tot_m1cnt - m1_vec[u]);
			mval_cnt += tmp;
		}
	}
	return {m1_vec[u], m2_vec[u]};
}

void solve() {
	string labels;
	cin >> N >> K >> labels;
	init();
	int scnt = 0;
	F0R(i,N) {
		safe[i+1] = (labels[i] == '*');
		scnt += safe[i+1];
	}
	vector<ll> E(N+5);
	FOR(i,2,K+2) {
		cin >> E[i];
		adj[i].push_back(E[i]);
		adj[E[i]].push_back(i);
		if (safe[i] && safe[E[i]]) union_sets(i,E[i]);
	}
	cin >> A >> B >> C;
	for (ll i = K + 2; i <= 1LL * N; ++i) {
		E[i] = ((A * E[i-2] + B * E[i-1] + C) % (i - 1LL)) + 1;
		adj[i].push_back(E[i]);
		adj[E[i]].push_back(i);
		if (safe[i] && safe[E[i]]) union_sets(i,E[i]);
	}

	map<ll,int> cc_sizes;
	vector<bool> seen(N+1);
	set<ll> sizes;
	FOR(i,1,N+1) {
		if (!safe[i] || seen[find_set(i)]) continue;
		seen[find_set(i)] = 1;
		cc_sizes[sz[find_set(i)]]++;
		sizes.insert(sz[find_set(i)]);
	}
	if (!sizes.empty()) {
		m1 = *(sizes.rbegin()); m1cnt = cc_sizes[m1];
	}

	// one cc
	if (scnt == m1) {
		mval = m1 * (m1 - 1LL) / 2LL;
		dfs_allsafe(1,-1);
		return;
	}

	if (m1cnt > 1) {
		//easy case
		mval = choose2(2LL * m1);

		for (auto blah : cc_sizes) {
			ll ccsz = blah.first, szcnt = blah.second;
			if (ccsz == m1) {
				ll tmp = (szcnt - 2) * choose2(m1);
				mval += tmp;
			}
			else {
				ll tmp = szcnt * choose2(ccsz);
				mval += tmp;
			}

		}


		dfs_allmax(1, -1);
		return;
	}
	else {
		assert(m1cnt == 1 && sz(sizes) > 1);
		sizes.erase(m1);
		m2 = *(sizes.rbegin()); m2cnt = cc_sizes[m2];

		ll tot_val = m1 + m2;
		mval = choose2(tot_val);

		for (auto blah : cc_sizes) {
			ll ccsz = blah.first, szcnt = blah.second;
			if (ccsz == m1 || ccsz == m2) {
				ll tmp = (szcnt - 1) * choose2(ccsz);
				mval += tmp;
			}
			else {
				ll tmp = szcnt * choose2(ccsz);
				mval += tmp;
			}
		}
		
		dfs_somemax(1,-1);
		return;
	}
	return;
}

// check int vs ll and precision
// check logic
int main(){ FAST
	freopen ("/Users/konwoo/input.txt", "r", stdin);
	freopen ("/Users/konwoo/output.txt", "w", stdout);

	cin >> T;
	F0R(t,T) {
		solve();
		cout << "Case #" << t + 1 << ": " << mval << " " << mval_cnt << newl;
	}


    return 0;
}
	
