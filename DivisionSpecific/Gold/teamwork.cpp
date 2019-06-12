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

//int N, xl, yl, xb, yb, x, y;
//vii places;

const int MX = 10050;
int N, K, a[MX];
ll dp[MX];

const int k = 25;
int loga[MX];
int st[MX][k];

int query(int L, int R){
    int j = loga[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

int main(){
    //    ifstream fin("/Users/konwoo/input.txt");
    //    ofstream fout("/Users/konwoo/output.txt");
    //    freopen("/Users/konwoo/desktop/input","r",stdin);
    //    freopen("/Users/konwoo/desktop/output","w",stdout);
    
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    
    cin >> N >> K;
    F0R(i, N){
        cin >> a[i];
    }

    //sparse table initialization, implementation from cp-algorithms
    
    loga[1] = 0;
    for (int i = 2; i <= MX; i++)
        loga[i] = loga[i/2] + 1;
    
    for (int i = 0; i < N; i++)
        st[i][0] = a[i];
    
    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    
    dp[0] = a[0];
    FOR(i, 1, N){
        FOR(j, 1, min(K, i+1) + 1){
            dp[i] = max(dp[i], dp[i-j] + j*query(i - j + 1, i));
        }
    }
    d(dp[N-1]);
    
    
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // Check array bounds (be careful about assummptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}

