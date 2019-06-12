//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int N;
map<pair<string,string>,int> times;


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    fin >> N;
    F0R(i, N){
        string a, b; fin >> a >> b;
        a = a.substr(0,2);
        if (a != b) times[{a,b}]++;
    }
    ll ans = 0;
    for (auto a : times) ans += a.s*times[{a.f.s, a.f.f}];
    fout << ans/2;

    return 0;
}
