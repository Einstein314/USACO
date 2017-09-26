///*
//ID: konwoo.1
//PROG: hamming
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
//int N, B, D;
//
//bool indistance(int x, int y){
//    int c = x ^ y;
//    int count = 0;
//    while (c > 0){
//        if ((c & 1) == 1){
//            count++;
//        }
//        c = c >> 1;
//    }
//    return (count >= D);
//}
//
//int main() {
//    ifstream fin("hamming.in");
//    ofstream fout("hamming.out");
//    fin >> N >> B >> D;
//
//    vi sol;
//    sol.pb(0);
//    int last = 0;
//
//
//    FOR(i, last + 1, pow(2,B)){
//        bool check = false;
//        for (int j : sol){
//            if (!indistance(j, i)){
//                check = true;
//                break;
//            }
//        }
//        if (!check){
//            sol.pb(i);
//            last = i;
//        }
//        if (sol.size() == N ){
//            break;
//        }
//    }
//
//    F0R(i, N){
//        fout << sol[i];
//        if ((i+1) % 10 == 0){
//            fout << "\n";
//        }
//        else{
//            if (i == N - 1){
//                fout << "\n";
//            }
//            else{
//                fout << " ";
//            }
//        }
//    }
//    return 0;
//}