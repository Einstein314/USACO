///*
//ID: konwoo.1
//PROG: money
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
//long long d[10001];
//int V, N, t;
//
//
//int main() {
//    ifstream fin("money.in");
//    ofstream fout("money.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    fin >> V >> N;
//    d[0] = 1;
//    FOR(i, 1, V+1){
//        fin >> t;
//        FOR(j, t, N + 1){
//            d[j] += d[j-t];
//        }
//    }
//    fout << d[N] << "\n";
//
//    return 0;
//}