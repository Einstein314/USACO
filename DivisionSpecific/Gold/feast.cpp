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
#define debug(x) cout << x << " "

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
double PI = 4*atan(1);

const int MAX = 5000500;
int T, A, B, p[2][MAX];

int main(){
    // ifstream fin("/Users/konwoo/input.txt");
    // ofstream fout("/Users/konwoo/output.txt");
//     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
//     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> T >> A >> B;
    
    p[0][0] = 1;
    F0R(j, 2){
        F0R(i, T+1){
            if (!p[j][i]) continue;
            if (i + A <= T) p[j][i+A] = 1;
            if (i + B <= T) p[j][i+B] = 1;
            if (j == 0) p[j+1][i/2] = 1;
        }
    }
    int ans = T;
    while(ans--){
        if (p[0][ans + 1] || p[1][ans + 1]){ //you only need p[1][ans+1]
            break;
        }
    }
    cout << ans+1 << endl;
    
    
    
    return 0;
}

