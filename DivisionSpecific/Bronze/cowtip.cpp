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

int n, ans;
char arr[10][10];


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    fin >> n;
    F0R(i,n ){
        F0R(j, n){
            fin >> arr[i][j];
        }
    }

    F0R(i, n){
        F0R(j, n){
            cout << arr[i][j] << " " ;
        }
    }

    F0Rd(i, n){
        F0Rd(j, n){
            if (arr[i][j] == '1'){
                ans++;
                F0R(k, i+1){
                    F0R(l, j+1){
                        if (arr[k][l] == '0'){
                            arr[k][l] = '1';
                        }
                        else if (arr[k][l] == '1'){
                            arr[k][l] = '0';
                        }
                    }
                }
            }
        }
    }

    fout << ans;




    return 0;
}
