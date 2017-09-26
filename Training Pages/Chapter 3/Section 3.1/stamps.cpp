///*
//ID: konwoo.1
//PROG: stamps
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
//    ifstream fin("stamps.in");
//    ofstream fout("stamps.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int K, N;
//    fin >> K >> N;
//    int s[N];
//    int max = -1;
//    F0R(i, N){
//        fin >> s[i];
//        if (s[i] > max) {max = s[i];}
//    }
//    int min[max * K + 2];
//    F0R(i, max*K+2){
//        min[i] = MOD;
//    }
//    min[0] = 0;
//    F0R(i, N){
//        min[s[i]] = 1;
//    }
//    FOR(i, 1, max * K + 2){
//        int tmin = MOD;
//        F0R(j, N){
//            if ((i - s[j]) >= 0 && min[i-s[j]] < tmin && min[i - s[j]] < K){
//                tmin = min[i - s[j]];
//            }
//        }
//        if (tmin != MOD) min[i] = tmin + 1;
//    }
//
//    int count = 0;
//    FOR(i, 1, max * K + 2){
//        if (min[i] == MOD) {
//            count = i;
//            break;
//        }
//    }
//    fout << count - 1 << "\n";
//    return 0;
//}