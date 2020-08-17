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
//DP[i] = worst case from r to shortest path between s, i
int n, m, s, r, f, rdist[MX], rvis[MX], DP[MX], sdist[MX], svis[MX];
vi adj[MX];

void rbfs() {
	queue<int> q;
	q.push(r);
	rdist[r] = 0; rvis[r] = 1;
	while (!q.empty()) {
		int nxt = q.front(); q.pop();
		for (auto &v : adj[nxt]) {
			if (!rvis[v]) {
				q.push(v);
				rdist[v] = rdist[nxt] + 1;
				rvis[v] = 1;
			}
		}
	}
	return;
}

// check int vs ll and precision
// check logic
int main(){ FAST
    //freopen ("/Users/konwoo/input.txt", "r", stdin);
    //freopen ("/Users/konwoo/output.txt", "w", stdout);
    
    cin >> n >> m;
    F0R(i,m) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].emplace_back(b);
    	adj[b].emplace_back(a);
    }
    cin >> s >> f >> r;
    rbfs();

    queue<int> q;
    q.push(s);
    sdist[s] = 0; svis[s] = 1;
    while (!q.empty()) {
    	int cur = q.front(); q.pop();
   		int best_prev = 0;
    	for (auto &nxt : adj[cur]) {
    		if (!svis[nxt]) {
    			svis[nxt] = 1;
    			sdist[nxt] = sdist[cur] + 1;
    			q.push(nxt);
    		}
    		else if (svis[nxt] && sdist[nxt] + 1 == sdist[cur]){
    			ckmax(best_prev, DP[nxt]);
    		}
    	}
    	DP[cur] = (cur == s) ? rdist[s] : min(rdist[cur],best_prev);
    }

    finish(DP[f]);



    
    
    return 0;
}

