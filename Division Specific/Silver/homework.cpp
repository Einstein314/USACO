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

int N, arr[100100], o[100100], tmin;

multiset<pair<double, int> > m;

double e = 1e-50;

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    fin >> N;

    arr[0] = 0, o[0] = 0;
    F0R(i, N){
        fin >> arr[i+1];
        o[i+1] = o[i];
        o[i+1] += arr[i+1];
    }

    tmin = min(arr[N-1], arr[N]);
    FORd(k, 1, N-1){
        double sum = o[N] - o[k] - tmin;
        double denom = N-k-1;
        m.insert(mp(sum/(denom), k));
        tmin = min(tmin, arr[k]);
    }
    
    multiset< pair<double, int> > ::iterator it = m.begin();
    multiset< pair<double, int> > ::reverse_iterator it2 = m.rbegin();

    double ans = ( *it2 ).f;
    while (it != m.end()){
        if (fabs((*it).f -ans) < e){
            fout << (*it).s << endl;
        }
        it++;
    }

    return 0;
}
