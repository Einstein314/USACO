///*
//ID: konwoo.1
//PROG: nocows
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
//const int prime = 9901;
//
//int main() {
//    int N, K, dp[201][101];
//    ifstream fin("nocows.in");
//    ofstream fout("nocows.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    fin >> N >> K;
//    for (int i = 2; i <= N; ++i) {
//        for (int j = 0; j <= K; ++j) {
//            dp[i][j] = 0;
//        }
//    }
//    for (int j = 1; j <= K; ++j){
//        dp[1][j] = 1;
//    }
//
//    for (int i = 3; i < N + 1; i+=2){
//        for (int j = 1; j < K+1; ++j){
//            for (int l = 1; l <= i - 2; l += 2){
//                dp[i][j] += dp[l][j-1] * dp[i - l - 1][j-1];
//                dp[i][j] %= prime;
//            }
//        }
//    }
//
//    fout << (dp[N][K] - dp[N][K-1] + prime) % prime << "\n";
//
//}