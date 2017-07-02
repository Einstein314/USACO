///*
//ID: konwoo.1
//PROG: gift1
//LANG: C++11
//*/
//#include "bits/stdc++.h"
//using namespace std;
//
//ifstream fin ("gift1.in");
//ofstream fout ("gift1.out");
//
//int main(){
//    map<string, int> weird;
//    vector<string> names;
//    int NP;
//    fin >> NP;
//
//    for (int i = 0; i < NP; i++){
//        string a;
//        fin >> a;
//        weird[a] = 0;
//        names.push_back(a);
//    }
//
//    for (int i = 0; i < NP; i++){
//        string a;
//        int b,c,remainder;
//        fin >> a >> b >>c;
//
//        if(c > 0){
//            weird[a] -= (b - (b % c));
//            for (int j = 0; j < c; j++){
//                string d;
//                fin >> d;
//                weird[d] += b/c;
//            }
//        }
//
//        else{
//            weird[a] += b;
//        }
//    }
//
//    for (int i = 0; i < NP; i++){
//        fout << names[i] << " " << weird[names[i]] << "\n";
//    }
//
//    return 0;
//}
//
//
//
