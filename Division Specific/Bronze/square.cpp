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

int coords[8];
int main(){
    int x, i;
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("square.in");
    ofstream fout("square.out");
    while (fin >> x){
        coords[i] = x;
        i++;
    }
    int hor = max(coords[6], coords[2]) - min(coords[0], coords[4]);
    int ver = max(coords[7], coords[3]) - min(coords[1], coords[5]);

    F0R(i, 11){
        if (i >= max(hor, ver)){
            int ans = i * i;
            fout << ans;
            break;
        }
    }

    return 0;
}
