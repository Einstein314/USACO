
#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[234][5200],n,k,tmp;
main(){
	memset(dp,-1,sizeof dp);
	dp[0][0]=0;
	cin>>n>>k;
	for(int s=0;s<n;s++){
		cin>>tmp;
		int t=0,f=0;
		while(tmp%2==0) t++,tmp/=2;
		while(tmp%5==0) f++,tmp/=5;
		for(int i=k-1;i>=0;i--)
			for(int j=0;j<5200;j++)
				if(dp[i][j]!=-1)
					dp[i+1][j+f]=max(dp[i+1][j+f],dp[i][j]+t);
	}
	int ans=0;
	for(int i=0;i<5200;i++) ans=max(ans,min(i,dp[k][i]));
	cout<<ans<<endl;
}
