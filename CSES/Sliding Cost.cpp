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


ll k, n, x[200500], ans, prevm, pm2;
ordered_mset st;

int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	cin >> n >> k;
	F0R(i,n){
		cin >> x[i];
	}
	F0R(i,k) st.insert(x[i]);
	F0R(i,k){
		ans += abs(x[i] - *st.find_by_order((k-1)/2));
	}
	cout <<  ans << " ";
	prevm = *st.find_by_order((k-1)/2);
	pm2 = *st.find_by_order((k+1)/2);
	F0R(i,n-k){
		st.erase(st.find_by_order(st.order_of_key(x[i])));
		st.insert(x[i+k]);
		ll cur = *st.find_by_order((k-1)/2);
		if (k % 2 == 1) ans += (abs(x[i+k] - prevm) - abs(x[i] - cur));
		else{
			//if (x[i+k] >= prevm) ans += (abs(x[i+k] - pm2) - abs(x[i] - pm2));
			if (x[i+k] >= prevm){
				if (x[i] == pm2){
					ans += abs(x[i+k] - prevm) - abs(x[i]-prevm);
				}
				else{
					ans += abs(x[i+k] - pm2) - abs(x[i] - pm2);
				}
			}
			else ans += (abs(x[i+k] - prevm) - abs(x[i] - prevm));
		}
		cout << ans << " ";
		prevm = cur;
		pm2 = *st.find_by_order((k+1)/2);
	}

	


    
    
    

    return 0;
}
