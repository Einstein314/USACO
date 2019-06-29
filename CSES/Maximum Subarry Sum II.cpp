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
const ll MOD = 1e9 + 7; 

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


ll n, a, b, x[MX], p[MX], lg[MX], st[MX][25], ans;

ll q(int l, int r){
	int j = lg[r - l + 1];
	return max(st[l][j], st[r - (1 << j) + 1][j]);
}

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

	cin >> n >> a >> b;
	F0R(i,n){
		cin >> x[i];
		p[i] = (!i ? x[i] : p[i-1] + x[i]);
	}
	lg[1] = 0;
	FOR(i, 2, MX) lg[i] = lg[i/2] + 1;
	F0R(i,n) st[i][0] = p[i];
	FOR(j, 1, 26) for (int i = 0; i + (1 << j) <= n; i++) st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
	ans = -1e15;
	ans = max(ans, q(a-1, b-1));
	FOR(i,1,n-a+1){
		ans = max(ans, q(a-1+i,min(b-1+i,n-1)) - p[i-1]);
	}
	cout << ans << newl;
	








    return 0;
}
