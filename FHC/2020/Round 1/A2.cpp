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
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0;}
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll T, N, K;

void solve(int t) {
	cin >> N >> K;
	vector<ll> L(N+1), H(N+1), W(N+1), Lvals(4), Hvals(4), Wvals(4), P(N+1);
	F0R(i,K) cin >> L[i+1]; F0R(i,4) cin >> Lvals[i];
	F0R(i,K) cin >> W[i+1]; F0R(i,4) cin >> Wvals[i];
	F0R(i,K) cin >> H[i+1]; F0R(i,4) cin >> Hvals[i];
	FOR(i,K+1,N+1) {
		L[i] = (Lvals[0] * L[i-2] + Lvals[1] * L[i-1] + Lvals[2]) % Lvals[3] + 1LL;
		W[i] = (Wvals[0] * W[i-2] + Wvals[1] * W[i-1] + Wvals[2]) % Wvals[3] + 1LL;
		H[i] = (Hvals[0] * H[i-2] + Hvals[1] * H[i-1] + Hvals[2]) % Hvals[3] + 1LL;
	}

	set<pair<ll,ll>> cur_active;
	cur_active.insert({L[1],L[1]+W[1]});
	P[1] = 2LL * W[1] + 2LL * H[1];
	FOR(i,2,N+1) {
		pair<ll,ll> merged_interval = {L[i],L[i]+W[i]};
		ll delta_perimeter = 0, cur_left = L[i], inside_cnt = 0;
		bool new_rect = true;

		auto beg_interval = cur_active.upper_bound({L[i],L[i]+W[i]});
		if (beg_interval != cur_active.begin()) {
			--beg_interval;
			auto [lval,rval] = *beg_interval;
			assert(lval <= L[i]);
			if (rval >= L[i]) {
				merged_interval.first = lval;
				cur_left = rval;
				++beg_interval;
				cur_active.erase({lval,rval});
				inside_cnt--;
				new_rect = false;
			}
			else {
				++beg_interval;
			}
		}
	


		while (true) {
			if (beg_interval == cur_active.end() || (*(beg_interval)).first > L[i] + W[i]) {
				if (cur_left < L[i] + W[i]) {
					delta_perimeter += abs(L[i] + W[i] - cur_left);
				} else {
					merged_interval.second = cur_left;
				}
				break;
			}
			auto [lval,rval] = *beg_interval;
			assert(lval >= L[i] && lval <= L[i] + W[i]);

			new_rect = false;
			delta_perimeter += (lval - cur_left);
			inside_cnt--;


			if (rval <= L[i] + W[i]) {
				cur_left = rval;
			}
			else {
				cur_active.erase({lval,rval});
				merged_interval.second = rval;
				break;
			}

			++beg_interval;
			cur_active.erase({lval,rval});
		}

		if (new_rect) {
			// new rectangle
			P[i] = (P[i-1] + 2LL * W[i] + 2LL * H[i]) % MOD;
		}
		else {
			// how much is it extended by horizontally
			P[i] = (P[i-1] + 2LL * delta_perimeter) % MOD;
			if (inside_cnt < -1) {
				ll tmp = (2LL * H[i] * (inside_cnt + 1LL)) % MOD;
				P[i] = (P[i] + tmp + MOD) % MOD;
			}
		}
		cur_active.insert(merged_interval);
	}
	ll ans = 1LL;
	FOR(i,1,N+1) {
		ans = (ans * P[i]) % MOD;
	}
	printf("Case #%d: %lld\n", t, ans);
}


// check int vs ll and precision
// check logic
int main(){ FAST
	freopen ("/Users/konwoo/input.txt", "r", stdin);
	freopen ("/Users/konwoo/output.txt", "w", stdout);

	cin >> T;
	F0R(t,T) {
		solve(t+1);
	}


    return 0;
}
	
