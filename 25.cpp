#include "/Users/konwoo/stdc++.h"
//#include "bits/stdc++.h"

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

int arr[3][5];

bool norect(int a, int b, int c, int d, int e, int g, int u, int y){
    int ycoord = 6;
    F0R(i, 3){
        F0R(j, ycoord){
            arr[i][j] = 0;
        }
    }
    int h = (int) floor(a/ycoord);
    int o = (int) floor(b/ycoord);
    int p = (int) floor(c/ycoord);
    int q = (int) floor (d/ycoord);
    int r = (int) floor (e/ycoord);
    int t = (int) floor (g/ycoord);
    int v = (int) floor (u/ycoord);
    int z = (int) floor (y/ycoord);
    arr[h][a % ycoord] = 1;
    arr[o][b % ycoord] = 1;
    arr[p][c % ycoord] = 1;
    arr[q][d % ycoord] = 1;
    arr[r][e % ycoord] = 1;
    arr[t][g % ycoord] = 1;
    arr[v][u % ycoord] = 1;

    if (!(arr[0][0] && arr[0][1] && arr[1][0] && arr[1][1]) && !(arr[0][0] && arr[1][0] && arr[0][2] && arr[1][2]) &&
            !(arr[0][0] && arr[1][0] && arr[0][3] && arr[1][3]) && !(arr[0][1] && arr[1][1] && arr[0][2] && arr[1][2]) &&
            !(arr[0][1] && arr[1][1] && arr[0][3] && arr[1][3]) && !(arr[0][2] && arr[1][2] && arr[0][3] && arr[1][3]) &&
            !(arr[0][0] && arr[2][0] && arr[0][1] && arr[2][1]) && !(arr[0][0] && arr[2][0] && arr[0][2] && arr[2][2]) &&
            !(arr[0][0] && arr[2][0] && arr[0][3] && arr[2][3]) && !(arr[0][1] && arr[2][1] && arr[0][2] && arr[2][2]) &&
            !(arr[0][1] && arr[2][1] && arr[0][3] && arr[2][3]) && !(arr[0][2] && arr[2][2] && arr[0][3] && arr[2][3]) &&
            !(arr[1][0] && arr[2][0] && arr[1][1] && arr[2][1]) && !(arr[1][0] && arr[2][0] && arr[1][2] && arr[2][2]) &&
            !(arr[1][0] && arr[2][0] && arr[1][3] && arr[2][3]) && !(arr[1][1] && arr[2][1] && arr[1][2] && arr[2][2]) &&
            !(arr[1][1] && arr[2][1] && arr[1][3] && arr[2][3]) && !(arr[1][2] && arr[2][2] && arr[1][3] && arr[2][3]) &&
            !(arr[0][0] && arr[1][0] && arr[0][4] && arr[1][4]) && !(arr[0][1] && arr[1][1] && arr[0][4] && arr[1][4]) &&
            !(arr[0][2] && arr[1][2] && arr[0][4] && arr[1][4]) && !(arr[0][3] && arr[1][3] && arr[0][4] && arr[1][4]) &&
            !(arr[0][0] && arr[2][0] && arr[0][4] && arr[2][4]) && !(arr[0][1] && arr[2][1] && arr[0][4] && arr[2][4]) &&
            !(arr[0][2] && arr[2][2] && arr[0][4] && arr[2][4]) && !(arr[0][3] && arr[2][3] && arr[0][4] && arr[2][4]) &&
            !(arr[1][0] && arr[2][0] && arr[1][4] && arr[2][4]) && !(arr[1][1] && arr[2][1] && arr[1][4] && arr[2][4]) &&
            !(arr[1][2] && arr[2][2] && arr[1][4] && arr[2][4]) && !(arr[1][3] && arr[2][3] && arr[1][4] && arr[2][4]) &&
            !(arr[0][0] && arr[1][0] && arr[0][5] && arr[1][5]) && !(arr[0][1] && arr[1][1] && arr[0][5] && arr[1][5]) &&
            !(arr[0][2] && arr[1][2] && arr[0][5] && arr[1][5]) && !(arr[0][3] && arr[1][3] && arr[0][5] && arr[1][5]) &&
            !(arr[0][0] && arr[2][0] && arr[0][5] && arr[2][5]) && !(arr[0][1] && arr[2][1] && arr[0][5] && arr[2][5]) &&
            !(arr[0][2] && arr[2][2] && arr[0][5] && arr[2][5]) && !(arr[0][3] && arr[2][3] && arr[0][5] && arr[2][5]) &&
            !(arr[1][0] && arr[2][0] && arr[1][5] && arr[2][5]) && !(arr[1][1] && arr[2][1] && arr[1][5] && arr[2][5]) &&
            !(arr[1][2] && arr[2][2] && arr[1][5] && arr[2][5]) && !(arr[1][3] && arr[2][3] && arr[1][5] && arr[2][5]) &&
            !(arr[0][4] && arr[1][4] && arr[0][5] && arr[1][5]) && !(arr[0][4] && arr[2][4] && arr[0][5] && arr[2][5]) &&
            !(arr[1][4] && arr[2][4] && arr[1][5] && arr[2][5]) )
    {
            return true;
    }

    return false;

}




int main(){
    ifstream fin("/Users/konwoo/input.txt");
    ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("homework.in");
//    ofstream fout("homework.out");
    F0R(i, 3){
        F0R(j, 6){
            arr[i][j] = 0;
        }
    }
    int siz = 18;
    int count = 0;
    F0R(i, siz){
        FOR(j, i+1, siz){
            FOR(k, j+1, siz){
                FOR(l, k+1, siz){
                    FOR(m, l+1, siz){
                        FOR(n, m+1, siz){
                            FOR (w, n+1, siz){
                                FOR(ab, w+1, siz){
                                    if (norect(i, j, k, l, m, n, w, ab)){
                                        count++;
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }

    cout << count;






    return 0;
}





