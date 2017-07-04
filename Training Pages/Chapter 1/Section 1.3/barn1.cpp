///*
//ID: konwoo.1
//PROG: barn1
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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    ifstream cin("barn1.in");
//    ofstream cout("barn1.out");
//
//    int M,S,C,sum;
//    cin >> M >> S >> C;
//    vi k(C);
//    vi l(C-1);
//    if (M >= C){
//        cout << C << "\n";
//    }
//    else{
//        F0R(i, C){
//            cin >> k[i];
//        }
//        sort(k.begin(), k.end());
//        FOR(i, 1, C){
//            l[i-1] = k[i] - k[i-1]-1;
//        }
//        sum = k[C-1] - k[0] + 1;
//        sort(l.begin(), l.end());
//        FOR(i, C-M, C-1){
//            sum -= l[i];
//        }
//        cout << sum << "\n";
//    }
//    return 0;
//}
//
