///*
//ID: konwoo.1
//PROG: pprime
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
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
//int a,b;
//vi all[9];
//vi sol, primes;
//
//void genprimes(){
//    FOR(i, 2, 10001){
//        bool f = 1;
//        for (int j: primes){
//            if (i%j==0){
//                f = 0;
//                break;
//            }
//            if (j*j > i) break;
//        }
//        if (f) primes.pb(i);
//    }
//}
//
//bool isprime(int x){
//    for (int i: primes){
//        if (x % i == 0 && x != i) return false;
//        if (i*i > x) return true;
//    }
//    return true;
//}
//
//int main() {
//    ifstream fin("pprime.in");
//    ofstream fout("pprime.out");
//    fin >> a >> b;
//    int diga = 0;
//    int digb = 0;
//    int tempa = a;
//    int tempb = b;
//    while (tempa > 0){
//        tempa /= 10;
//        diga++;
//    }
//    while (tempb > 0){
//        tempb /= 10;
//        digb++;
//    }
//    genprimes();
//    all[1] = {5,7};
//    all[2] = {11};
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            all[3].pb(101*d1 + 10*d2);
//        }
//    }
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            all[4].pb(1001*d1 + 110*d2);
//        }
//    }
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            for (int d3 = 0; d3 <=9; d3++){
//                all[5].pb(10001*d1 + 1010*d2 + 100*d3);
//            }
//        }
//    }
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            for (int d3 = 0; d3 <=9; d3++){
//                all[6].pb(100001*d1 + 10010*d2 + 1100*d3);
//            }
//        }
//    }
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            for (int d3 = 0; d3 <=9; d3++){
//                for (int d4 = 0; d4 <= 9; d4++){
//                    all[7].pb(1000001*d1 + 100010*d2 + 10100*d3 + 1000*d4);
//                }
//            }
//        }
//    }
//
//    for (int d1 = 1; d1 <= 9; d1+=2){
//        for (int d2 = 0; d2 <= 9; d2++){
//            for (int d3 = 0; d3 <=9; d3++){
//                for (int d4 = 0; d4 <= 9; d4++){
//                    all[8].pb(10000001*d1 + 1000010*d2 + 100100*d3 + 11000*d4);
//                }
//            }
//        }
//    }
//    if (b == 100000000){
//        digb--;
//    }
//    FOR(i, diga, digb + 1){
//        F0R(j, all[i].size()){
//            if (isprime(all[i][j]) && (all[i][j] >= a) && (all[i][j] <= b)){
//                sol.pb(all[i][j]);
//            }
//        }
//    }
//    F0R(i, sol.size()){
//        fout << sol[i] << "\n";
//    }
//    return 0;
//}
//
