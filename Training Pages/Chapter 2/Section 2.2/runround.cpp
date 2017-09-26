///*
//ID: konwoo.1
//PROG: runround
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
//ll M, siz;
//string xdig;
//int freq[10], freqtest[10];
//
//bool runaround(ll x){
//    F0R(i, 10){
//        freq[i] = 0;
//        freqtest[i] = 0;
//    }
//    xdig = to_string(x);
//    siz = xdig.size();
//    F0R(i, siz){
//        freqtest[xdig[i] - '0']++;
//    }
//    F0R(i, 10){
//        if (freqtest[i] >= 2){
//            return false;
//        }
//    }
//    F0R(i, siz){
//        if ((xdig[i] - '0') == 0){
//            return false;
//        }
//    }
//    int d = xdig[(xdig[0] - '0') % siz] - '0';
//    F0R(i, siz){
//        freq[d]++;
//        d = xdig[(d + xdig.find(to_string(d))) % siz] - '0';
//    }
//    F0R(i, 10){
//        if (freq[i] != freqtest[i] || freq[i] >= 2){
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    ifstream fin("runround.in");
//    ofstream fout("runround.out");
//    fin >> M;
//    ll N = M + 1;
//    bool check = true;
//    while (check){
//        if (runaround(N)){
//            fout << N << "\n";
//            check = false;
//        }
//        N++;
//    }
//    return 0;
//}