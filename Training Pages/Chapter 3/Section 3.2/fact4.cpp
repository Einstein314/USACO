///*
//ID: konwoo.1
//PROG: fact4
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
//
//int dig[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
//
//int lastdig(int n){
//    if (n  < 10){
//        return dig[n];
//    }
//    if (((n/10) % 10) % 2 == 0){
//        return (6 * lastdig(n/5) * dig[n % 10]) % 10;
//    }
//    return (4 * lastdig(n/5) * dig[n % 10]) % 10;
//}
//
//
//int main() {
//    ifstream fin("fact4.in");
//    ofstream fout("fact4.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int N;
//    fin >> N;
//    fout << lastdig(N) << "\n";
//    return 0;
//}