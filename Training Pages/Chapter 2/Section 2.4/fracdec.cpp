///*
//ID: konwoo.1
//PROG: fracdec
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
//const int INF = 0xFFFFFF;
//
//int ccount = 0;
//
//
//ofstream fout("fracdec.out");
////ofstream fout("sort4.txt");
//
//void print(char c){
//    if (ccount == 76){
//        fout << "\n";
//        ccount = 0;
//    }
//    fout << c;
//    ccount++;
//}
//
//int nums(int N, int D){
//    int c2 = 0, c5 = 0;
//    if (N == 0) {return 1;}
//    while (D % 2 == 0) {D/= 2; c2++;}
//    while (D % 5 == 0) {D/= 5; c5++;}
//    while (N % 2 == 0) {N/=2; c2--;}
//    while (N % 5 == 0) {N/=5; c5--;}
//    if (c2 > c5){
//        if (c2 > 0) return c2;
//        else{
//            return 0;
//        }
//    }
//    else{
//        if (c5 > 0) return c5;
//        else{
//            return 0;
//        }
//    }
//}
//
//void print(int n){
//    if (n >= 10) print (n/10);
//    print ((char) ('0' + (n % 10)));
//}
//
//int main() {
//    ifstream fin("fracdec.in");
////    ifstream fin("sort3.txt");
//    int n, d;
//    fin >> n >> d;
//    print(n/d);
//    n = n % d;
//    print ('.');
//    int x = nums(n, d);
//    F0R(i, x){
//        n *= 10;
//        print(n/d);
//        n %= d;
//    }
//    int r = n;
//    if (r != 0 ){
//        print ('(');
//        do{
//            n*= 10;
//            print (n/d);
//            n %= d;
//        } while (n != r);
//        print (')');
//    }
//    fout << "\n";
//
//    return 0;
//}