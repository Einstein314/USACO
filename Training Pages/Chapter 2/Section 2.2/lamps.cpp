///*
//ID: konwoo.1
//PROG: lamps
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
//int N,C;
//int lamps[101], bools[9];
//
//int main() {
//    ifstream fin("lamps.in");
//    ofstream fout("lamps.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    fin >> N >> C;
//    while (true){
//        int d;
//        fin >> d;
//        if (d == - 1){
//            break;
//        }
//        else{
//            lamps[d] = 1;
//        }
//    }
//    while (true){
//        int d;
//        fin >> d;
//        if (d == - 1){
//            break;
//        }
//        else{
//            lamps[d] = 2;
//        }
//    }
//    F0R(i, 9){
//        bools[i] = 1;
//    }
//
//    string str[9];
//    string sstr[9];
//    int astr[9];
//    astr[1] = 1;
//    astr[2] = 2;
//    astr[3] = 1;
//    astr[4] = 1;
//    astr[5] = 2;
//    astr[6] = 1;
//    astr[7] = 2;
//    astr[8] = 0;
//    str[1] = "222222";
//    sstr[1] = "000000";
//    str[2] = "221112";
//    sstr[2] = "001110";
//    str[3] = "212121";
//    sstr[3] = "010101";
//    str[4] = "211211";
//    sstr[4] = "011011";
//    str[5] = "122122";
//    sstr[5] = "100100";
//    str[6] = "121212";
//    sstr[6] = "101010";
//    str[7] = "112221";
//    sstr[7] = "110001";
//    str[8] = "111111";
//    sstr[8] = "111111";
//
//    FOR(j, 1, 9){
//        FOR(i, 1, N+1){
//            if ((lamps[i] != 0 && lamps[i] != str[j][(i+5) % 6] - '0') || (C < astr[j])){
//                bools[j] = false;
//                break;
//            }
//        }
//        if (bools[j]){
//            for (int i = 1; i <= N - 5; i+= 6){
//                fout << sstr[j];
//            }
//            fout << sstr[j].substr(0, N % 6);
//            fout << "\n";
//        }
//    }
//
//    bool finalcheck = true;
//    FOR(i, 1, 9){
//        if (bools[i] == 1){
//            finalcheck= false;
//            break;
//        }
//    }
//    if (finalcheck){
//        fout << "IMPOSSIBLE" << "\n";
//    }
//    return 0;
//}