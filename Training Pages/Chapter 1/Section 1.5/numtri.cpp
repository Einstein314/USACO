///*
//ID: konwoo.1
//PROG: numtri
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
//int R;
//const int MAX = 1001;
//int arr[MAX][MAX];
//int dpcheck[MAX][MAX];
//
//int dp(int x, int y, int bound){
//    if (dpcheck[x][y] != -1){
//        return dpcheck[x][y];
//    }
//    else if (x < bound){
//        return dpcheck[x][y] = arr[x][y] + max(dp(x+1,y,bound), dp(x+1,y+1,bound));
//    }
//    else{
//        return 0;
//    }
//}
//
//int main() {
//    ifstream fin("numtri.in");
//    ofstream fout("numtri.out");
//    fin >> R;
//    FOR(i, 1, MAX){
//        FOR(j, 1, i+1){
//            fin >> arr[i][j];
//        }
//    }
//    memset(dpcheck, -1, sizeof dpcheck);
//    fout << dp(1,1,MAX) << "\n";
//    return 0;
//}
//
