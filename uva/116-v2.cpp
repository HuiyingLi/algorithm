#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int m,n;
long dp[20][110];
long next[20][110];
int mt[20][110];
void solve(){
	long res=2147483647;
	int ind=-1;
	for(int i=0;i<m;i++){
		dp[i][n-1]=mt[i][n-1];
		if(n==1&&dp[i][n-1]<res){
			res=dp[i][n-1];
			ind=i;
		}
	}
	for(int j=n-2;j>=0;j--){
		for(int i=0;i<m;i++){
			int rs[3];
			rs[0]=i-1;
			rs[1]=i;
			rs[2]=i+1;
			if(rs[0]<0)
				rs[0]=m-1;
			if(rs[2]>m-1)
				rs[2]=0;
			sort(rs,rs+3);
			dp[i][j]=dp[rs[0]][j+1];
			next[i][j]=rs[0];
			for(int k=1;k<3;k++){
				if(dp[i][j]>dp[rs[k]][j+1]){
					dp[i][j]=dp[rs[k]][j+1];
					next[i][j]=rs[k];
				}
			}
			dp[i][j]+=mt[i][j];
			if(j==0 && dp[i][j]<res){
				res=dp[i][j];
				ind=i;
			}
		}
	}
	cout<<ind+1;
	for(int i=0;i<n-1;i++){
		cout<<" "<<next[ind][i]+1;
		ind=next[ind][i];
	}
	cout<<endl<<res<<endl;
}
int main(){
	while(scanf("%d%d",&m, &n)!=EOF){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&mt[i][j]);
			}
		}
		solve();
	}
	return 0;
}
