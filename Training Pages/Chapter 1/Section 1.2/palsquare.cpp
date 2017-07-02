///*
//ID: konwoo.1
//PROG: palsquare
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
//string digits[20] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J"};
//
//deque<string> convertb(int num, int base){
//    deque<string> x;
//    div_t q = div(num, base);
//    while (!((q.quot == 0) && (q.rem == 0))){
//        x.push_front(digits[q.rem]);
//        q.rem = div(q.quot, base).rem;
//        q.quot = div(q.quot, base).quot;
//    }
//    return x;
//}
//
//bool testpal(deque<string> a){
//    if(a.size() == 1){
//        return true;
//    }
//    else {
//        for (size_t i = 0; i < a.size() / 2; i++) {
//            if (a[i] != a[a.size() - i - 1]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//string convertd(deque<string> a){
//    string s = "";
//    for(size_t i = 0; i <  a.size(); i++){
//        s += a[i];
//    }
//    return s;
//}
//
//int main() {
//    ifstream cin("palsquare.in");
//    ofstream cout("palsquare.out");
//
//    int n = 0;
//    cin >> n;
//
//    FOR(i, 1, 301){
//        if (testpal(convertb(pow(i,2), n))){
//            cout << convertd(convertb(i, n)) << " " << convertd(convertb(pow(i,2), n)) << "\n";
//        }
//    }
//    return 0;
//}
//
