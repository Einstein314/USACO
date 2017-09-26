///*
//ID: konwoo.1
//PROG: comehome
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
//const int INF = 0xFFFFFF;
//
//int d[52][52];
//
//int cti(char a){
//    if ( a >= 'a' && a <= 'z'){
//        return a - 'a';
//    }
//    else{
//        return a - 'A' + 26;
//    }
//}
//
//char itc(int x){
//    if (x <= 25){
//        return char('a' + x);
//    }
//    else{
//        return char('A' + (x - 26));
//    }
//}
//
//int main() {
//    ifstream fin("comehome.in");
//    ofstream fout("comehome.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int p;
//    fin >> p;
//    F0R(i, 52){
//        F0R(j, 52){
//            d[i][j] = INF;
//        }
//    }
//    F0R(i, p){
//        char ft, sd;
//        int dis;
//        fin >> ft >> sd >> dis;
//        int fti = cti(ft);
//        int sdi = cti(sd);
//        if (dis < d[fti][sdi]){
//            d[fti][sdi] = dis;
//            d[sdi][fti] = dis;
//        }
//    }
//    F0R(i, 52){
//        d[i][i] = 0;
//    }
//    F0R(i, 52){
//        F0R(j, 52){
//            F0R(k, 52){
//                if (d[i][k] + d[j][k] < d[i][j]){
//                    d[i][j] = d[i][k] + d[j][k];
//                }
//            }
//        }
//    }
//    int ans = INF;
//    FOR(i, 26, 51){
//        if (d[i][51] < ans){
//            ans = d[i][51];
//        }
//    }
//    int farm = 0;
//    FOR(i, 26, 51){
//        if (d[i][51] == ans){
//            farm = i;
//            break;
//        }
//    }
//
//    fout << itc(farm) << " " << ans << "\n";
//    return 0;
//}