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
//#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pr(x) cout << x << "\n"
#define bug(x) cout << x << " "
#define trav(a,x) for (auto& a : x)


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int MAXN = 1e5 + 100;
int N, D, A[2*MAXN], B[2*MAXN], dist[2*MAXN], que[2*MAXN], cur, len;


struct cmpa{
    bool operator()(const int a, const int b) const{
        return B[a] < B[b];
    }
};

struct cmpb{
    bool operator()(const int a, const int b) const{
        return A[a] < A[b];
    }
};

multiset<int, cmpa> sa;
multiset<int, cmpb> sb;

void input(){
    cin >> N >> D;
    F0R(i, 2*N){
        cin >> A[i] >> B[i];
        A[i] = -A[i];
        B[i] = -B[i];
        dist[i] = -1;
    }
    F0R(i, N){
        if (B[i] == 0){
            que[len++] = i;
            dist[i] = 1;
        }
        else{
            sa.insert(i);
        }
        if (A[i+N] == 0){
            que[len++] = i+N;
            dist[i+N] = 1;
        }
        else{
            sb.insert(i+N);
        }
    }
}

void solve(){
    multiset<int, cmpa>::iterator ita;
    multiset<int, cmpb>::iterator itb;
    
    while (cur < len){
        int i = que[cur];
        if (i < N){
            while(1){
                itb = sb.lb(i);
                if (itb == sb.end() || A[*itb] > A[i] + D){
                    break;
                }
                dist[*itb] = dist[i] + 1;
                que[len++] = *itb;
                sb.erase(itb);
            }
        }
        else{
            while(1){
                ita = sa.lb(i);
                if (ita == sa.end() || B[*ita] > B[i] + D){
                    break;
                }
                dist[*ita] = dist[i] + 1;
                que[len++] = *ita;
                sa.erase(ita);
            }
        }
        cur++;
    }
}

int main(){
    freopen("piepie.in","r",stdin);
    freopen("piepie.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();
    F0R(i, N){
        pr(dist[i]);
    }
    
    

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}




