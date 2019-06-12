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

int n;

int m = -100;
int arr[101][2];

int ans[6];
int p[6][3] = {
        {1,2,3},
        {1,3,2},
        {2,1,3},
        {2,3,1},
        {3,1,2},
        {3,2,1},
};



int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    fin >> n;
    F0R(i, n){
        fin >> arr[i][0] >> arr[i][1];
    }


    F0R(i, 6){
        F0R(j, n){
            if ((arr[j][0] ==  p[i][1] && arr[j][1] == p[i][0]) || (arr[j][0] ==  p[i][2] && arr[j][1] == p[i][1]) || (arr[j][0] ==  p[i][0] && arr[j][1] == p[i][2])){
                ans[i]++;
            }
        }
    }

    F0R(i, 6){
        if (ans[i] > m){
            m = ans[i];
        }
    }

    fout << m;





    return 0;
}
