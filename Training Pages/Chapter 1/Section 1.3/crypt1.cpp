///*
//ID: konwoo.1
//PROG: crypt1
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
//bool contains(int a, vi l){
//    deque<int> digits;
//    while (a != 0){
//        div_t q = div(a,10);
//        digits.push_front(q.rem);
//        a = q.quot;
//    }
//    size_t sum = 0;
//    for(size_t i = 0; i < digits.size(); i++){
//        for(size_t j = 0; j < l.size(); j++){
//            if (digits[i] == l[j]){
//                sum++;
//            }
//        }
//    }
//    return (sum == digits.size());
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    ifstream cin("crypt1.in");
//    ofstream cout("crypt1.out");
//    int N;
//    cin >> N;
//    vi k(N);
//    F0R(i, N){
//        cin >> k[i];
//    }
//    int solutions = 0;
//    FOR(i, 100, 1000){
//        FOR(j, 10, 100){
//            if (contains(i, k) && contains(j, k) && contains((i * (j % 10)), k) && contains((i * (j - (j % 10))/10), k) && contains((i*j), k) && ((i * (j - (j % 10))/10) < 1000) && ((i * (j % 10)) < 1000)){
//                solutions++;
//            }
//        }
//    }
//    cout << solutions << "\n";
//    return 0;
//}
//
