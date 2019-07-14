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

ll n, m, a, b, cst, dist[100001], seen[100001];
vector<pair<ll,ll>> adj[100001];

void dijkstra(){
	priority_queue<pair<ll,ll>> pq;
	pq.push(mp(0,1));
	F0R(i,n+1) dist[i] = 1e15;
	dist[1] = 0;
	while (!pq.empty()){
		ll vert = pq.top().s;
		pq.pop();
		if (seen[vert]) continue;
		seen[vert] = 1;
		for (auto &v : adj[vert]){
			ll wt = v.s, v2 = v.f;
			if (dist[v2] > dist[vert] + wt){
				dist[v2] = dist[vert] + wt;
				pq.push(mp(-1 * dist[v2], v2));
			}
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
		cin >> a >> b >> cst;
		adj[a].pb(mp(b,cst));
	}
	dijkstra();
	FOR(i, 1, n+1){
		cout << dist[i] << " ";
	}





    return 0;

}
