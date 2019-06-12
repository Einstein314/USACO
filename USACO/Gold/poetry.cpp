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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


#define FOR(i,a,b) for (int i =a; i<b;i++)
#define F0R(i,a) for (int i =0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1;i >=a;i--)
#define F0Rd(i,a) for (int i = (a)-1;i >=0; i--)
#define sz(x) (int)(x).size()
//#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pr(x) cout << x << "\n"
#define bug(x) cout << x << " "
#define trav(a,x) for (auto& a : x)


const ll MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}


const int MAXN = 5000+10;
int N, M, K, cl, dp[MAXN], word[MAXN], si, ci, arrci[MAXN];
ll ans;
char ch;
map<char, int> cmap;
vi mp[MAXN];
string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll bp(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while (b > 0){
        if (b & 1){
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){
    freopen("poetry.in","r",stdin);
    freopen("poetry.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    F0R(i, N){
        cin >> si >> ci;
        word[si]++;
        mp[ci].pb(si);
        cl = max(cl, ci);
    }
    F0R(i, M){
        cin >> ch;
        cmap[ch]++;
    }
    
//    FOR(i, 1, K+1) pr(word[i]);
//    FOR(i, 1, cl+1){
//        trav(a, mp[i]){
//            pr(a);
//        }
//    }
//    F0R(i, 26){
//        pr(cmap[alph[i]]);
//    }
    
    dp[0] = 1;
    FOR(w, 1, K+1){
        FOR(t, 1, w+1){
            ll temp = 0;
            F0R(j, word[t]){
                temp += dp[w-t];
                temp %= MOD;
            }
//            ll temp = word[t] * dp[w-t];
            temp %= MOD;
            dp[w] += temp;
            dp[w] %= MOD;
        }
    }
    
//    FOR(i, 1, K+1) pr(dp[i]);
    
    FOR(i, 1, cl+1){
        trav(a, mp[i]){
            arrci[i] += dp[K-a];
            arrci[i] %= MOD;
        }
    }
    
//    FOR(i, 1, cl+1){
//        pr(arrci[i]);
//    }
    
    ans = 1;
    //can cutdown runtime here
    F0R(i, 26){
        if (cmap[alph[i]]){
            ll ind = cmap[alph[i]];
            ll temp = 0;
            FOR(j, 1, cl+1){
                temp += bp(arrci[j], ind, MOD);
                temp %= MOD;
            }
            ans *= temp;
            ans %= MOD;
        }
    }
    pr(ans);
    
    

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


