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

const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//const int MX = 100001;
//double PI = 4*atan(1);

// CHECK ARRAY BOUNDS, precision errors, check ll vs int
// CHECK DEFINE AND MACROS

//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

int N, a[105], dp[105][105][105];

int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
    //     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
    //     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);

    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    F0R(i, N) cin >> a[i+1];
    F0R(i, N){
        F0R(j, N){
            F0R(k, N){
                dp[i+1][j+1][k+1] = 500;
            }
        }
    }
    
    dp[1][1][1] = (a[1] == 0) ? 0 : 1;
    
    FOR(i, 1, N+1){
        FOR(j, i, N+1){
            FOR(k, i, j+1){
                if (i == 1 && k != 1){
                    FOR(l, 1, N+1){
                        dp[i][j][k] += (a[i] == i-1) ? 0 : 1;
                    }
                    continue;
                }
                if (j != k){
                    dp[i][j][k] = dp[i][j-1][k];
                }
                else{
                    FOR(l, i-1, j){
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][l]);
                    }
                }
                if (a[j] != j-k){
                    dp[i][j][k]++;
                }
            }
        }
    }
    
    
    FOR(i, 1, N+1){
        int amin = 1000;
        FOR(j, i, N+1){
            amin = min(amin, dp[i][N][j]);
//            cout << dp[i][N][j] << " ";
        }
//        debug("");
        debug(amin);
    }
    


    return 0;
}

