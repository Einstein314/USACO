///*
//ID: konwoo.1
//PROG: cowtour
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
//
//#define INF    (1e40)
//
//typedef struct Point Point;
//struct Point {
//    int x, y;
//};
//
//#define MAXPASTURE 150
//
//int n;
//double dist[MAXPASTURE][MAXPASTURE];
//double diam[MAXPASTURE];
//double fielddiam[MAXPASTURE];
//Point pt[MAXPASTURE];
//int field[MAXPASTURE];
//int nfield;
//
//double ptdist(Point a, Point b)
//{
//    return sqrt((double)(b.x-a.x)*(b.x-a.x)+(double)(b.y-a.y)*(b.y-a.y));
//}
//
//void mark(int i, int m)
//{
//    int j;
//    if(field[i] != -1) {
//        assert(field[i] == m);
//        return;
//    }
//
//    field[i] = m;
//    for(j=0; j<n; j++)
//        if(dist[i][j] < INF/2)
//            mark(j, m);
//}
//
//int main(void)
//{
//    FILE *fin, *fout;
//    int i, j, k, c;
//    double newdiam, d;
//
//    fin = fopen("cowtour.in", "r");
//    fout = fopen("cowtour.out", "w");
//    assert(fin != NULL && fout != NULL);
//
//    fscanf(fin, "%d\n", &n);
//    for(i=0; i<n; i++)
//        fscanf(fin, "%d %d\n", &pt[i].x, &pt[i].y);
//
//    for(i=0; i<n; i++) {
//        for(j=0; j<n; j++) {
//            c = getc(fin);
//            if(i == j)
//                dist[i][j] = 0;
//            else if(c == '0')
//                dist[i][j] = INF;
//            else
//                dist[i][j] = ptdist(pt[i], pt[j]);
//        }
//        assert(getc(fin) == '\n');
//    }
//
//    for(k=0; k<n; k++)
//        for(i=0; i<n; i++)
//            for(j=0; j<n; j++)
//                if(dist[i][k]+dist[k][j] < dist[i][j])
//                    dist[i][j] = dist[i][k]+dist[k][j];
//
//    for(i=0; i<n; i++)
//        field[i] = -1;
//    for(i=0; i<n; i++)
//        if(field[i] == -1)
//            mark(i, nfield++);
//
//    for(i=0; i<n; i++) {
//        for(j=0; j<n; j++)
//            if(diam[i] < dist[i][j] && dist[i][j] < INF/2)
//                diam[i] = dist[i][j];
//        if(diam[i] > fielddiam[field[i]])
//            fielddiam[field[i]] = diam[i];
//    }
//
//    newdiam = INF;
//    for(i=0; i<n; i++)
//        for(j=0; j<n; j++) {
//            if(field[i] == field[j])
//                continue;
//
//            d = diam[i]+diam[j]+ptdist(pt[i], pt[j]);
//            if(d < fielddiam[field[i]])
//                d = fielddiam[field[i]];
//            if(d < fielddiam[field[j]])
//                d = fielddiam[field[j]];
//
//            if(d < newdiam)
//                newdiam = d;
//        }
//
//    fprintf(fout, "%.6lf\n", newdiam);
//    exit(0);
//}