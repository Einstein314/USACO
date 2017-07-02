///*
//ID: konwoo.1
//PROG: ride
//LANG: C++11
//*/
//#include "bits/stdc++.h"
//using namespace std;
//
//ifstream fin ("ride.in");
//ofstream fout ("ride.out");
//
//int score(string s){
//    int g = 1;
//    for(int i = 0; i < s.length(); i++){
//        g *= s[i] - 'A' + 1;
//    }
//    return g % 47;
//}
//
//int main() {
//    string group, comet;
//    fin >> group >> comet;
//    if (score(group) == score(comet)){
//        fout << "GO" << endl;
//    }
//    else{
//        fout << "STAY" << endl;
//    }
//
//    return 0;
//}