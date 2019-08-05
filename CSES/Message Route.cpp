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
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;




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

/*
struct custom_hash{
	static uint64_t splitmix64(uint64_t x){
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}

};
*/

int n, m, a, b, d1[100005], p[100005];
vi adj[100005];
queue<int> q1;

//Remember to check int vs ll!!

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	cin >> n >> m;
	F0R(i,m){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	q1.push(1);
	memset(d1, -1, sizeof(d1));
	d1[1] = 0;
	p[1] = -1;
	while (!q1.empty()){
		int vert = q1.front();
		q1.pop();
		for (auto &c : adj[vert]){
			if (d1[c] != -1) continue;
			d1[c] = d1[vert] + 1;
			p[c] = vert;
			q1.push(c);
		}
	}
	if (d1[n] == -1) return cout << "IMPOSSIBLE" << newl, 0;
	vi ans;
	int cur = n;
	while (cur != -1){
		ans.pb(cur);
		cur = p[cur];
	}
	reverse(all(ans));
	cout << sz(ans) << newl;
	for (auto &v : ans) cout << v << " ";



	







    return 0;
}
