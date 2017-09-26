///*
//ID: konwoo.1
//PROG: kimbits
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
//const int MAX_TABLE_N = 32;
//unsigned int C[MAX_TABLE_N + 1][MAX_TABLE_N + 1];
//
//inline void initTable()
//{
//    for(int i = 0; i <= MAX_TABLE_N; ++i) {
//        C[0][i] = 0;
//        C[i][0] = 1;
//    }
//    for(int i = 1; i <= MAX_TABLE_N; ++i)
//    {
//        for(int j = 1; j <= MAX_TABLE_N; ++j) {
//            C[i][j] = C[i-1][j] + C[i-1][j-1];
//        }
//    }
//}
//
//int main()
//{
//    ifstream fin("kimbits.in");
//    ofstream fout("kimbits.out");
//
//
//    initTable();
//
//    int n, l;
//    unsigned int p;
//
//    fin >> n >> l >> p;
//
//    for (int bit = 1; bit <= n; ++bit) {
//        unsigned int sum = 0;
//        for (int j = 0; j <= l; ++j) {
//            sum += C[n - bit][j];
//        }
//        if (p > sum) {
//            fout << 1;
//            l--;
//            p -= sum;
//        } else {
//            fout << 0;
//        }
//    }
//
//    fout << endl;
//
//    return 0;
//}