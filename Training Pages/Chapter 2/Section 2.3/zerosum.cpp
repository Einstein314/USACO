///*
//ID: konwoo.1
//PROG: zerosum
//LANG: C++11
//*/
//
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
//int N;
//vector<string> sol;
//int nums[9] = {1,2,3,4,5,6,7,8,9};
//
//
//void dfs(int counter, int x, int sum, int sign, string seq){
//    if (counter == N){
//        if (sum + sign * x == 0){
//            sol.pb(seq);
//        }
//        return;
//    }
//    dfs(counter + 1, 10*x + nums[counter], sum, sign, seq + " " + char(nums[counter] + '0'));
//    dfs(counter + 1, nums[counter], sum + sign * x, 1, seq + "+" + char(nums[counter] + '0'));
//    dfs(counter + 1, nums[counter], sum + sign * x, -1, seq + "-" + char(nums[counter] + '0'));
//}
//
//
//
//
//
//
//int main() {
//    ifstream fin("zerosum.in");
//    ofstream fout("zerosum.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    fin >> N;
//    dfs(1, 1, 0, 1,(string) "1");
//    for(size_t i = 0; i < sol.size(); i++){
//        fout << sol[i] << "\n";
//    }
//    return 0;
//}