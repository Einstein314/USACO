//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; --i)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; --i)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define EPS 1e-10


const int MOD = 1000000007 ;
double PI = 4*atan(1);

int N;
vector<pii> milk;


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    fin >> N;
    milk.resize(N);
    F0R(i, N){
        fin >> milk[i].s >> milk[i].f;
    }
    sort(milk.begin(), milk.end());

    int i1 = 0, i2 = N - 1, ans = 0;
    while (i1 < i2){
        ans = max(ans, milk[i1].f + milk[i2].f);
        int t = min(milk[i1].s, milk[i2].s);
        milk[i1].s -= t, milk[i2].s -=t;
        if (milk[i1].s == 0) i1++;
        if (milk[i2].s == 0) i2--;
    }
    if (i1 == i2 && milk[i1].s > 0){
        ans = max(ans, 2*milk[i1].f);
    }
    fout << ans;





    return 0;

}
