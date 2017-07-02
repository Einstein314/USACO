/*
ID: konwoo.1
PROG: namenum
LANG: C++11
*/

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

int alph[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

string numberize(string a){
    string j = "";
    F0R(i, a.length()) j+= char(alph[a[i]-'A'] + '0');
    return j;
}

int main() {
    ifstream cin("namenum.in");
    ifstream fin ("dict.txt");
    ofstream cout("namenum.out");
    bool exists = false;
    string s,s1;
    cin >> s;
    while (fin >> s1){
        if (numberize(s1) == s){
            exists = true;
            cout << s1 << "\n";
        }
    }
    if (!exists) {
        cout << "NONE" << "\n";
    }
    return 0;
}

