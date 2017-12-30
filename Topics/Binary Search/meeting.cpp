// #include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define EPS 1e-10


const int MOD = 1000000007;
double PI = 4*atan(1);

int n, x[66666], v[66666];





int main(){
    // ifstream fin("/Users/konwoo/input.txt");
    // ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("shuffle.in");
//    ofstream fout("shuffle.out");

    cin >> n;
    F0R(i, n) cin >> x[i];
    F0R(i, n) cin >> v[i];

    double lo = 0.0, hi = 1000000000.0, mid = 0.0, ans = 0.0;
    while (fabs(hi - lo) > EPS){
        mid = (lo + hi)/2.0;
        double L = -1e233, R = 1e233;
        FOR(i, 0, n){
            double z = x[i] - v[i] * mid, w = x[i] + v[i] * mid;
            L = max(L, z), R = min(R, w);
        }
        if (L <= R) hi = mid; else lo = mid;
    }

    printf("%.10lf\n", lo);

    return 0;
}
