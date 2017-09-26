///*
//ID: konwoo.1
//PROG: nuggets
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
//int works[256];
//int main()
//{
//    ifstream fin("nuggets.in");
//    ofstream fout("nuggets.out");
//
//    int n;
//    fin >> n;
//    int nug[n];
//    F0R(i, n){
//        fin >> nug[i];
//    }
//    int t = nug[0];
//    if (t == 1){
//        fout << 0 << "\n";
//        return 0;
//    }
//    sort(nug, nug + sizeof(nug)/sizeof(t));
//    F0R(i, n){
//        t = gcd(t, nug[i]);
//    }
//    if (t != 1){
//        fout << 0 << "\n";
//        return 0;
//    }
//    works[0] = 1;
//    int pos = 0;
//    int lv = 0;
//    int last = 0;
//    while (pos < 2000000000){
//        if (pos - last > 256) break;
//        if (!works[lv]) last = pos;
//        else{
//            works[lv] = 0;
//            F0R(i, n){
//                works[(lv + nug[i]) % 256] = 1;
//            }
//        }
//        lv = (++pos) % 256;
//    }
//    if (pos >= 2000000000) last = 0;
//    fout << last << endl;
//    return 0;
//}