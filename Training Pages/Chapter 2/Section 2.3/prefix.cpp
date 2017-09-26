///*
//ID: konwoo.1
//PROG: prefix
//LANG: C++11
//*/
//
////#include "bits/stdc++.h"
//#include "kimko_stdc++.h"
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
//int dp[200001];
//
//int main() {
////    ifstream fin("prefix.in");
////    ofstream fout("prefix.out");
//    ifstream fin("sort3.txt");
//    ofstream fout("sort4.txt");
//    vector<string> ps;
//    while (true){
//        string word;
//        fin >> word;
//        if (word == "."){
//            break;
//        }
//        ps.pb(word);
//    }
//    string seq;
//    while (fin.good()){
//        string l;
//        fin >> l;
//        seq += l;
//    }
//
//    int n = seq.size();
//    int sol = 0;
//
//    F0R(i, n+1){
//        for (string& pref : ps) {
//            int start = i - (int) pref.size();
//            if (start < 0) continue;
//            if (seq.substr(start, pref.size()) != pref) continue;
//            if (start > 0 && !dp[start]) continue;
//
//            dp[i] = 1;
//            sol = i;
//            break;
//        }
//    }
//
//    fout << sol << "\n";
//    return 0;
//}