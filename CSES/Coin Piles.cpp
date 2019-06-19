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



ll t, a, b;

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	cin >> t;
	F0R(i,t){
		cin >> a >> b;
		if (a == 0 && b == 0) {
			cout << "YES" << newl;
			continue;
		}
		if ((a < 2 && b < 2) || a == 0 || b == 0) cout << "NO" << newl;
		else if ((a+b) % 3 == 0 && a <= 2 * b && b <= 2*a) cout << "YES" << newl;
		else cout << "NO" << newl;

	}
	












    return 0;
}
