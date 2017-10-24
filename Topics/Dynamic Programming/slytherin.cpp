

 #include<bits/stdc++.h>
#define int long long
using namespace std;
int f[11][65][(1<<11)+(1<<4)];
int d,l,r,cnt=0,a[65];
int dp(int P,int L,int B,int Z) {
	if(P==0) return (B==0)&&(Z==0);
	if(!L&&!Z&&f[d][P][B]!=-1) return f[d][P][B];
	int up=(L?a[P]:d-1);
	int ans=0;
	for(int i=0;i<=up;i++) {
		if(i==0&&Z) ans+=dp(P-1,L&&(i==up),B,1);
		else ans+=dp(P-1,L&&(i==up),B^(1<<i),0);
	}
	if(!L&&!Z) f[d][P][B]=ans;
	return ans;
}

int S(int x) {
	for(cnt=0;x;a[++cnt]=x%d,x/=d);
	return dp(cnt,1,0,1);
}

main() {
	cin>>d;memset(f,-1,sizeof(f));
	while(cin>>d>>l>>r) cout<<S(r)-S(l-1)<<"\n";
}
