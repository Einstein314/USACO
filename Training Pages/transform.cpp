///*
//ID: konwoo.1
//PROG: transform
//LANG: C++11
//*/
//
//#include "bits/stdc++.h";
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
//
//typedef vector<vector<char> > square;
//
//bool rotate90(const square &sq1, const square &sq2);
//bool rotate180(const square &sq1, const square &sq2);
//bool rotate270(const square &sq1, const square &sq2);
//bool reflect(const square &sq1, const square &sq2);
//bool combination(const square &sq1, const square &sq2);
//bool nochange(const square &sq1, const square &sq2);
//int determinetype(const square &sq1, const square &sq2);
//
//int main() {
//    ifstream fin("transform.in");
//    ofstream fout("transform.out");
//
//    int N;
//    fin >> N;
//
//    square sq1(N, vector<char>(N));
//    square sq2(N, vector<char>(N));
//
//    F0R(i, N){
//        F0R(j, N){
//            fin >> sq1[i][j];
//        }
//    }
//
//    F0R(i, N){
//        F0R(j, N){
//            fin >> sq2[i][j];
//        }
//    }
//
//    fout << determinetype(sq1, sq2) << "\n";
//    return 0;
//}
//
//int determinetype(const square &sq1, const square &sq2){
//    if (rotate90(sq1, sq2)){
//        return 1;
//    }
//    if (rotate180(sq1, sq2)){
//        return 2;
//    }
//    if (rotate270(sq1, sq2)){
//        return 3;
//    }
//    if (reflect(sq1, sq2)){
//        return 4;
//    }
//    if (combination(sq1, sq2)){
//        return 5;
//    }
//    if (nochange(sq1, sq2)){
//        return 6;
//    }
//    return 7;
//}
//
//bool rotate90(const square &sq1, const square &sq2){
//    int n = sq1.size();
//    F0R(i, n){
//        F0R(j, n){
//            if(sq1[i][j] != sq2[j][n-i-1]){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool rotate180(const square &sq1, const square &sq2){
//    int n = sq1.size();
//    F0R(i, n){
//        F0R(j, n){
//            if(sq1[i][j] != sq2[n-i-1][n-j-1]){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool rotate270(const square &sq1, const square &sq2){
//    int n = sq1.size();
//    F0R(i, n){
//        F0R(j, n){
//            if(sq1[i][j] != sq2[n-j-1][i]){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool reflect(const square &sq1, const square &sq2){
//    int n = sq1.size();
//    F0R(i, n){
//        F0R(j, n){
//            if(sq1[i][j] != sq2[i][n-j-1]){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool combination(const square &sq1, const square &sq2){
//    int n = sq1.size();
//    square temp(n, vector<char>(n));
//    F0R(i, n){
//        F0R(j, n){
//            temp[i][j] = sq1[i][n-j-1];
//        }
//    }
//    return rotate90(temp, sq2) || rotate180(temp, sq2) || rotate270(temp, sq2);
//}
//
//bool nochange(const square &sq1, const square &sq2){
//    return (sq1 == sq2);
//}