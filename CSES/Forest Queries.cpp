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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;


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
//const int MOD = 1e9 + 7;



//Remember to check int vs ll!!

int n, q, px1, py1, px2, py2, trees[1001][1001];
char forst[1001][1001];


int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");
    
	cin >> n >> q;
	F0R(i,n){
		F0R(j,n){
			cin >> forst[i+1][j+1];
		}
	}
	F0R(i,n){
		F0R(j,n){
			trees[i+1][j+1] = trees[i][j+1] + trees[i+1][j] - trees[i][j] + (forst[i+1][j+1] == '*' ? 1 : 0);
		}
	}
	F0R(i,q){
		cin >> py1 >> px1 >> py2 >> px2;
		cout << trees[py2][px2] - trees[py2][px1-1] - trees[py1-1][px2] + trees[py1-1][px1-1]<< newl;

	}




    return 0;

}
