///*
//ID: konwoo.1
//PROG: milk
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
//int main() {
//    ifstream cin("milk.in");
//    ofstream cout("milk.out");
//
//    int N = 0;
//    int M = 0;
//    int money = 0;
//    cin >> N >> M;
//    vector<pii> k(M);
//    F0R(i, M) cin >> k[i].f >> k[i].s;
//    sort(k.begin(), k.end());
//    F0R(i, M){
//        while ((N != 0) && (k[i].s != 0)){
//            N -= 1;
//            k[i].s -= 1;
//            money += k[i].f;
//        }
//    }
//    cout << money << "\n";
//    return 0;
//}
//
