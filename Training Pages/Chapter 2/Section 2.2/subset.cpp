///*
//ID: konwoo.1
//PROG: subset
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
//
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
//int N;
//const int MAX = 1600;
//ll ways[MAX];
//
//
//
//int main() {
//    ifstream fin("subset.in");
//    ofstream fout("subset.out");
//    fin >> N;
//    int sum = N*(N+1)/2;
//    ways[0] = 1;
//
//    if (sum % 2 == 1){
//        fout << 0 << "\n";
//        return 0;
//    }
//
//    else {
//        FOR(i, 1, N + 1) {
//            FORd(j, 0, sum - i + 1){
//                ways[j+i] += ways[j];
//            }
//        }
//        fout << ways[sum/2]/2 << "\n";
//    }
//    return 0;
//}