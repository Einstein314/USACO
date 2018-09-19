#include "/Users/konwoo/stdc++.h"
//#include "bits/stdc++.h"

#include <unordered_set>
#include <set>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//        tree_order_statistics_node_update> indexed_set;




typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;


#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define lb lower_bound
#define ub upper_bound

//const int MOD = 1000000009;
//double PI = 4*atan(1);

const int N = 200 * 1000 + 13;

int n;
long long T;
int a[N];
int f[N];


void upd(int x){
    x++;
    while (x <= N){
        f[x]++;
        x += (x & -x);
    }
}

int get(int x){
    x++;
    int res = 0;
    while (x > 0){
        res += f[x];
        x -= (x & -x);
    }
    return res;
}

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("multimoo.in");
//    ofstream fout("multimoo.out");
//    freopen("milkorder.in","r",stdin);
//    freopen("milkorder.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> T;
    F0R(i, n){
        cin >> a[i];
    }

    vector<long long> sums(1, 0ll);
    long long pr = 0;

    F0R(i, n){
        pr += a[i];
        sums.pb(pr);
    }
    sort(sums.begin(), sums.end());
    sums.resize(unique(sums.begin(), sums.end()) - sums.begin());

    long long ans = 0;
    pr = 0;
    upd(lower_bound(sums.begin(), sums.end(), 0ll) - sums.begin());

    F0R(i, n){
        pr += a[i];
        int pos = upper_bound(sums.begin(), sums.end(), pr - T) - sums.begin();
        ans += (i + 1 - get(pos - 1));
        int k = lower_bound(sums.begin(), sums.end(), pr) - sums.begin();
        upd(k);
    }


    cout << ans;

    return 0;

}










