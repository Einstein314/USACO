///*
//ID: konwoo.1
//PROG: game1
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
//int main()
//{
//    ifstream fin("game1.in");
//    ofstream fout("game1.out");
//
//    int num[200];
//    int dp[200];
//    int sum[200];
//    int n;
//    fin >> n;
//
//    for (int i = 0; i < n; ++i)
//    {
//        fin >> num[i];
//        dp[i] = num[i];
//        sum[i] = num[i];
//    }
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < n - i; ++j)
//        {
//            dp[j] = max<int>(sum[j] - dp[j] + num[j + i], sum[j + 1] - dp[j + 1] + num[j]);
//        }
//        for (int j = 0; j < n - i; ++j)
//        {
//            sum[j] += num[j + i];
//        }
//    }
//
//    fout << dp[0] << " " << sum[0] - dp[0] << endl;
//
//    return 0;
//}