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

int n;


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    fin >> n;
    map <string, int> log;
    map <string, int> :: iterator itr;
    string arr[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

    F0R(i, 7){
        log.insert(mp(arr[i], 0));
    }


    F0R(i, n){
        string name;
        int milk;
        fin >> name >> milk;

        auto t = log.find(name);
        t->s+=milk;

    }
    pair<string, int> m = mp("min", 10000000);
    pair<string, int> n = mp("smin", 10000000);

    for(itr = log.begin(); itr != log.end(); itr++){
        if (itr->s < m.s){
            m.f = itr->f;
            m.s = itr->s;
        }
    }

    for(itr = log.begin(); itr != log.end(); itr++){
        if (itr->s < n.s && itr->s > m.s){
            n.f = itr->f;
            n.s = itr->s;
        }
    }

    int counter = 0;
    for (itr = log.begin(); itr != log.end(); itr++){
        if (itr->s == n.s){
            counter++;
        }
    }


    if (counter != 1){
        fout << "Tie\n";
    }
    else{
        fout << n.f << endl;
    }





    return 0;
}
