///*
//ID: konwoo.1
//PROG: ratios
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
//int gcd(int a, int b)
//{
//    if (a == 0)
//        return b;
//    return gcd(b%a, a);
//}
//
//int findGCD(int arr[], int n)
//{
//    int result = arr[0];
//    for (int i=1; i<n; i++)
//        result = gcd(arr[i], result);
//
//    return result;
//}
//
//int main()
//{
//  ifstream fin("ratios.in");
//  ofstream fout("ratios.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int m[3][3], r[3];
//    F0R(i, 3){
//        fin >> r[i];
//    }
//    F0R(i, 3){
//        F0R(j, 3){
//            fin >> m[j][i];
//        }
//    }
//    int ar[4];
//    ar[0] = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
//    if (ar[0] == 0){
//        fout << "NONE\n";
//    }
//    else{
//        ar[1] = r[0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (r[1] * m[2][2] - m[1][2] * r[2]) + m[0][2] * (r[1] * m[2][1] - m[1][1] * r[2]);
//        ar[2] = m[0][0] * (r[1] * m[2][2] - m[1][2] * r[2]) - r[0] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * r[2] - r[1] * m[2][0]);
//        ar[3] = m[0][0] * (m[1][1] * r[2] - r[1] * m[2][1]) - m[0][1] * (m[1][0] * r[2] - r[1] * m[2][0]) + r[0] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
//        int d = findGCD(ar, 4);
//        bool check = true;
//        F0R(i, 4){
//            if (ar[i]/d < 0 || ar[i]/d > 100){
//                fout << "NONE\n";
//                check = false;
//                break;
//            }
//        }
//        if (check) fout << ar[1]/d << " " << ar[2]/d << " " << ar[3]/d << " " << ar[0]/d << "\n";
//    }
//    return 0;
//}
