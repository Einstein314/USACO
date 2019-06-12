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


const int MOD = 1000000007;
double PI = 4*atan(1);


int c = 0, ans = 0, best[50000];
vi diamond;

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int N, K;

    fin >> N >> K;
    diamond.resize(N);
    F0R(i, N){
        fin >> diamond[i];
    }
    sort(diamond.begin(), diamond.end());
    F0Rd(i, N){
        if (i == N - 1){
            best[i] = i;
        }
        else{
            best[i] = best[i+1];
        }
        while (diamond[best[i]] - diamond[i] > K) best[i]--;
        if (i != N - 1){
            FORd(j, best[i] + 1, best[i+1] + 1){
                c = max(c, best[j] - j + 1);
            }
        }
        ans = max(ans, best[i] - i + 1 + c);
    }
    fout << ans;
}
