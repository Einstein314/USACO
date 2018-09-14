//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

#include <unordered_set>
#include <set>

//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

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

const int MOD = 1000000009;
double PI = 4*atan(1);



struct compare {
    bool operator()(pii a, pii b) const{
        return a.f < b.f;
    }
};


int n;
multiset<pii, compare> towers;





int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("multimoo.in");
//    ofstream fout("multimoo.out");
//    freopen("milkorder.in","r",stdin);
//    freopen("milkorder.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int temp;
    cin >> temp;
    towers.insert(mp(temp, 1));
    int total = 1;
    FOR(i, 1, n){
        int siz;
        cin >> siz;
        multiset<pii>::iterator itlow = towers.upper_bound(mp(siz,1));
        if (itlow == towers.end()){
            towers.insert(mp(siz,1));
            total++;
        }
        else{
            towers.insert(mp(siz,itlow->s + 1));
            towers.erase(itlow);
        }
    }

    cout << total;

    return 0;

}


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
##**(better version)**
//#include "/Users/konwoo/stdc++.h"
#include "bits/stdc++.h"

#include <unordered_set>
#include <set>

//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

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

const int MOD = 1000000009;
double PI = 4*atan(1);



int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
//    ifstream fin("multimoo.in");
//    ofstream fout("multimoo.out");
//    freopen("milkorder.in","r",stdin);
//    freopen("milkorder.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;
    multiset<int> s;
    while(n--){
        cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.end()) s.insert(x);
        else{
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;

    return 0;

}














