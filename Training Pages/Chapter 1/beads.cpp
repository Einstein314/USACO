///*
//ID: konwoo.1
//PROG: beads
//LANG: C++11
//*/
//#include "bits/stdc++.h"
//using namespace std;
//#define FOR(i, a, b) for (int i=a; i<b; i++)
//
//int main(){
//    ifstream fin ("beads.in");
//    ofstream fout ("beads.out");
//
//    //int N = 77;
//    int N = 0;
//    string necklace;
//    fin >> N >> necklace;
//
//    //string necklace = "rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr";
//
//    int answer = 0;
//    int rplus = 0;
//    int bplus = 0;
//    int rminus = 0;
//    int bminus = 0;
//    int j = 0;
//    int answers[N];
//
//
//    FOR(i, 0, N) {
//        rplus = 0;
//        bplus = 0;
//        rminus = 0;
//        bminus = 0;
//        j = i + 1;
//        while (('r' == necklace.at((j % N + N) % N) || (necklace.at((j % N + N) % N) == 'w')) && (necklace.at(((j-1) % N + N) % N) != 'b')) {
//            rplus++;
//            j = (j + 1) % N;
//            if (j == i) {
//                break;
//            }
//        }
//        j = i + 1;
//        while (('b' == necklace.at((j % N + N) % N) || (necklace.at((j % N + N) % N) == 'w')) && (necklace.at(((j-1) % N + N) % N) != 'r')) {
//            bplus++;
//            j = (j + 1) % N;
//            if (j == i) {
//                break;
//            }
//        }
//        j = i - 1;
//        while (('r' == necklace.at((j % N + N) % N) || (necklace.at((j % N + N) % N) == 'w'))) {
//            rminus++;
//            j = (j - 1 % N + N) % N;
//            if (j == i) {
//                break;
//            }
//        }
//        j = i - 1;
//        while (('b' == necklace.at((j % N + N) % N) || (necklace.at((j % N + N) % N) == 'w'))) {
//            bminus++;
//            j = (j - 1 % N + N) % N;
//            if (j == i) {
//                break;
//            }
//        }
//        answers[i] = max(rplus, bplus) + max(rminus, bminus) + 1;
//    }
//
//    int maxi = answers[0];
//    FOR(i, 1, N){
//        maxi = max(maxi, answers[i]);
//    }
//    if (maxi > N){
//        fout << N << "\n";
//    }
//    else{
//        fout << maxi << "\n";
//    }
//    return 0;
//}
//
//
