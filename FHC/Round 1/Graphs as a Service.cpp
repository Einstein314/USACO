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


int T, N, M, x, y, z;

//Remember to check int vs ll!!

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
    ifstream cin("/Users/konwoo/input.txt");
	ofstream cout("/Users/konwoo/output.txt");

	cin >> T;
	F0R(t,T){
		cin >> N >> M;
		int dist[55][55];
		map<pii,int> mp1;
		FOR(i, 1, N+1) FOR(j, 1, N+1) dist[i][j] = 2000000;
		F0R(j, M){
			cin >> x >> y >> z;
			dist[x][y] = z;
			dist[y][x] = z;
			mp1[mp(x,y)] = z;
		}
		FOR(i, 1, N+1){
			dist[i][i] = 0;
		}
		FOR(k, 1, N+1){
			FOR(i, 1, N+1){
				FOR(j, 1, N+1){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		bool chck = 1;
		for (auto &a : mp1){
			if (dist[a.f.f][a.f.s] != a.s){
				chck = 0;
				break;
			}
		}
		cout << "Case #" << t+1 << ": ";
		if (!chck) cout << "Impossible" << newl;
		else{
			cout << sz(mp1) << newl;
			for (auto &a : mp1){
				cout << a.f.f << " " << a.f.s << " " << a.s << newl;
			}
		}
	}


	







    return 0;
}
