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

//#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int N, G;



struct measure {
    int day;
    int cow;
    int delta;

};

bool sortm (const measure& a, const measure& b){
    return a.day < b.day;
}

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    fin >> N >> G;

    vector<measure> m(N);
    for (auto &a : m){
        fin >> a.day >> a.cow >> a.delta;
    }
    sort(m.begin(), m.end(), sortm);

    int result = 0;
    map<int, int> mp;
    map<int, int, greater<int> >cnts;
    cnts[0] = N + 1;

    for (auto &a : m){
        int& ret = mp[a.cow];
        int wascnt = cnts[ret]--;
        bool wastop = ret == cnts.begin()->first;
        if (wascnt == 1){
            cnts.erase(ret);
        }

        ret += a.delta;
        int iscnt = ++cnts[ret];
        bool istop = ret == cnts.begin()->first;

        if (wastop){
            if (!istop || wascnt != 1 || iscnt != 1){
                ++result;
            }
        }
        else if (istop){
            ++result;
        }
    }
    fout << result;


    return 0;
}
