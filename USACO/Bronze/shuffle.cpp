
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

//int b1[4], b2[4], truck[4];
//
//int area(int a[4]){
//    return abs((a[2] - a[0]) * (a[3]-a[1]));
//}

int N, trans[105], id[105], ori[105], ori1[105], ori2[105];
vector<int> v;

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    fin >> N;
    int a;
    while (fin >> a){
        v.pb(a);
    }
    F0R(i, N){
        trans[i] = v[i];
        id[i] = v[i+N];
        ori[i] = v[i];
    }

    F0R(j, N){
        ori1[j] = ori[trans[j] - 1];
    }
    F0R(j, N){
        ori2[j] = ori1[trans[j] - 1];
    }
    F0R(i, N){
        fout << id[ori2[i] -1] << endl;
    }

    return 0;
}
