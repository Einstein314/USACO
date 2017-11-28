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


int n, final[26];

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    fin >> n;
    F0R(i, n){
        string front, back;
        fin >> front >> back;
        int ftemp[26], btemp[26];
        F0R(j, 26){
            ftemp[j] = 0;
            btemp[j] = 0;
        }
        F0R(j, front.length()){
            ftemp[front[j] - '0' - 49]++;
        }
        F0R(j, back.length()){
            btemp[back[j] - '0' - 49]++;
        }

        F0R(j, 26){
            final[j] += max(ftemp[j], btemp[j]);
        }
    }

    F0R(i, 26){
        fout << final[i] << endl;
    }
    return 0;
}
