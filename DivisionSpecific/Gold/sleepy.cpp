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


//const int MOD = 1e9 + 7;
//const ll INF = 1e18;
//double PI = 4*atan(1);


//int gcd(int x, int y) {return !y ? x : gcd(y, x%y);}

const int MAXN = 1e5+100;
int N, arr[MAXN], len, btree[MAXN], ind[MAXN], btree2[MAXN], ind2[MAXN];

//return sum from [1, k]
int sum(int k){
    int temp = 0;
    while (k >= 1){
        temp += btree[k];
        k -= k&-k;
    }
    return temp;
}

//update arr[k] by x
void upd(int k, int x){
    while (k <= N){
        btree[k] += x;
        k += k&-k;
    }
}


//return sum from [1, k]
int sum2(int k){
    int temp = 0;
    while (k >= 1){
        temp += btree2[k];
        k -= k&-k;
    }
    return temp;
}

//update arr[k] by x
void upd2(int k, int x){
    while (k <= N){
        btree2[k] += x;
        k += k&-k;
    }
}


int main(){
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    F0R(i, N){
        cin >> arr[i];
    }
    F0Rd(i, N-1){
        if (arr[i] > arr[i+1]){
            len = i+1;
            break;
        }
    }
    F0R(i, len){
        upd(arr[i], 1);
        ind[arr[i]] = sum(arr[i]) - 1;
    }
    FOR(i, len, N){
        upd2(arr[i], 1);
    }
    F0R(i, len){
        upd2(arr[i], 1);
        ind2[arr[i]] = sum2(arr[i]) - 1;
        upd2(arr[i], -1);
    }
    
    pr(len);
    F0R(i, len-1){
        bug(len - i - 1 + ind[arr[i]] + ind2[arr[i]]);
    }
    cout << ind[arr[len-1]] + ind2[arr[len-1]];

    
    

    // DEBUGGING PROCEDURE
    // Make sure algorithm is right first
    // Check edge cases
    // Check precision errors, ll vs int
    // Check array bounds (be careful about assumptions)
    // Check every line of code carefully
    // Check variable names, overlap with macros
    
    return 0;
}


