
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

int findArea(int a[4]){
    return abs((a[2] - a[0])*(a[3]-a[1]));
}


int findIntersect(int c[4], int tr[4]){
    if (tr[0] <= c[0] && tr[2] >= c[2] && tr[1] <= c[1] && tr[3] >= c[3]){
        return 0;
    }
    else if (tr[3] >= c[3] && tr[1] <= c[1] && tr[0] >= c[0] && tr[0] <= c[2] && tr[2] <= c[2] && tr[2] >= c[0]){
        return findArea(c) - abs((tr[2] - tr[0])*(c[3] - c[1]));
    }
    else if (tr[3] <= c[3] && tr[1] >= c[1] && tr[0] <= c[0] && tr[2] >= c[2] && tr[3] >= c[1] && tr[1] <= c[3]){
        return findArea(c) - abs((tr[3] - tr[1])*(c[2] - c[0]));
    }
    else if (tr[0] >= c[0] && tr[0] <= c[2] && tr[2] >= c[2] && tr[3] >= c[3] && tr[1] <= c[1]){
        return findArea(c) - abs((c[3] - c[1])*(c[2] - tr[0]));
    }
    else if (tr[2] >= c[0] && tr[2] <= c[2] && tr[0] <= c[0] && tr[3] >= c[3] && tr[1] <= c[1]){
        return findArea(c) - abs((c[3] - c[1])*(c[0] - tr[2]));
    }

    else if (tr[1] >= c[1] && tr[1] <= c[3] && tr[3] >= c[3] && tr[2] >= c[2] && tr[0] <= c[0]){
        return findArea(c) - abs((c[2] - c[0])*(c[3] - tr[1]));
    }

    else if (tr[3] >= c[1] && tr[3] <= c[3] && tr[1] <= c[1] && tr[2] >= c[2] && tr[0] <= c[0]){
        return findArea(c) - abs((c[2] - c[0])*(c[1] - tr[3]));
    }
    else if (tr[0] >= c[0] && tr[2] <= c[2] && tr[1] >= c[1] && tr[3] <= c[3]){
        return findArea(c) - findArea(tr);
    }
    else if (tr[0] >= c[2] || tr[2] <= c[0] || tr[1] >= c[3] || tr[3] <= c[1]){
        return findArea(c);
    }
    else if (tr[0] >= c[0] && tr[0] <= c[2] && tr[3] >= c[1] && tr[3] <= c[3] && tr[1] <= c[1]){
        return findArea(c) - abs((c[2] - tr[0])*(tr[3] - c[1]));
    }
    else if (tr[0] >= c[0] && tr[0] <= c[2] && tr[1] >= c[1] && tr[1] <= c[3] && tr[3] >= c[3]){
        return findArea(c) - abs((c[2] - tr[0])*(c[3] - tr[1]));
    }
    else if (tr[2] >= c[0] && tr[2] <= c[2] && tr[3] >= c[1] && tr[3] <= c[3] && tr[1] <= c[1]){
        return findArea(c) - abs((tr[2] - c[0])*(tr[3]-c[1]));
    }
    else if (tr[2] >= c[0] && tr[2] <= c[2] && tr[1] >= c[1] && tr[1] <= c[3] && tr[3] >= c[3]){
        return findArea(c) - abs((tr[2] - c[0])*(c[3]-tr[1]));
    }
    else if (tr[1] >= c[1] && tr[1] <= c[3] && tr[3] >= c[1] && tr[3] <= c[3] && tr[2] >= c[0] && tr[2] <= c[2]){
        return findArea(c) - abs((tr[2] - c[0])*(tr[3] - tr[1]));
    }
    else if (tr[1] >= c[1] && tr[1] <= c[3] && tr[3] >= c[1] && tr[3] <= c[3] && tr[0] >= c[0] && tr[0] <= c[2]){
        return findArea(c) - abs((tr[0] - c[2])*(tr[3] - tr[1]));
    }
    else if (tr[0] >= c[0] && tr[0] <= c[2] && tr[2] >= c[0] && tr[2] <= c[2] && tr[1] >= c[1] && tr[1] <= c[3]){
        return findArea(c) - abs((tr[1] - c[3])*(tr[2] - tr[0]));
    }
    else if (tr[0] >= c[0] && tr[0] <= c[2] && tr[2] >= c[0] && tr[2] <= c[2] && tr[3] >= c[1] && tr[3] <= c[3]){
        return findArea(c) - abs((tr[3] - c[1])*(tr[2] - tr[0]));
    }





}

int b1[4], b2[4], t[4];

int main(){
//    ifstream fin("/Users/konwoo/input.txt");
//    ofstream fout("/Users/konwoo/output.txt");
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    F0R(i, 4){
        fin >> b1[i];
    }
    F0R(i, 4){
        fin >> b2[i];
    }
    F0R(i, 4){
        fin >> t[i];
    }
    int a = findIntersect(b1, t);
    int b = findIntersect(b2, t);

    fout << a+b;


    return 0;
}
