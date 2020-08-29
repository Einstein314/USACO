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

const ll MOD = 998244353;
const ll INF = 1000000007;

const int MX = 8005;
int T, N;
double P, DP[MX][MX];

double c2(double num) {
    return num * (num - 1.0) / 2.0;
}

void solve(int t) {
    cin >> N >> P;
    F0R(i,N) F0R(j,N) DP[i][j] = 0.0;

    F0R(i,N) {
        F0R(j,N) {
            if (!i && !j) continue;

            double picked = (2.0 / (i + j + 1.0)), not_picked = 1.0 - picked;
            double e_picked = 0.0, e_not_picked = 0.0;
            if (i == 1 && !j) {
                e_picked += ((i * 1.0) / (i + j)) * (DP[i-1][j] * P);
            }
            else if (!i && j == 1) {
                e_picked += ((j * 1.0) / (i + j)) * (DP[i][j-1] * (1.0 - P));
            }
            else {
                double ifrac = c2(i) / c2(i + j), jfrac = c2(j)/ c2(i + j), rfrac = 1.0 - ifrac - jfrac;
                if (i) {
                    e_not_picked += (DP[i-1][j] * (ifrac + rfrac * P));
                    e_picked += ((i * 1.0) / (i + j)) * (DP[i-1][j] * P);
                }
                if (j) {
                    e_not_picked += (DP[i][j-1] * (jfrac + rfrac * (1.0 - P)));
                    e_picked += ((j * 1.0) / (i + j)) * (DP[i][j-1] * (1.0 - P));
                }
            }
            DP[i][j] = picked * e_picked + not_picked * e_not_picked + 1.0;
        }
    }

    printf("Case #%d:\n", t);
    F0R(i,N) {
        printf("%.10f\n", DP[i][N-1-i]);
    }
}

// check int vs ll and precision
// check logic
int main(){ FAST
    freopen ("/Users/konwoo/input.txt", "r", stdin);
    freopen ("/Users/konwoo/output.txt", "w", stdout);

    cin >> T;
    FOR(i,1,T+1) {
        solve(i);
    }

    
    
    return 0;
}


