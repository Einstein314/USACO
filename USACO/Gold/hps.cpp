/*
 ID: konwoo.1
 LANG: C++
 TASK: nocows
 */


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
#define debug(x) cout << x << "\n"

//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//const int MX = 100001;
//double PI = 4*atan(1);

// CHECK ARRAY BOUNDS, precision errors, check ll vs int
// CHECK DEFINE AND MACROS

//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int MAX = 100500;
int N, K, c[MAX][3], dp[MAX][25][3];
char gest[MAX];

int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
    //     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
    //     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    
    FOR(i, 1, N+1){
        cin >> gest[i];
        F0R(j, 3){
            c[i][j] = c[i-1][j];
        }
        if(gest[i] == 'H') c[i][0]++;
        else if (gest[i] == 'P') c[i][1]++;
        else c[i][2]++;
        dp[i][0][0] = c[i][2];
        dp[i][0][1] = c[i][0];
        dp[i][0][2] = c[i][1];
    }
    FOR(i, 1, N+1){
        FOR(j, 1, K+1){
            F0R(l, 3){
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l] + c[i][(l- 1 + 3) % 3] - c[i-1][(l-1+3)%3]);
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][(l+1) % 3] + c[i][(l + 3) % 3] - c[i-1][(l+3)%3]);
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][(l+2) % 3] + c[i][(l+1 + 3) % 3] - c[i-1][(l+1+3)%3]);
            }
        }
    }
    
    cout << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << "\n";
    
    


    return 0;
}

