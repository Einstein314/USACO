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



char bd[8][8];
int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7}, col[8], diag1[20], diag2[20], cnt;


void search(int x){
	if (x == 8){
		cnt++;
		return;
	}
	F0R(i,8){
		if (col[i] || diag1[i + x] || diag2[i-x+7] || bd[x][i] == '*'){
			continue;
		}
		col[i] = diag1[i+x] = diag2[i-x+7] = 1;
		search(x+1);
		col[i] = diag1[i+x] = diag2[i-x+7] = 0;
	}

}

int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");


	F0R(i,8) F0R(j,8) cin >> bd[i][j];
	search(0);
	cout << cnt << newl;











    return 0;
}
