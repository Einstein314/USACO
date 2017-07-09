///*
//ID: konwoo.1
//PROG: sprime
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
//vi sol[9];
//
//bool isprime(int x){
//    int i;
//    if (x == 0 || x == 1) return false;
//    if (x == 2) return true;
//    if (x % 2 == 0) return false;
//    for(i = 3; i*i <= x; i+=2){
//        if (x % i == 0){
//            return 0;
//        }
//    }
//    return true;
//}
//
//int main() {
//    ifstream fin("sprime.in");
//    ofstream fout("sprime.out");
//    int N;
//    fin >> N;
//    vi digits(4);
//    digits = {1,3,7,9};
//    sol[1] = {2,3,5,7};
//    FOR(i, 2, N+1){
//        F0R(j, sol[i-1].size()){
//            F0R(k, digits.size()){
//                if (isprime(10*sol[i-1][j] + digits[k])){
//                    sol[i].pb(10*sol[i-1][j] + digits[k]);
//                }
//            }
//        }
//    }
//    F0R(i, sol[N].size()){
//        fout << sol[N][i] << "\n";
//    }
//    return 0;
//}
//
