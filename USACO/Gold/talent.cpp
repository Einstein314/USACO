#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;


#define FOR(i,a,b) for (int i =a; i<b;i++)
#define F0R(i,a) for (int i =0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1;i >=a;i--)
#define F0Rd(i,a) for (int i = (a)-1;i >=0; i--)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pr(x) cout << x << "\n"
#define bug(x) cout << x << " "
#define trav(a,x) for (auto& a : x)


const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}


const int MAXN = 1e3+696; //any constant that's big enough works
int N, W, dp[MAXN], w, t;
double ans = 0;

int main(){
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> W;
    FOR(i, 1, MAXN) dp[i] = -MOD;
    F0R(i, N){
        cin >> w >> t;
        F0Rd(j, MAXN-w){
            if (dp[j] != -MOD){
                dp[j+w] = max(dp[j+w], dp[j] + t);
            }
        }
    }
    FOR(i, W, MAXN) ans = max(ans, (double) dp[i]/i);
    pr((int) floor(1000*ans));
    
//    memset(dp, 0, sizeof(dp));
//    int N = 10;
//    int W = 50;
//    int w[12] = {0, 12, 15, 16, 16, 10, 21, 18, 12, 17, 18};
//    int v[12] = {0,3,8,9,6,2,9,4,4,8,9};
//    FOR(i, 1, N+1){
//        FORd(j, w[i], W+1){
//            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
//            bug(dp[j]);
//        }
//        cout << "\n";
//    }
//    pr(dp[W]);
//    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


