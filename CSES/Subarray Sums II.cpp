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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;


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


ll n, x, arr[MX], cnt, pref[MX];
map<ll,ll> trck;
multiset<ll> mst;

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

    
	cin >> n >> x;
	F0R(i,n){
		cin >> arr[i];
		pref[i+1] = pref[i] + arr[i];
		trck[pref[i+1]]++;
		//mst.insert(pref[i+1]);
	}
//	for (auto &a : mst) if (a == x) cnt++;
	cnt += trck[x];
	F0R(i,n){
		trck[pref[i+1]]--;
		cnt += trck[x + pref[i+1]];
		
//		mst.erase(mst.find(pref[i+1]));
//		cnt += mst.count(x + pref[i+1]);
	}
	cout << cnt << newl;

	
    

    return 0;
}
