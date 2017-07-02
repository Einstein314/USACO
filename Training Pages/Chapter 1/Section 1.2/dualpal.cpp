///*
//ID: konwoo.1
//PROG: dualpal
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
//string digits[20] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J"};
//
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
//int testpal(deque<string> a){
//    if(a.size() == 1){
//        return 1;
//    }
//    else {
//        for (size_t i = 0; i < a.size() / 2; i++) {
//            if (a[i] != a[a.size() - i - 1]) {
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
//
//int main() {
//    ifstream cin("dualpal.in");
//    ofstream cout("dualpal.out");
//
//    int n = 0;
//    int s = 0;
//    int counter = 0;
//    int vsum = 0;
//    cin >> n >> s;
//    vector<int> answers(n);
//    vector<int> test(9);
//
//    FOR(i, s+1, pow(2,31) - 1){
//        if (counter == n){
//            break;
//        }
//        test = {0,0,0,0,0,0,0,0,0};
//        FOR(j, 2, 11){
//            test[j-2] = testpal(convertb(i,j));
//        }
//        F0R(i, 9){
//            vsum += test[i];
//        }
//        if (vsum >= 2){
//            answers[counter] = i;
//            counter++;
//        }
//        vsum = 0;
//    }
//
//    F0R(i, n){
//        cout << answers[i] << "\n";
//    }
//    return 0;
//}
//
