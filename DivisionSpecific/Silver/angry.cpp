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

int N;
ll K;
vi a;




int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> N >> K;
    a.resize(N);
    F0R(i, N){
        fin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int R = 0; R < N ; ++R) {
        int count = 0, index = 0;
        while (count < K && index < N) {
            int temp = a[index]+2*R;
            while (a[index] <= temp && index < N) index++;
            count++;
        }
        if (index == N) {
            fout << R;
            return 0;
        }
    }

}
