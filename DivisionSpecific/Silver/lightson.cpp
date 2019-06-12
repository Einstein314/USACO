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

//#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> AdjList[100][100], targets;
int a,b,c,d, N, M;
int on[100][100] = { { 0 } };
int visited[100][100] = { { 0 } };

void visit(int x, int y){
    visited[x][y] = 1;
    for (auto i = AdjList[x][y].begin(); i != AdjList[x][y].end(); ++i){
        if (!on[i->first][i->second]){
            on[i->first][i->second] = 1;
            targets.pb(make_pair(i->first, i->second));
        }

    }
}



int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    fin >> N >> M;

    F0R(i, M){
        fin >>  a >> b >> c >> d;
        AdjList[a-1][b-1].pb(make_pair(c-1,d-1));
    }

    on[0][0] = 1;
    visit(0,0);

    auto x = targets.begin();
    while (x != targets.end()){
        int i = x->f;
        int j = x->s;
        const bool access = (i != 0 && visited[i-1][j]) || (j != 0 && visited[i][j-1]) || (i != N - 1 && visited[i+1][j]) || (j != N-1 && visited[i][j+1]);
        if (access){
            targets.erase(x);
            visit(i, j);
            x = targets.begin();
        }
        else{
            ++x;
        }
    }
    int ans = 0;
    F0R(w, N){
        F0R(q, N){
            ans += on[w][q];
        }
    }
    fout << ans << endl;



    return 0;
}





