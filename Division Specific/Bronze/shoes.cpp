//#include "bits/stdc++.h"
////#include "kimko_stdc++.h"
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
//int n;
//int r[1001], l[1001];
//
//int main()
//{
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    cin >> n;
//    F0R(i, n){
//        int siz;
//        string fit;
//        cin >> siz >> fit;
//        if (fit == "R"){
//            r[siz]++;
//        }
//        else{
//            l[siz]++;
//        }
//    }
//    int sum = 0;
//    FOR(i, 1, 1001){
//        sum += min(r[i], l[i]);
//    }
//    cout << sum;
//
//    return 0;
//}