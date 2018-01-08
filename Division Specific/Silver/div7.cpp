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

int N, x, prefix[50500];

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    prefix[0] = 0;
    fin >> N;
    FOR(i, 1, N+1){
        fin >> x;
        int y = (prefix[i-1] + x) % 7;
        prefix[i] = y;
    }
    int ans = 0;
    F0R(r, 7){
        int a, b;
        FOR(i, 1, N+1){
            if (prefix[i] == r){
                a = i;
                break;
            }
        }
        FORd(j, 1, N+1){
            if (prefix[j] == r){
                b = j;
                break;
            }
        }
        ans = max(ans, b-a);
    }


    fout << ans;






    return 0;

}
