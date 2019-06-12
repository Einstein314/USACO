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

int N, T;
vi d;

int works(int k){
    int cind = 0, ctime = 0;
    multiset<int> s;
    F0R(i, N){
        if (s.size() == k){
            ctime = *s.begin();
            s.erase(s.begin());
        }
        s.insert(d[i] + ctime);
    }
    return *prev(s.end());
}




int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    fin >> N >> T;
    d.resize(N);
    F0R(i, N){
        fin >> d[i];
    }
    int low = 1;
    int high = N;
    while (low < high){
        int mid = (low + high)/2;
        if (works(mid) <= T){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    fout << low;




    return 0;
}
