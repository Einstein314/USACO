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

int N, ans = 0, b1[3][100000];

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    fin >> N;
    F0R(i,N) {
        char c; fin >> c;
        if (i) {
            b1[0][i] = b1[0][i-1];
            b1[1][i] = b1[1][i-1];
            b1[2][i] = b1[2][i-1];
        }
        // H=0,P=1,S=2
        if (c == 'H') b1[1][i] ++;
        else if (c == 'P') b1[2][i] ++;
        else b1[0][i] ++;
    }
    F0R(i,N) {
        int z = max(max(b1[0][i],b1[1][i]),b1[2][i]);
        z += max(max(b1[0][N-1]-b1[0][i],b1[1][N-1]-b1[1][i]),b1[2][N-1]-b1[2][i]);
        ans = max(ans,z);
    }
    fout << ans;


    return 0;

}
