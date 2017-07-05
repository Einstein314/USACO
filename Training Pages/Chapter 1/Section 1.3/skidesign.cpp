///*
//ID: konwoo.1
//PROG: skidesign
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
//
//int main() {
//    ifstream fin("skidesign.in");
//    ofstream fout("skidesign.out");
//    int N = 0;
//    fin >> N;
//    vi k(N);
//    F0R(i, N) fin >> k[i];
//
//    int total = 0;
//    vi values;
//    sort(k.begin(), k.end());
//    int min = k[0];
//    int max = k[N-1];
//    if (max - min <= 17){
//        fout << total << "\n";
//    }
//    else{
//        F0R(i, 84){
//            int value = 0;
//            F0R(j, N){
//                if (k[j] < i){
//                    value += (k[j] - i) * (k[j] - i);
//                }
//                else if (k[j] > i + 17){
//                    value += (k[j] - i - 17) * (k[j] - i - 17);
//                }
//            }
//            values.pb(value);
//        }
//        sort(values.begin(), values.end());
//        fout << values[0] << "\n";
//    }
//    return 0;
//}
//
