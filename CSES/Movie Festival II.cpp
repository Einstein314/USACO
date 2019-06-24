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

bool compv(const pii& p1, const pii& p2){
    return p1.s < p2.s || (p1.s == p2.s && p1.f < p2.f);
}

int n, a, b, k, cnt;
vector<pii> vec;
set<pii> ppl;
ordered_set<pii> ppl2;

int bins(int vali){
	int lo = 0, hi = sz(ppl2) - 1;
	if (vali < ppl2.find_by_order(lo)->f) return 0;
	else if (vali > ppl2.find_by_order(hi)->f) return hi+1;
	while (lo < hi){
		int mid = (lo + hi)>>1;
		int tmp = ppl2.find_by_order(mid)->f;
		int tmpl = ppl2.find_by_order(lo)->f;
		int tmpr = ppl2.find_by_order(hi)->f;
		if (vali >= tmpl && vali < tmpr && hi - lo == 1) break;
		else if (tmp > vali) hi = mid;
		else lo = mid;
	}
	return hi;
}


int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

    cin >> n >> k;
    if (n == k) return cout << n << newl, 0;
    F0R(i,n){
        cin >> a >> b;
        vec.pb(mp(a,b));
    }
    sort(vec.begin(), vec.end(), compv);
	ppl2.insert(mp(vec[0].s, 0));
	cnt = 1;
    FOR(i,1,n){
        pii mv = vec[i];
		int mind = bins(mv.f);
        if (mind == 0 && sz(ppl2) < k) ppl2.insert(mp(mv.s, i)), cnt++;
        else if (mind == 0) continue;
        else{
			pii tmp = mp(ppl2.find_by_order(mind-1)->f, ppl2.find_by_order(mind-1)->s);
			ppl2.erase(tmp);
			ppl2.insert(mp(mv.s,i));
            cnt++;
         }
/*
        cout << newl;
         for (auto &d : ppl2){
         cout << d.f << " ";
         }
         cout << newl;
//		 cout << mind << newl;
         
*/
    }
    cout << cnt << newl;





    return 0;
}
