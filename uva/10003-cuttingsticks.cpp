#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;
int l,n;
int ct[60];
int dist[60][60];
int dp[60][60];
void getdist(){
	ct[n+1]=l;
	for(int i=0;i<=n+1;i++){
		for(int j=i+1;j<=n+1;j++){
			dist[i][j]=ct[j]-ct[i];
		}
	}
}
void solve(){
	getdist();
	for(int d=2;d<=n+1;d++){
		for(int i=0;i<=n+1;i++){
			if(i+d>n+1)
				continue;
			int minc=2147483647;
			for(int k=i+1;k<i+d;k++){
				if(dp[i][k]+dp[k][i+d]<minc){
					minc=dp[i][k]+dp[k][i+d];
				}
			}
			dp[i][i+d]=minc+dist[i][i+d];
		}
	}	
	cout<<dp[0][n+1];
}
int main(){
	scanf("%d",&l);
	while(l!=0){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&ct[i+1]);
		}
		cout<<"The minimum cutting is ";
		solve();
		cout<<".\n";
		scanf("%d",&l);
	}
	return 0;
}
