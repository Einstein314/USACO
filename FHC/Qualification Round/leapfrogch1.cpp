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


int T, N, sb;
string str;

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	ifstream cin("/Users/konwoo/Downloads/leapfrog_ch_.txt");
	ofstream cout("/Users/konwoo/output.txt");


	
	cin >> T;
	F0R(i,T){
		cout << "Case #" << i+1 << ": ";
		cin >> str;
		N = str.length();
		sb = 0;
		F0R(j,N) sb += (str[j] == 'B');
		cout << ((sb <= N - 2 && (sb * 2) >= N - 1) ? "Y" : "N");
        if (i != T-1) cout << newl; 
	}










    return 0;
}
