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

int N, Q, a[3][100001];


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    fin >> N >> Q;
    a[0][0] = 0;
    a[1][0] = 0;
    a[2][0] = 0;
    FOR(i, 1, N+1){
        int id;
        fin >> id;
        a[0][i] = a[0][i-1];
        a[1][i] = a[1][i-1];
        a[2][i] = a[2][i-1];
        a[id-1][i]++;
    }
    F0R(i, Q){
        int c, b;
        fin >> c >> b;
        fout << a[0][b] - a[0][c-1] << " " << a[1][b] - a[1][c-1] << " " << a[2][b] - a[2][c-1] << endl;
    }
    return 0;

}
