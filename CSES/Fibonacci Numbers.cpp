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

const ll mod1 = 1e9  + 7 ;


struct matrix {
    vector<vector<ll>> cells;
    matrix(vector<vector<ll>> input) : cells(input) {}
    matrix(ll n, ll m, ll val) {
        cells.resize(n);
        vector<ll> row(m);
        fill(row.begin(), row.end(), val);
        fill(cells.begin(), cells.end(), row);
    }
    
    matrix(ll n) : matrix(n, n, 0) {
        for (ll i = 0; i < n; i++) {
            cells[i][i] = 1;
        }
    }
    
    matrix operator*(matrix b) {
        assert(cells[0].size() == b.cells.size());
        ll n = cells.size(), m = b.cells[0].size();
        matrix result(n, m, 0);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                for (ll k = 0; k < (ll) b.cells.size(); k++)
                    result.cells[i][j] += ((cells[i][k] * b.cells[k][j] + mod1) % mod1 + mod1);
                result.cells[i][j] %= mod1;
            }
        }
        return result;
    }
};


matrix matPow(matrix base, ll exp) {
    if (exp == 0)
        return matrix(base.cells.size());
    return matPow(base * base, exp / 2) * (exp % 2 == 1 ? base : matrix(base.cells.size()));
}

ll n;


int main(){
    // ios::sync_with_stdio(0);
   // cin.tie(0);

//	ifstream cin("/Users/konwoo/input.txt");
//	ofstream cout("/Users/konwoo/output.txt");

	cin >> n;
	if (n == 0) return cout << 0 << newl, 0;
	matrix mat({{1,1},{1,0}}); 
	mat = matPow(mat, n-1);
	cout << mat.cells[0][0] << newl;



    
    
    

    return 0;
}
