///*
//ID: konwoo.1
//PROG: maze1
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
//struct pos
//{
//    int row;
//    int col;
//};
//
//ifstream fin;
//ofstream fout;
//
//int W, H, w, h;
//char m[82][205] = {{0}};
//pos e[2];
//int v[82][205] = {{0}};
//
//pos moves[4] = {
//        {-1, 0},
//        {1, 0},
//        {0, -1},
//        {0, 1}
//};
//
//int steps[82][205] = {{0}};
//
//
//void search(int row, int col, int step)
//{
//    if (steps[col][row] == 0 || step < steps[col][row]) {
//        steps[col][row] = step;
//    } else {
//        return;
//    }
//
//    v[col][row] = 1;
//
//    int availableMove = 0;
//    for (int i = 0; i < 4; ++i) {
//        if (m[col + moves[i].col][row + moves[i].row] != '*' && v[col + moves[i].col][row + moves[i].row] == 0) {
//            availableMove++;
//            search(row + moves[i].row, col + moves[i].col, step + 1);
//        }
//    }
//
//    v[col][row] = 0;
//}
//
//int main()
//{
//    fin.open("maze1.in");
//    fout.open("maze1.out");
//
//    fin >> W >> H;
//    w = 2 * W + 1;
//    h = 2 * H + 1;
//    for (int i = 0; i <= w + 1; ++i) {
//        m[i][0] = '*';
//        m[i][h+1] = '*';
//    }
//    for (int i = 0; i <= h + 1; ++i) {
//        m[0][i] = '*';
//        m[w+1][i] = '*';
//    }
//
//    fin.get();
//
//    for (int row = 1; row <= h; ++row) {
//        for (int col = 1; col <= w; ++col) {
//            char c = fin.get();
//            if (c == ' ') {
//                m[col][row] = '.';
//            } else {
//                m[col][row] = '*';
//            }
//        }
//        fin.get();
//    }
//
//    int exitIndex = 0;
//    for (int i = 1; i <= w; ++i) {
//        if (m[i][1] == '.') {
//            e[exitIndex].row = 1;
//            e[exitIndex].col = i;
//            exitIndex++;
//        }
//        if (m[i][h] == '.') {
//            e[exitIndex].row = h;
//            e[exitIndex].col = i;
//            exitIndex++;
//        }
//    }
//    for (int i = 1; i <= h; ++i) {
//        if (m[1][i] == '.') {
//            e[exitIndex].row = i;
//            e[exitIndex].col = 1;
//            exitIndex++;
//        }
//        if (m[w][i] == '.') {
//            e[exitIndex].row = i;
//            e[exitIndex].col = w;
//            exitIndex++;
//        }
//    }
//
//    for (int i = 0; i < 2; ++i) {
//        search(e[i].row, e[i].col, 0);
//    }
//
//    int maxStep = 0;
//
//    for (int i = 2; i < h; ++i) {
//        for (int j = 2; j < w; ++j) {
//            if (steps[j][i] > maxStep) {
//                maxStep = steps[j][i];
//            }
//        }
//    }
//
//    fout << ((maxStep + 1) >> 1) << endl;
//
//    return 0;
//}