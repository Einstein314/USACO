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


struct Comp{
	bool operator()(const pair<pair<int,int>,int>& p1, const pair<pii,int>& p2){
		return p1.f.s > p2.f.s || (p1.f.s == p2.f.s && p1.f.f > p2.f.f);
	}
};

bool compv(const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2){
	return p1.f.f < p2.f.f || (p1.f.f == p2.f.f && p1.f.s < p2.f.s);
}

int n, a, b, arr[MX];
vector<pair<pii,int>> vec;
priority_queue<pair<pii,int>, vector<pair<pii,int>>, Comp> pq;


int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);
//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

	cin >> n;
	F0R(i,n){
		cin >> a >> b;
		vec.pb(mp(mp(a,b), i));
	}
	sort(vec.begin(), vec.end(), compv);
	int room = 1;
	F0R(i,n){
		if (!pq.empty() && vec[i].f.f > pq.top().f.s){
			arr[vec[i].s] = arr[pq.top().s];
			pq.pop();
		}
		else{
			arr[vec[i].s] = room;
			room++;
		}
		pq.push(vec[i]);
	}
	int maxrm = 0;
	F0R(i,n){
		maxrm = max(maxrm, arr[i]);
	}
	cout << maxrm << newl;
	F0R(i,n){
		cout << arr[i] << " ";
	}









    


    return 0;
}
