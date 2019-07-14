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
#define trav(a,b) for (auto a : b)

const int MX = 2e5 + 5;
//check this!!
//const int MOD = 1e9 + 7;
const ll MOD = 998244353;


ll n, p[MX], q, k, x, a, b;
char ch;
ordered_mset om;

//Remember to check int vs ll!!
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");

	cin >> n >> q;
	F0R(i,n){
		cin >> p[i];
		om.insert(p[i]);
	}
	F0R(t,q){
		cin >> ch;
		if (ch == '!'){
			cin >> k >> x;
			om.erase(om.find_by_order(om.order_of_key(p[k-1])));
			p[k-1] = x;
			om.insert(x);
		}
		else{
			cin >> a >> b;
			int t1 = om.order_of_key(b+1), t2 = om.order_of_key(a);
			cout << t1 - t2 << newl;
		}
	}





    return 0;
}
