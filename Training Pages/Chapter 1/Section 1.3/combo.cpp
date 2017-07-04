///*
//ID: konwoo.1
//PROG: combo
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
//int overlap(int x, int y, int n){
//    if (abs(x-y) == 0 % n){
//        return 5;
//    }
//    else if ((abs(x-y) == 1 % n) || abs(x-y) == n-1 % n){
//        return 4;
//    }
//    else if ((abs(x-y) == 2 % n) || abs(x-y) == n-2 % n){
//        return 3;
//    }
//    else if ((abs(x-y) == 3 % n) || abs(x-y) == n-3 % n){
//        return 2;
//    }
//    else if ((abs(x-y) == 4 % n) || abs(x-y) == n-4 % n){
//        return 1;
//    }
//    return 0;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    ifstream cin("combo.in");
//    ofstream cout("combo.out");
//    int N;
//    cin >> N;
//    tuple<int, int, int> k1;
//    tuple<int, int, int> k2;
//    cin >> get<0>(k1) >> get<1>(k1) >> get<2>(k1);
//    cin >> get<0>(k2) >> get<1>(k2) >> get<2>(k2);
//    if (N > 6){
//        cout << 250 - (overlap(get<0>(k1), get<0>(k2), N) * overlap(get<1>(k1), get<1>(k2), N) * overlap(get<2>(k1), get<2>(k2), N)) << "\n";
//    }
//    else{
//        cout << N*N*N << "\n";
//    }
//    return 0;
//}
//
