///*
//ID: konwoo.1
//PROG: heritage
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
//string post;
//
//void build(string pre,string in)
//{
//if(pre.size()==0) return;
//int pos = in.find(pre[0]);
//build(pre.substr(1,pos),in.substr(0,pos));
//build(pre.substr(pos+1),in.substr(pos+1));
//post += pre[0];
//}
//
//int main()
//{
//#ifndef LOCAL
//    ifstream cin("heritage.in");
//    ofstream cout("heritage.out");
//#endif
//    string pre,in;
//    cin >> in >> pre;
//    build(pre,in);
//    cout << post << endl;
//    return 0;
//}