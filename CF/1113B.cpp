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


int n, a[50050];

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	cin >> n;
	int sm1 = 0;
	F0R(i,n){
		cin >> a[i];
		sm1 += a[i];
	}
	sort(a, a+n);
	int nge =0 ;
	FORd(i,1,n){
		int tmp = 0;
		vi temp;
		FOR(j, 1, a[i]+1){
			if (a[i] % j == 0 ){
				tmp = j;
				temp.pb(j);
			}
		}
		for (auto b : temp){
			nge = min(nge, a[0] * b + a[i]/ b - a[0] - a[i]);
		}
	}
	 cout << min(sm1 + nge, sm1) << newl;






    return 0;
}