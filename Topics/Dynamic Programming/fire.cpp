//#include "bits/stdc++.h"
#include "/Users/konwoo/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
//#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, f[2005], ans;
vector<int>v[2005], order;
struct node{
	int t, d, p, id;
}nd[110];

int comp(node x, node y){return x.d < y.d;}

int main()
{
	cin >> n;
	for (int i = 1; i < n+1; i++){
		cin >> nd[i].t >> nd[i].d >> nd[i].p;
		nd[i].id = i;
	}
	sort(nd+1, nd+n+1, comp);

	for (int i = 1; i < n+1; i++){
		for (int j = nd[i].d - 1; j >= nd[i].t; j--){
			if (f[j] < f[j-nd[i].t] + nd[i].p){
				f[j] = f[j-nd[i].t] + nd[i].p;
				v[j] = v[j-nd[i].t];
				v[j].pb(nd[i].id);
			}
		}
	}
	for (int i = 0; i <= 2000; i++) if (ans < f[i]){ans = f[i]; order=v[i];}
	cout << ans << endl << order.size() << endl;
	F0R(i, order.size()){
		cout << order[i] << " ";
	}



    return 0;
}
