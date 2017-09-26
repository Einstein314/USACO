///*
//ID: konwoo.1
//PROG: agrinet
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
//class UnionFind{
//private: vi p, rank;
//public:
//    UnionFind(int N){
//        rank.assign(N, 0);
//        p.assign(N,0);
//        F0R(i, N){
//          p[i] = i;
//        }}
//    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
//    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
//    void unionSet(int i, int j){
//        if (!isSameSet(i, j)){
//            int x = findSet(i), y = findSet(j);
//            if (rank[x] > rank[y]) p[y] = x;
//            else{
//                p[x] = y;
//                if (rank[x] == rank[y]) rank[y]++;
//            }
//        }
//    }
//};
//
//
//
//
//int main() {
//    ifstream fin("agrinet.in");
//    ofstream fout("agrinet.out");
////    ifstream fin("sort3.txt");
////    ofstream fout("sort4.txt");
//    int N;
//    fin >> N;
//    int d[N][N];
//    vector< pair<int, pii> > el;
//    F0R(i, N){
//        F0R(j, N){
//            fin >> d[i][j];
//            if (i != j){
//                el.pb(mp(d[i][j], pii(i , j)));
//            }
//        }
//    }
//    sort(el.begin(), el.end());
//    int mst = 0;
//    UnionFind UF(N);
//    for(size_t i = 0; i < el.size(); i++){
//        pair<int, pii> front = el[i];
//        if(!UF.isSameSet(front.s.f, front.s.s)){
//            mst += front.f;
//            UF.unionSet(front.s.f, front.s.s);
//        }
//    }
//    fout << mst << "\n";
//    return 0;
//}