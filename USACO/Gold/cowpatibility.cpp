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
#define trav(a,x) for (auto& a : x)


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

int hash_f(int key){
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    return key;
}

int hash_combine(int a, int b) {return a * 31  + b;}

struct chash{
    int operator()(vi x) const{
        int cur = 1;
        trav(i, x){
            cur = hash_combine(cur, hash_f(i));
        }
        return cur;
    }
};
gp_hash_table< vi, int, chash> g;


const ll MAXN = 5e4+5;
int N, temp;
ll ans, cows[MAXN][5];

int main(){
    //    ifstream fin("/Users/konwoo/input.txt");
    //    ofstream fout("/Users/konwoo/output.txt");
    //    freopen("/Users/konwoo/desktop/input","r",stdin);
    //    freopen("/Users/konwoo/desktop/output","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen("cowpatibility.in","r",stdin);
//    freopen("cowpatibility.out","w",stdout);
    
    cin >> N;
    F0R(i, N){
        F0R(j, 5){
            cin >> cows[i][j];
        }
        sort(begin(cows[i]), end(cows[i]));
    }
    F0R(i, N){
        FOR(j, 1, (1<<5)){
            vi p;
            F0R(k, 5){
                if ((j >> k) & 1){
                    p.pb(cows[i][k]);
                }
            }
            if (p.size() % 2) ans += g[p];
            else ans -= g[p];
        }
        FOR(j, 1, (1<<5)){
            vi p;
            F0R(k, 5){
                if ((j >> k) & 1){
                    p.pb(cows[i][k]);
                }
            }
            g[p]++;
        }
    }
    cout << 1LL * N * (N-1) /2 - ans  << "\n";
    
    
    
    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // CHECK ARRAY BOUNDS, precision errors, check ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}




