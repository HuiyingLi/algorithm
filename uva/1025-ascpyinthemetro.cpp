#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int N, T, M1,M2;
int t[60], dl[60],dr[60];
int sched[210][60][2];
int dp[210][60];
void buildschedule(){
	memset(sched,0,sizeof(sched));
	//left
	for(int i=0;i<M1;i++){
		int tt=0;
		for(int j=0;j<N;j++){
			tt+=t[j];
			if(dl[i]+tt<210)
				sched[dl[i]+tt][j][0]=1;
		}
	}
	//right
	for(int i=0;i<M2;i++){
		int tt=0;
		sched[dr[i]][N-1][1]=1;
		for(int j=N-1;j>0;j--){
			tt+=t[j];
			if(dr[i]+tt<210)
				sched[dr[i]+tt][j-1][1]=1;
		}
	}
}
void printdp(){
	for(int i=0;i<=T;i++){
		for(int j=0;j<N;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

}
void solve(){
	buildschedule();
	for(int i=0;i<210;i++)
		for(int j=0;j<60;j++)
			dp[i][j]=214748;
	dp[0][0]=0;
	for(int i=1;i<=T;i++){
		for(int j=0;j<N;j++){
			if(i-1>=0){
				dp[i][j]=dp[i-1][j]+1;
			}
			if(j>0&&i-t[j]>=0&&sched[i-t[j]][j-1][0])
				dp[i][j]=min(dp[i][j],dp[i-t[j]][j-1]);
			if(j<N-1&&i-t[j+1]>=0&&sched[i-t[j+1]][j+1][1])
				dp[i][j]=min(dp[i][j],dp[i-t[j+1]][j+1]);
		}
	}
//	printdp();
	if(dp[T][N-1]>214740)
		cout<<"impossible\n";
	else
		cout<<dp[T][N-1]<<endl;
}
int main(){
	int C=0;
	scanf("%d",&N);
	while(N!=0){
		scanf("%d",&T);
		for(int i=1;i<N;i++){
			scanf("%d",&t[i]);
		}
		scanf("%d",&M1);
		for(int i=0;i<M1;i++){
			scanf("%d",&dl[i]);
		}
		scanf("%d",&M2);
		for(int i=0;i<M2;i++){
			scanf("%d",&dr[i]);
		}
		printf("Case Number %d: ", ++C);
		solve();
		scanf("%d",&N);
	}
	
}
