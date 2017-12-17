//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

using namespace std;



typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

bool adj[200][200];
pair<pii,int> cows[200];

int dist(pii a, pii b) {
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int N; fin >> N;
    int z = 0;
    F0R(i,N) fin >> cows[i].f.f >> cows[i].f.s >> cows[i].s;
    F0R(i,N) F0R(j,N) if (i != j && dist(cows[i].f,cows[j].f) <= cows[i].s*cows[i].s) adj[i][j] = 1;
    F0R(i,N) {
        int visit[200];
        F0R(j,N) visit[j] = 0;
        queue<int> todo;
        todo.push(i);
        while (todo.size()) {
            int k = todo.front(); todo.pop();
            visit[k] = 1;
            F0R(j,N) if (adj[k][j] && visit[j] == 0) {
                    visit[j] = -1;
                    todo.push(j);
                }
        }
        int ans = 0;
        F0R(j,N) if (visit[j] == 1) ans++;
        // cout << ans << "\n";
        z = max(z,ans);
    }
    fout << z;


}
