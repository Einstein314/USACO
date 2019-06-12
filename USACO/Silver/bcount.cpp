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

int N, Q, k, a, b, breed[4][100100];

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    fin >> N >> Q;
    FOR(i, 1, N+1){
        fin >> k;
        if (i != 1){
            FOR(j, 1, 4){
                breed[j][i] = breed[j][i-1];
            }
        }
        breed[k][i]++;
    }
    F0R(i, Q){
        fin >> a >> b;
        FOR(j, 1, 3){
            fout << breed[j][b] - breed[j][a-1] << " ";
        }
        fout << breed[3][b] - breed[3][a-1] << endl;
    }




    return 0;

}
