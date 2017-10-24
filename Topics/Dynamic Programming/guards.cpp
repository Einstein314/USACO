
#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long

int dp[251][1 << 15][2][2], n, m, md = 1e9 + 7;
char s[250][251];

inline void ad(int &x, int y) { if ((x += y) >= md)x -= md; }
inline int ID(int a, int b) { return a * m + b; }

int main(){
	scanf("%d%d", &n, &m);
	f(i, 0, n)scanf("%s", s[i]);
	if (m > 15){
		f(i, 0, n)f(j, i + 1, m)swap(s[i][j], s[j][i]);
		swap(n, m);
	}
	dp[0][0][0][0] = 1;
	f(i, 0, n)f(j, 0, m)f(msk, 0, 1 << m)f(bf, 0, 2)f(bad, 0, 2)f(ch, 0, 2){
		int id = ID(i, j), nid = id + 1, nmsk = msk | ch << j, nbf = bf || ch, nbad = !ch && !bf && !(msk >> j & 1);
		if (s[i][j] == 'x'){
			if (ch)continue;
			nmsk &= ~(1 << j);
			nbf = 0;
			nbad = 0;
		}
		if (j + 1 == m)nbf = 0;
		if (bad && nbad)continue;
		nbad |= bad;
		ad(dp[nid][nmsk][nbf][nbad], dp[id][msk][bf][bad]);
	}
	int an = 0;
	f(i, 0, 1 << m)f(j, 0, 2)f(k, 0, 2)ad(an, dp[n * m][i][j][k]);
	printf("%d\n", an);
}
