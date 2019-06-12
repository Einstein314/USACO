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
#define d(x) cout << x << "\n"

//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

int N, a[300], dp[300][300], ans;


int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
//         freopen("/Users/konwoo/desktop/input","r",stdin);
//         freopen("/Users/konwoo/desktop/output","w",stdout);
    
        freopen("248.in","r",stdin);
        freopen("248.out","w",stdout);
    
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    F0R(i,N) cin >> a[i+1];
    FOR(i,1,N+1) dp[i][1] = a[i];
    FOR(j, 2, N+1){
        FOR(i, 1, N-j+2){
            FOR(k, 1, j){
                if (dp[i][k] == dp[i+k][j-k]){
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }
    d(ans);

    // READ THIS 
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // CHECK DEFINE AND MACROS
    
    return 0;
}

