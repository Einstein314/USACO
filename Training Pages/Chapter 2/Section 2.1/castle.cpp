///*
//ID: konwoo.1
//PROG: castle
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
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
//int r,c,rn,maxn,max2n,wx,wy,wd;
//int m[51][51],v[51][51],b[51][51],room[2501];
//void dfs(int i,int j,int& s)
//{
//    if(v[i][j]) return;
//    v[i][j] = 1;
//    b[i][j] = rn;
//    s++;
//    if(!(m[i][j]&1)) dfs(i,j-1,s);
//    if(!(m[i][j]&2)) dfs(i-1,j,s);
//    if(!(m[i][j]&4)) dfs(i,j+1,s);
//    if(!(m[i][j]&8)) dfs(i+1,j,s);
//}
//int main()
//{
//    ifstream fin("castle.in");
//    ofstream fout("castle.out");
//    fin >> c >> r ;
//    int in;
//    for(int i=1;i<=r;i+=1)
//        for(int j=1;j<=c;j+=1)
//            fin >> m[i][j];
//    for(int i=1;i<=r;i+=1)
//        for(int j=1;j<=c;j+=1)
//            if(!v[i][j])
//            {
//                rn++;
//                int tn=0;
//                dfs(i,j,tn);
//                room[rn] = tn;
//                if( tn > maxn ) maxn = tn;
//            }
//    for(int j=1;j<=c;j+=1)
//        for(int i=r;i>=1;i-=1)
//        {
//            if((b[i-1][j] != b[i][j]) && (room[b[i-1][j]] + room[b[i][j]] > max2n ))
//            {
//                max2n = room[b[i-1][j]] + room[b[i][j]];
//                wx = i,wy = j,wd = 'N';
//            }
//            if((b[i][j+1] != b[i][j]) && (room[b[i][j+1]] + room[b[i][j]] > max2n ))
//            {
//                max2n = room[b[i][j+1]] + room[b[i][j]];
//                wx = i,wy = j,wd = 'E';
//            }
//        }
//    fout << rn << endl << maxn << endl << max2n <<endl;
//    fout << wx <<" " << wy <<" " << char(wd) <<endl;
//    return 0;
//}