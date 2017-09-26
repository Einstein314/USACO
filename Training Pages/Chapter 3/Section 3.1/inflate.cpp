///*
//ID: konwoo.1
//PROG: inflate
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
//int main() {
//    ifstream fin("inflate.in");
//    ofstream fout("inflate.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int M, N;
//    fin >> M >> N;
//    int best[M+1];
//    F0R(i, M+1){
//        best[i] = 0;
//    }
//    F0R(i, N){
//        int points, mins;
//        fin >> points >> mins;
//        FOR(j, mins, M+1){
//            if (best[j - mins] + points > best[j]){
//                best[j] = best[j - mins] + points;
//            }
//        }
//    }
//    fout << best[M] << "\n";
//    return 0;
//}