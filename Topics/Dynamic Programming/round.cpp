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

int dp[205][6000], n, k;
ll temp;
int main()
{

	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    
	F0R(i, n){
		cin >> temp;
		int t = 0;
		int f = 0;

		while (temp % 5 == 0) temp/=5, f++;
		while (temp % 2 == 0) temp/=2, t++;

		F0Rd(j, k){
			F0R(l, 6000){
				if (dp[j][l] != -1){
					dp[j+1][l+f] = max(dp[j+1][l+f], dp[j][l] + t);
				}
			}
		}
	}

	int ans = 0;
	F0R(i, 6000){
		ans = max(ans, min(i, dp[k][i]));
	}

	cout << ans;
   



    return 0;
}
