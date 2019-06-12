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
#define bug(x) cout << x << " "


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int MX = 1050;
int H, G, hx[MX], hy[MX], gx[MX], gy[MX];
ll dp[MX][MX][2], ans;

int disthg(int a, int b){
    return pow(hx[a] - gx[b], 2) + pow(hy[a] - gy[b], 2);
}

int disth(int a, int b){
    return pow(hx[a] - hx[b], 2) + pow(hy[a] - hy[b], 2);
}

int distg(int a, int b){
    return pow(gx[a] - gx[b], 2) + pow(gy[a] - gy[b], 2);
}


int main(){
    //    ifstream fin("/Users/konwoo/input.txt");
    //    ofstream fout("/Users/konwoo/output.txt");
    //    freopen("/Users/konwoo/desktop/input","r",stdin);
    //    freopen("/Users/konwoo/desktop/output","w",stdout);
    
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    
    cin >> H >> G;
    FOR(i,1,H+1) cin >> hx[i] >> hy[i];
    FOR(i,1,G+1) cin >> gx[i] >> gy[i];
    
    dp[0][0][0] = 0;
    F0R(i,2){
        dp[1][0][i] = 0;
        dp[0][1][i] = 0;
    }
    dp[1][1][1] = disthg(1,1);
    FOR(h, 2, H+1){
        dp[h][0][0] = dp[h-1][0][0] + disth(h-1,h);
    }

    
    FOR(h, 1, H+1){
        FOR(g, 1, G+1){
            if (h == 1 && g == 1) continue;
            if (h == 1){
                dp[h][g][1] = dp[h][g-1][1] + distg(g-1,g);
            }
            if (g == 1){
                if (h == 2){
                    dp[h][g][0] = dp[h-1][g][1] + disthg(h,g);
                    dp[h][g][1] = dp[h][g-1][0] + disthg(h,g);
                }
                else{
                    dp[h][g][1]  = dp[h][g-1][0] + disthg(h,g);
                    dp[h][g][0] = min(dp[h-1][g][0] + disth(h-1, h), dp[h-1][g][1] + disthg(h,g));
                }
            }
            else if (h != 1 && g != 1){
                if (h == 2){
                    dp[h][g][0] = dp[h-1][g][1] + disthg(h,g);
                    dp[h][g][1] = min(dp[h][g-1][1] + distg(g-1,g), dp[h][g-1][0] + disthg(h,g));
                }
                else{
                    dp[h][g][0] = min(dp[h-1][g][0] + disth(h-1,h), dp[h-1][g][1] + disthg(h,g));
                    dp[h][g][1] = min(dp[h][g-1][1] + distg(g-1,g), dp[h][g-1][0] + disthg(h,g));
                }
            }
        }
    }
    cout << dp[H][G][0] << "\n";
    
    
    
    
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // Check array bounds (be careful about assummptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}

