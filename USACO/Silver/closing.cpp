//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;


#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int N, M;

int order[3010];
//vector< vector< pii > > AdjList(3010, vector<pii>(3010, make_pair(-1, 0)));
vector <vector< pii > > AdjList(3010);
vi dfs_num;

void dfs(int u, int ord){
    dfs_num[u] = 1;
    F0R(j, (int)AdjList[u].size()){
        pii v = AdjList[u][j];
        if (dfs_num[v.first] == 0 && v.s > ord){
            dfs(v.first, ord);
        }
    }
}

int CC(int o){
    int numCC = 0;
    dfs_num.assign(N, 0);
    F0R(i, N){
        if (dfs_num[i] == 0 && order[i] > o){
            ++numCC;
            dfs(i, o);
        }
    }
    return numCC;
}





int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    fin >> N >> M;

    F0R(i, M){
        int a, b;
        fin >> a >> b;
        AdjList[a-1].pb(mp(b-1, 0));
        AdjList[b-1].pb(mp(a-1, 0));
    }

    F0R(i, N){
        int c;
        fin >> c;
        order[c - 1] = i+1;
    }

    F0R(i, N){
        F0R(j, (int)AdjList[i].size()){
            int a = min(order[i], order[AdjList[i][j].f]);
            AdjList[i][j].s = a;
            //fout << i << " " << AdjList[i][j].f << " " << AdjList[i][j].s << "\n";
        }
    }


    F0R(i, N){
        if (CC(i) == 1){
            fout << "YES" << "\n";
        }
        else{
            fout << "NO" << "\n";
        }
    }








    return 0;
}





