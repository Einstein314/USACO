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


multiset<int> chickens;
vector<pii> cows;
int C, N;



int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    fin >> C >> N;
    int x, y, total=0;
    for (int i=0; i<C; i++) { fin >> x; chickens.insert(x); }
    for (int i=0; i<N; i++) { fin >> x >> y; cows.push_back(pii(y,x)); }
    sort (cows.begin(), cows.end());
    for (int j=0; j<N; j++) {
        auto which_chicken = chickens.lower_bound(cows[j].second);
        if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
            total++;
            chickens.erase(which_chicken);
        }
    }
    fout << total << "\n";
    return 0;

}
