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

const int MAXN = 50500;
int N, tot, x, tr[2*MAXN];
pii a[MAXN];


int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tr[idx];
        idx -= (idx&-idx);
    }
    return sum;
}
void update (int idx, int val){
    while (idx <= 2*MAXN){
        tr[idx] += val;
        idx += (idx & -idx);
    }
}

//int N, dp[255][255], a[255], ans;

int main(){
//     ifstream fin("/Users/konwoo/input.txt");
//     ofstream fout("/Users/konwoo/output.txt");
//     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
//     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);

    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    F0R(i, 2*N){
        cin >> x;
        if (a[x].f == 0){
            a[x].f = i+1;
        }
        else{
            a[x].s = i+1;
        }
    }
    sort(a, a+N+1);
    FOR(i,1,N+1){
        int tmp = read(a[i].s) - read(a[i].f - 1);
        tot += tmp;
        update(a[i].s, 1);
    }
    cout << tot << "\n";
   
    return 0;
}

