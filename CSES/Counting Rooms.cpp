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


int n, m, vis[1002][1002], rooms;
char bd[1002][1002];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
	if (bd[x][y] == '#' || vis[x][y]) return;
	vis[x][y] = 1;
	F0R(k,4) bfs(x+dx[k],y+dy[k]);
}


//Remember to check int vs ll!!

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	cin >> n >> m;
	F0R(i,m+2) bd[0][i] = '#', bd[n+1][i] = '#';
	F0R(j,n+2) bd[j][0] = '#', bd[j][m+1] = '#';
	F0R(i,n){
		F0R(j,m){
			cin >> bd[i+1][j+1];
		}
	}
	F0R(i,n){
		F0R(j,m){
			if (bd[i+1][j+1] == '#' || vis[i+1][j+1]) continue;
			bfs(i+1, j+1);
			rooms++;
		}
	}
	cout << rooms << newl;







    return 0;
}
