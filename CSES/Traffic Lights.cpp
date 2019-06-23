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


int x, n, p[200500], sp[200500], dif[200500], mx;
map<int, int> a, rel;
vi ans;

int parent[200500], sz[200500];

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool same(int a, int b){
    return find_set(a) == find_set(b);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    
}

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");



	cin >> x >> n;
	F0R(i,n){
		cin >> p[i+1];
		sp[i+1] = p[i+1];
		a.insert(mp(p[i+1], i+1));
	}
	sort(sp, sp+n+1);
	sp[n+1] = x;
	FOR(i,1,n+1){
		rel.insert(mp(a[sp[i]], i));
	}
	F0R(i,n+1){
		make_set(i+1);
		dif[i+1] = sp[i+1] - sp[i];
		mx = max(mx, dif[i+1]);
	}
	FORd(i,1,n+1){
//		FOR(j, 1, n+2){
//			cout << dif[j] << " ";
//		}
//		cout << newl;
		ans.pb(mx);
		int ind = rel[i];
		int ta = dif[find_set(ind)];
		int tb = dif[find_set(ind+1)];
		dif[find_set(ind)] += tb;
		dif[find_set(ind+1)] += ta;
		union_sets(ind, ind+1);
		mx = max(mx, dif[find_set(ind)]);
	}
	F0Rd(i,n){
		cout << ans[i] << " ";
	}
	


    
    
    

    return 0;
}
