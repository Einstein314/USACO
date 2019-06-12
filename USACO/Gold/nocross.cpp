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
int N, lord[MX], rord[MX], dp[MX][MX];

bool fri(int k, int l){
    return abs(lord[k] - rord[l]) <= 4;
}

int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
//         freopen("/Users/konwoo/desktop/input","r",stdin);
//         freopen("/Users/konwoo/desktop/output","w",stdout);
    
        freopen("nocross.in","r",stdin);
        freopen("nocross.out","w",stdout);
    
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    F0R(i,N) cin >> lord[i+1];
    F0R(i,N) cin >> rord[i+1];
    FOR(i,1,N+1){
        FOR(j,1,N+1){
            if (fri(i,j)) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    d(dp[N][N]);
    
    
//    FOR(i,1,N+1){
//        FOR(j,1,i+1){
//            bug(dp[i][j]);
//        }
//        d(".");
//    }
    
    // READ THIS
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // CHECK EVERY LINE OF CODE
    // CHECK DEFINE AND MACROS
    
    return 0;
}

