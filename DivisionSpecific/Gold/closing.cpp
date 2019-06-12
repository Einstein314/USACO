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

int N, M, x,y,p;
set<int> vert;
vector<string> ans;
vi adj[200500], perm;
ll parent[200500], size[200500]; //where n is number of vertices, note change this to n+1 if your vertices are numbered 1 to n

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool same(int a, int b){
    return find_set(a) == find_set(b);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
    
}

int main(){
    //     ifstream fin("/Users/konwoo/input.txt");
    //     ofstream fout("/Users/konwoo/output.txt");
    //     freopen("/Users/konwoo/desktop/input.txt","r",stdin);
    //     freopen("/Users/konwoo/desktop/output.txt","w",stdout);
    
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);

    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    F0R(i, M){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    F0R(i, N){
        cin >> p;
        perm.pb(p);
        make_set(perm[i]);
    }
    reverse(all(perm));
    ans.pb("YES");
    vert.insert(perm[0]);
    
    FOR(i, 1, N){
        for (auto a : adj[perm[i]]){
            if (vert.find(a) != vert.end()){
                union_sets(a, perm[i]);
            }
        }
        vert.insert(perm[i]);
        if (size[find_set(perm[0])] == i+1){
            ans.pb("YES");
        }
        else{
            ans.pb("NO");
        }
    }
    reverse(all(ans));
    F0R(i, N){
        cout << ans[i] << "\n";
    }
  
    
    
    return 0;
}

