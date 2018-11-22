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

const int MAXN = 100500;
ll trf[MAXN], trb[MAXN], A[MAXN], B[MAXN];
pii ans[MAXN];
int N, tot;

ll readf(int idx){
    ll sum = 0;
    while (idx > 0){
        sum += trf[idx];
        idx -= (idx&-idx);
    }
    return sum;
}
void updatef (int idx, ll val){
    while (idx <= MAXN){
        trf[idx] += val;
        idx += (idx & -idx);
    }
}

ll readb(int idx){
    ll sum = 0;
    while (idx > 0){
        sum += trb[idx];
        idx -= (idx&-idx);
    }
    return sum;
}
void updateb (int idx, ll val){
    while (idx <= MAXN){
        trb[idx] += val;
        idx += (idx & -idx);
    }
}


//int N, dp[255][255], a[255], ans;

int main(){
//     ifstream fin("/Users/konwoo/input.txt");
//     ofstream fout("/Users/konwoo/output.txt");
//     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
//     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);

    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    F0R(i,N){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B,B+N);
    F0R(i,N){
        int rank = int(lb(B,B+N,A[i]) - B);
        A[i] = rank + 1;
    }
    
    
    F0Rd(i, N){
        ll x = readf(A[i] - 1);
        ans[A[i]].f = N - 1 - i - x;
        updatef(A[i],1);
    }
    
    F0R(i,N){
        ll y = readb(A[i]-1);
        ans[A[i]].s = i - y;
        updateb(A[i],1);
    }
    
    F0R(i,N){
        if (max(ans[A[i]].f, ans[A[i]].s) > 2 * min(ans[A[i]].f, ans[A[i]].s)){
            tot++;
        }
    }
    
    cout << tot << "\n";     
    return 0;
}

