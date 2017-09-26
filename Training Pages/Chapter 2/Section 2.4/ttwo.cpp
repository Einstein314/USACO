///*
//ID: konwoo.1
//PROG: ttwo
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
//char m[12][12];
//int cx, cy, fx, fy, mins, dirc, dirf, diry[4] = {0, 1, 0, -1}, dirx[4] = {-1, 0, 1, 0};
//
//int main() {
//    ifstream fin("ttwo.in");
//    ofstream fout("ttwo.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    F0R(i, 12){
//        m[0][i] = '*';
//        m[i][0] = '*';
//        m[11][i] = '*';
//        m[i][11] = '*';
//    }
//    FOR(i, 1, 11){
//        FOR(j, 1, 11){
//            fin >> m[i][j];
//            if (m[i][j] == 'C'){
//                cx = i;
//                cy = j;
//                m[i][j] = '.';
//            }
//            else if (m[i][j] == 'F'){
//                fx = i;
//                fy = j;
//                m[i][j] = '.';
//            }
//        }
//    }
//    mins = 0;
//    dirc = 0;
//    dirf = 0;
//    while (!(cx == fx && cy == fy)){
//        mins++;
//        if (mins > 10000){
//            break;
//        }
//        if (m[cx + dirx[dirc]][cy + diry[dirc]] == '*'){
//            dirc++;
//            dirc %= 4;
//        }
//        else{
//            cx += dirx[dirc];
//            cy += diry[dirc];
//        }
//        if (m[fx + dirx[dirf]][fy + diry[dirf]] == '*'){
//            dirf++;
//            dirf %= 4;
//        }
//        else{
//            fx += dirx[dirf];
//            fy += diry[dirf];
//        }
//    }
//    if (cx == fx && cy == fy){
//        fout << mins << "\n";
//    }
//    else{
//        fout << 0 << "\n";
//    }
//    return 0;
//}