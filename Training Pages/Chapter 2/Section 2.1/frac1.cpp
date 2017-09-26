///*
//ID: konwoo.1
//PROG: frac1
//LANG: C++11
//*/
//
//#include "kimko_stdc++.h"
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
//int n;
//int gcd ( int a, int b )
//{
//    int c;
//    while ( a != 0 ) {
//        c = a; a = b%a;  b = c;
//    }
//    return b;
//}
//
//vector<pair<double, int>> a;
//vector<pair<string, int>> b;
//int main() {
//    ifstream fin("frac1.txt");
//    ofstream fout("frac2.txt");
//    fin >> n;
//    int count = 0;
//    FOR(i, 1, n + 1) {
//        FOR(j, 1, i) {
//            if (gcd(i,j) == 1){
//                a.pb(make_pair(((double) j)*n/i, count));
//                string s = to_string(j) + "/" + to_string(i);
//                b.pb(make_pair(s, count));
//                count++;
//            }
//        }
//    }
//    sort(a.begin(), a.end());
//    fout << "0/1" << "\n";
//    for(size_t i = 0; i < a.size(); i++){
//        fout << b.at(a[i].s).f  << "\n";
//    }
//    fout << "1/1" << "\n";
//    return 0;
//}