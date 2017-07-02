//ID: konwoo.1
//PROG: friday
//LANG: C++11
//
//
//#include "bits/bitsstdc++.h"
//using namespace std;
//
//ifstream fin ("friday.in");
//ofstream fout ("friday.out");
//
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int fdays[7] = {0, 0, 0, 0, 0, 0, 0};
//
//bool leapyear(int x){
//    return ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)));
//}
//
//int main(){
//    int N;
//    fin >> N;
//    int year = 1900;
//    int day = 2;
//
//    for (int i = 1900; i < 1900 + N; i++){
//        for (int m = 0; m < 12; m++){
//            int daysInMonth = days[m];
//            if (m == 1 && leapyear(i)) daysInMonth++;
//            for (int d = 1; d <= daysInMonth; d++){
//                if (d == 13) fdays[day]++;
//                day = (day + 1) % 7;
//            }
//        }
//    }
//
//    for(int i = 0; i < 7; i++){
//        fout << (i ? " " : "") << fdays[i];
//    }
//    fout << endl;
//    return 0;
//}
//
//
//
