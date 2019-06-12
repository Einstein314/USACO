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


int m,n,k;

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    fin >> m >> n >> k;
    F0R(i, m){
        string x;
        fin >> x;
        F0R(a, k){
            F0R(j, x.length()){
                F0R(l, k){
                    fout << x[j];
                }
            }
            fout << endl;
        }

    }


    return 0;
}
