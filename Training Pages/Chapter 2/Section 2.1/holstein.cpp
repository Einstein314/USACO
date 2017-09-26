///*
//ID: konwoo.1
//PROG: holstein
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
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
//
//int A, B;
//int V[25];
//int C[15][25];
//vector<int> sol;
//vector<int> cur;
//int v[25];
//void go(int p) {
//    if (cur.size() >= sol.size()) {
//        return;
//    }
//    if (p == B) {
//        bool ok = true;
//        for (int i=0; i<A; ++i) {
//            if (v[i] < V[i]) {
//                ok = false;
//                break;
//            }
//        }
//        if (ok) {
//            if (cur.size()<sol.size() || cur<sol) {
//                sol = cur;
//            }
//        }
//        return;
//    }
//    for (int i=0; i<A; ++i) {
//        v[i] += C[p][i];
//    }
//    cur.push_back(p);
//    go(p+1);
//    cur.pop_back();
//    for (int i=0; i<A; ++i) {
//        v[i] -= C[p][i];
//    }
//    go(p+1);
//}
//int main() {
//    ifstream fin("holstein.in");
//    fin >> A;
//    for (int i=0; i<A; ++i) {
//        fin >> V[i];
//    }
//    fin >> B;
//    for (int i=0; i<B; ++i) {
//        for (int j=0; j<A; ++j) {
//            fin >> C[i][j];
//        }
//    }
//    fin.close();
//
//    sol.assign(B+1, 123456789);
//    go(0);
//
//    ofstream fout("holstein.out");
//    fout << sol.size();
//    for (int i=0; i<(int)sol.size(); ++i) {
//        fout << ' ' << sol[i] + 1;
//    }
//    fout << '\n';
//    fout.close();
//
//    return 0;
//}