///*
//ID: konwoo.1
//PROG: butter
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
//const int INF = 1<<20;
//double PI = 4*atan(1);
//
//using namespace std;
//
//const int MAX = 801;
//int n,p,c;
//int m[MAX][MAX];
//int d[MAX][MAX];
//int cow[MAX];
//vector<int> con[MAX];
//
//void SPFA(int v0)
//{
//    queue<int> Q;
//    bool v[MAX]={0};
//    Q.push(v0);
//    while(!Q.empty())
//    {
//        int cur = Q.front();
//        Q.pop();
//        for(int i=0;i!=con[cur].size();i++)
//        {
//            int cp = con[cur][i]; // connected point
//            if(d[v0][cur]+m[cur][cp] < d[v0][cp])
//            {
//                d[v0][cp] = d[v0][cur]+m[cur][cp];
//                if(!v[cp])
//                {
//                    Q.push(cp);
//                    v[cp]=1;
//                }
//            }
//        }
//        v[cur] = 0;
//    }
//}
//
//int main()
//{
//#ifndef LOCAL
//    ifstream cin("butter.in");
//    ofstream cout("butter.out");
//#endif
//    cin >> n >> p >> c;
//    for(int i=0;i!=n;i++)
//        cin >> cow[i];
//    int x,y,dis;
//    for(int i=1;i<=c;i++)
//    {
//        cin >> x >> y >> dis;
//        m[x][y]=m[y][x] = dis;
//        con[x].push_back(y);
//        con[y].push_back(x);
//    }
//    for(int i=1;i<=p;i++)
//        for(int j=1;j<=p;j++)
//            d[i][j] = INF;
//    for(int i=1;i<=p;i++)
//        m[i][i]=d[i][i]=0;
//    for(int i=1;i<=p;i++)
//        SPFA(i);
//    int min = INF;
//    for(int i=1;i<=p;i++)
//    {
//        int sum =0;
//        for(int j=0;j!=n;j++)
//            sum+= d[cow[j]][i];
//        if (sum<min) min = sum;
//    }
//    cout << min << endl;
//    return 0;
