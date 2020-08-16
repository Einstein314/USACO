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



int T, N, K;
ll ans;
char V[1000005];
//Remember to check int vs ll!!

const ll MOD = 1e9 + 7;

void exp2(int ex){
	ll tmp = 1;
	ll bas = 2;
	while (ex){
		if (ex & 1) tmp = (1LL * tmp * bas) % MOD;
		ex >>= 1, bas = (bas * bas) % MOD;
	}
	ans = (ans + tmp) % MOD;
}

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
    ifstream cin("/Users/konwoo/input.txt");
	ofstream cout("/Users/konwoo/output.txt");

	cin >> T;
	F0R(t,T){
		cin >> N >> K;
		F0R(i,N) cin >> V[i+1];
		ans = 0;
		int cur = 0;
		FORd(i,1,N+1){
			if (cur < 0) cur = 0;
			cur += (V[i] == 'A' ? -1 : 1);
			if (cur > K){
				exp2(i);
				cur -= 2;
			}
		}
		cout << "Case #" << t+1 << ": " << ans << newl;
	}







    return 0;
}
