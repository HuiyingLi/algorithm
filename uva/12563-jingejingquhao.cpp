#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int T, n;
long t;
int len[60];
int dp[10000];
int ml[10000];
void solve(){
	memset(dp,0,sizeof(dp));
	memset(ml,0,sizeof(ml));
	for(int i=1;i<=t-1;i++){
		dp[i]=i>=len[0]?1:0;
		if(dp[i]==1){
			ml[i]=len[0];
		}
	}
	for(int j=1;j<n;j++){
		for(int i=t-1;i>0;i--){
			int s=i-len[j]>=0?dp[i-len[j]]+1:0;
			if(s==dp[i]&&i-len[j]>=0){
				ml[i]=max(ml[i-len[j]]+len[j],ml[i]);
				//if(ml[i]-len[j-1]>=0)
				//	ml[i]=ml[]-len[j-1]+(len[j-1]>len[j]?len[j-1]:len[j]);
			}else if(s>dp[i]){
				dp[i]=s;
				ml[i]=ml[i-len[j]]+len[j];
			}
		}
	}
	cout<<dp[t-1]+1<<" "<<ml[t-1]+678<<endl;
}
int main(){
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d%ld",&n,&t);
		for(int i=0;i<n;i++)
			scanf("%d",&len[i]);
		cout<<"Case "<<cas+1<<": ";
		solve();
	}
	return 0;
}
