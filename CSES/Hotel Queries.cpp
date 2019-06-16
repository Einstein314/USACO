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


int n, m, h[200500], r, t[5000];

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

	cin >> n >> m;
	F0R(i,n) cin >> h[i];
	int sqr = (int) ceil(sqrt((double)n));
	F0R(i,sqr){
		int maxtmp = -1;
		if (i * sqr >= n) continue;
		FOR(j, i*sqr, min((i+1)*sqr, n)){
			maxtmp = max(maxtmp, h[j]);
		}
		t[i] = maxtmp;
	}
	// if n == 2, t[0] is the only element
	F0R(i,m){
		cin >> r;
		bool bad = 1;
		F0R(j, sqr){
			if (t[j] >= r){
				bad = 0;
				int ind = -1;
				bool foind = 0;
				int newmx = -1;
				FOR(k, j*sqr, min(n, (j+1)*sqr)){
					if (h[k] >= r && !foind){
						h[k] -= r;
						foind = 1;
						ind = k + 1;
					}
					newmx = max(newmx, h[k]);
				}
				t[j] = newmx;
				cout << ind << " ";
				break;
			}
		}
		if (bad){
			cout << 0 << " ";
		}
	}












    return 0;
}
