

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

//int b1[4], b2[4], truck[4];
//
//int area(int a[4]){
//    return abs((a[2] - a[0]) * (a[3]-a[1]));
//}

int findmax(int arr[3]){
    if (arr[0] > arr[1] && arr[0] > arr[2]){
        return 4;
    }
    if (arr[1] > arr[0] && arr[1] > arr[2]){
        return 2;
    }
    if (arr[2] > arr[0] && arr[2] > arr[1]){
        return 1;
    }
    if (arr[0] == arr[1] && arr[0] > arr[2]){
        return 6;
    }
    if (arr[0] == arr[2] && arr[0] > arr[1]){
        return 5;
    }
    if (arr[1] == arr[2] && arr[1] > arr[0]){
        return 3;
    }
    if (arr[1] == arr[2] && arr[2] == arr[0]){
        return 7;
    }
}

int N, d[105], change[105], m[3];
string names[105], temp[105];

vector<int> c;
map <int, pair<string, int> > milk;

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    fin >> N;
    F0R(i, N){
        fin >> d[i] >> names[i] >> temp[i];
        change[i] = stoi(temp[i]);
        milk.insert(mp(d[i], mp(names[i], change[i])));
    }

    F0R(i, 3){
        m[i] = 7;
    }
    c.pb(findmax(m));
    F0R(i, 101){

        for (auto a : milk){
            if (a.f == i+1){
                if (a.s.f == "Bessie"){
                    m[0] += a.s.s;
                }
                if (a.s.f == "Elsie"){
                    m[1] += a.s.s;
                }
                if (a.s.f == "Mildred"){
                    m[2] += a.s.s;
                }
            }
        }
        c.pb(findmax(m));

    }

    int ans = 0;
    F0R(i, c.size() - 1){
        if(c[i] != c[i+1]) {
            ans++;
        }
    }

    fout << ans;
//

    return 0;
}
