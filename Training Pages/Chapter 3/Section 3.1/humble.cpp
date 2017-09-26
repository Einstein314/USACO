///*
//ID: konwoo.1
//PROG: humble
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
//    ifstream fin("humble.in");
//    ofstream fout("humble.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int K, N;
//    fin >> K >> N;
//    int p[K];
//    F0R(i, K){
//        fin >> p[i];
//    }
//    long hum[N+1];
//    int pind[K];
//    F0R(i, K){
//        pind[i] = 0;
//    }
//    hum[0] = 1;
//    int track, minp;
//    long min;
//
//
//    FOR(i, 1, N+1){
//        track = 0;
//        min = 0x7FFFFFFF;
//        minp = -1;
//        F0R(j, K){
//            FOR(k, pind[j], i){
//                if (hum[k]* (double) p[j] > hum[i - 1]){
//                    track = k;
//                    break;
//                }
//            }
//            pind[j] = track;
//            if (hum[track]* (double) p[j] < min) {
//                min = hum[track]*p[j];
//                minp = j;
//            }
//        }
//        hum[i] = min;
//        pind[minp]++;
//    }
//    fout << hum[N] << "\n";
//    return 0;
//}