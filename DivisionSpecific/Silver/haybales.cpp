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


ll n,q;
vector<ll> num;

ll bin(ll t){
    if (t < num[0]) return 0;
    ll fir = 0, las = n-1;
    while (fir <= las){
        ll mid = (fir + las)/2;
        if (num[mid] > t){
            las = mid - 1;
        }
        else{
            fir = mid + 1;
        }
    }
    return las + 1;
}


int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    fin >> n >> q;
    F0R(i, n){
        ll temp;
        fin >> temp;
        num.pb(temp);
    }

    sort(num.begin(), num.end());

    F0R(i, q){
        ll w,z;
        fin >> w >> z;
        fout << bin(z) - bin(w-1) << endl;
    }

    return 0;
}
