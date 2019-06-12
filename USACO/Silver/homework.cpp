//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;


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

int N, pre[100100];
double mvals[100100];
vi scores;



int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    fin >> N;
    int temp = 0;
    double maxval = -1.0;
    scores.resize(N);
    F0R(i, N){
        fin >> scores[i];
        temp += scores[i];
        pre[i] = temp;
    }
    int minim = min(scores[N-2], scores[N-1]);

    FORd(k, 1, N-1){
        double ans = (pre[N-1] - pre[k-1] - minim)/(N - k - 1.0);
        mvals[k-1] = ans;
        minim = min(minim, scores[k-1]);
        maxval = max(maxval, ans);
    }

    FOR(i, 1, N-1){
        if (mvals[i-1] == maxval){
            fout << i << "\n";
        }
    }


    return 0;
}





