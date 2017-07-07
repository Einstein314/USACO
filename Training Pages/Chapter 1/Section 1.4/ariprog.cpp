///*
//ID: konwoo.1
//PROG: ariprog
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
//bool k[125001];
//
//
//int main() {
//    ifstream fin("ariprog.in");
//    ofstream fout("ariprog.out");
//    int N = 0;
//    int M = 0;
//    fin >> N >> M;
//    vi lol;
//    vector<pii> sol;
//    F0R(i, M+1){
//        FOR(j,i, M+1){
//                k[i*i + j*j] = 1;
//        }
//    }
//    F0R(i, 125001){
//        if (k[i]){
//            lol.pb(i);
//        }
//    }
//    F0R(i, lol.size()){
//        FOR(j, i+1, lol.size()){
//            if (lol[i] + (N-1)*(lol[j] - lol[i]) > 2*M*M) break;
//            bool test = 1;
//            F0R(m, N){
//                if (!k[lol[i] + m*(lol[j] - lol[i])]){
//                    test = 0;
//                    break;
//                }
//            }
//            if (test) sol.pb(mp(lol[j] - lol[i], lol[i]));
//        }
//    }
//    sort(sol.begin(), sol.end());
//    for (auto a: sol) fout << a.s << " " << a.f << "\n";
//    if (sol.size() == 0) fout << "NONE\n";
//    return 0;
//}
//
