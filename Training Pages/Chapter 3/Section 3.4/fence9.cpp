///*
//ID: konwoo.1
//PROG: fence9
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
//#include <iostream>
//#include <fstream>
//#include <cmath>
//using namespace std;
//
//int x,y,p,t;
//int gcd(int a,int b)
//{
//    if(a==0) return b;
//    while(b!=0)
//    {
//        t = b;
//        b = a%b;
//        a = t;
//    }
//    return a;
//}
//
//int main()
//{
//#ifndef LOCAL
//    ifstream cin("fence9.in");
//    ofstream cout("fence9.out");
//#endif
//    cin >> x >> y >> p;
//    cout << p*y/2+1-(gcd(x,y)+gcd(abs(x-p),y)+p)/2 << endl;
//    return 0;
//}