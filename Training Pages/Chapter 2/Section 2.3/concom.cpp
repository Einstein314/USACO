///*
//ID: konwoo.1
//PROG: concom
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
////#include "kimko_stdc++.h"
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> pii;
//
//#define FOR(i, a, b) for (int i=a; i<b; i++)
//#define F0R(i, a) for (int i=0; i<a; i++)
//#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
//#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
//
//#define mp make_pair
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
//
//const int MOD = 1000000007;
//double PI = 4*atan(1);
//
//int t[101][101], n, m = 0, c[101];
//bool con[101];
//
//
//
//void dfs(int x){
//    con[x] = true;
//    FOR(i, 1, n+1) c[i] += t[x][i];
//    FOR(i, 1, n+1){
//        if (c[i] >= 50 && !con[i]) {
//            dfs(i);
//        }
//    }
//}
//
//
//
//int main() {
//    ifstream fin("concom.in");
//    ofstream fout("concom.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    fin >> n;
//    memset(t, 0, sizeof(t));
//    FOR(i, 1, n + 1){
//        int a, b;
//        fin >> a >> b;
//        if (a > m) m = a;
//        if (b > m) m = b;
//        fin >> t[a][b];
//    }
//    n = m;
//    FOR(i, 1, n+1){
//        memset(con, false, sizeof(con));
//        memset(c, 0, sizeof(c));
//        dfs(i);
//        FOR(j, 1, n+1){
//            if (j != i && con[j]){
//                fout << i << " " << j << "\n";
//            }
//        }
//
//    }
//    return 0;
//}