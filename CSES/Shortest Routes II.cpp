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

ll n, m, a, b, c, q, dist[501][501];
vector<pair<ll,ll>> adj[501];

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");
    
	cin >> n >> m >> q;
	FOR(i, 1, n+1){
		FOR(j, 1, n+1){
			dist[i][j] = 1e18;
		}
	}
	F0R(i,m){
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
		dist[a][b] = min(dist[a][b],c);
		dist[b][a] = min(dist[a][b],c);
	}
	FOR(i, 1, n+1) dist[i][i] = 0;
	FOR(k, 1, n+1){
		FOR(i, 1, n+1){
			FOR(j, 1, n+1){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	F0R(i,q){
		cin >> a >> b;
		cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << newl;
	}





    return 0;

}
