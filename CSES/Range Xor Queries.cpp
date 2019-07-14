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
#define trav(a,b) for (auto a : b)
 
const int MX = 2e5 + 5;
//check this!!
//const int MOD = 1e9 + 7;
const ll MOD = 998244353;
template <class T, int SZ> struct Seg{
    T seg[2*SZ], ID = 0;
    Seg() {memset(seg, 0, sizeof(seg));}
    T comb(T a, T b) {return a^b;}
    void build(){
        F0Rd(i, SZ) seg[i] = comb(seg[i<<1], seg[(i<<1)|1]);
    }
    void upd(int p, T value){
        for (seg[p += SZ] = value; p > 1; p>>=1){
            seg[p>>1] = comb(seg[p], seg[p^1]);
        }
    }
    T query(int l, int r){
        //[l,r]
        T resl = ID, resr = ID; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1){
            if (l & 1) resl = comb(resl, seg[l++]);
            if (r & 1) resr = comb(seg[--r], resr);
        }
        return comb(resl, resr);
    }
};
//Remember to check int vs ll!!
int n, q, a, b, x, fl;
Seg<int, MX> segt;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
//    ifstream cin("/Users/konwoo/input.txt");
//    ofstream cout("/Users/konwoo/output.txt");
    cin >> n >> q;
    F0R(i,n){
        cin >> x;
        segt.upd(i, x);
    }
    F0R(i,q){
        cin >>  a >> b;
        cout << segt.query(a-1, b-1) << newl;
    }
    return 0;
}