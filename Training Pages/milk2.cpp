///*
//ID: konwoo.1
//PROG: milk2
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
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
//int main() {
//    ifstream fin ("milk2.in");
//    ofstream fout ("milk2.out");
//    int N = 0;
//    fin >> N;
//    vector<pii> k(N), k1;
//    F0R(i,N) fin >> k[i].f >> k[i].s;
//    sort(k.begin(),k.end());
//    F0R(i,N) {
//        pii x = k[i];
//        while (i<N-1 && k[i+1].f <= x.s) i++, x.s = max(x.s,k[i].s);
//        k1.pb(x);
//    }
//    int a1 = 0, a2 = 0;
//    F0R(i,k1.size()) a1 = max(a1,k1[i].s-k1[i].f);
//    F0R(i,k1.size()-1) a2 = max(a2,k1[i+1].f-k1[i].s);
//    fout << a1 << " " << a2 << "\n";
//}