///*
//ID: konwoo.1
//PROG: sort3
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
//int N, sum, one, two, unrest, sectres, dosun, undos;
//
//int main() {
//    ifstream fin("sort3.in");
//    ofstream fout("sort3.out");
//    fin >> N;
//    int j[N];
//    F0R(i, N){
//        fin >> j[i];
//    }
//    F0R(i, N){
//        if (j[i] == 1){
//            one++;
//        }
//        else if (j[i] == 2){
//            two++;
//        }
//    }
//    F0R(i, one){
//        if (j[i] != 1){
//            unrest++;
//        }
//        if (j[i] == 2){
//            undos++;
//        }
//    }
//    FOR(i, one, one + two){
//        if (j[i] == 3){
//            sectres++;
//        }
//        else if (j[i] == 1){
//            dosun++;
//        }
//    }
//    sum = unrest + sectres + max(dosun-undos, 0);
//    fout << sum << "\n";
//    return 0;
//}