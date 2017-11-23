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

char st[5000];

bool conson(char c){
	return c && c != 'a' && c != 'e' && c!= 'i' && c!= 'o' && c!= 'u';
}

bool check(int i){
	if (i < 2) return false;
	if (st[i] == st[i-1] && st[i-1] == st[i-2]) return false;
	return conson(st[i-2]) && conson(st[i-1]) && conson(st[i]);
}


int main()
{
	cin >> st;
	F0R(i, 5000){
		if (check(i)){
			cout << ' ' ;
			st[i-1] = 0;
		}
		cout << st[i];
	}
	cout << ' ';
    return 0;
}


#include<cstdio>
char s[3010];
bool con(char c){
	return c&&c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u';
}
bool chk(int i){
	if(i<2)return 0;
	if(s[i-2]==s[i-1]&&s[i-1]==s[i])return 0;
	return con(s[i-2])&&con(s[i-1])&&con(s[i]);
}
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(chk(i))putchar(' '),s[i-1]=0;
		putchar(s[i]);
	}
	puts("");
}
