//#include "bits/stdc++.h"
#include "/Users/konwoo/stdc++.h"
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
int arr[200100], ans = 0, counter[200100], x = 1;
bool g[200100];

int main()
{
	cin >> n;
	F0R(i,n){
		cin >> arr[i];
		if (counter[arr[i]]++) ans++;
	}

	cout << ans << endl;

	F0R(i, n){
		if(counter[arr[i]] > 1){
			while(counter[x]) x++;
			if (x < arr[i] || g[arr[i]]){
				counter[arr[i]]--;
				counter[x]++;
				cout << x << " ";
			}
			else{
				g[arr[i]] = 1;
				cout << arr[i] << " ";
			}

		}
		else{
			cout << arr[i] << " ";
		}
	}


    return 0;
}
