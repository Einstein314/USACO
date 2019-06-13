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


int n, a[300500], pref[300500];
map<int,int> ev, od;

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	cin >> n;
	ev[0]++;
	F0R(i,n){
		cin >> a[i+1];
		pref[i+1] = pref[i];
		pref[i+1] ^= a[i+ 1];
		if ((i + 1) % 2 == 0){
			ev[pref[i+1]]++;
		}
		else{
			od[pref[i+1]]++;
		}
	}
	ll ans = 0;
	for (map<int,int>::iterator it = ev.begin(); it != ev.end(); ++it){
		ans += 1ll * ((int) it->s) * (((int) it->s) - 1)/2; 
	}
	for (map<int,int>::iterator it1 = od.begin(); it1 != od.end(); ++it1){
		ans += 1ll * ((int) it1->s) * (((int) it1->s) - 1)/2; 
	}

	cout << ans << newl;






    return 0;
}