///*
//ID: konwoo.1
//PROG: milk3
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
//int A,B,C;
//bool output[21];
//bool searched[21][21];
//
//
//void dfs(int a, int b, int c){
//    if (searched[a][b]) return;
//    searched[a][b]= 1;
//    if (a == 0) output[c] = 1;
//    if (c < C && b > 0) dfs(a,max(0,b+c-C),min(C,b+c));
//    if (a < A && b > 0) dfs(min(A,a+b),max(0,a+b-A),c);
//    if (b < B && a > 0) dfs(max(0,a+b-B),min(B,a+b),c);
//    if (c < C && a > 0) dfs(max(0,a+c-C),b,min(C,a+c));
//    if (a < A && c > 0) dfs(min(A,a+c),b,max(0,a+c-A));
//    if (b < B && c > 0) dfs(a,min(B,b+c),max(0,b+c-B));
//}
//
//
//int main() {
//    ifstream fin("milk3.in");
//    ofstream fout("milk3.out");
//    fin >> A >> B >> C;
//    dfs(0,0,C);
//    F0R(i, C) if (output[i]) fout << i << " ";
//    fout << C << "\n";
//    return 0;
//}
//
