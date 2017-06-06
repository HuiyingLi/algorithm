#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class state{
	public:
	long val;
	string path;
};

int m,n;
int mt[20][110];
int next[20][110];
state dp[20][110];

void init(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j].val=0;
			dp[i][j].path="";
		}
	}
}
void solve(){
	init();
	long res=2147483647;
	for(int i=0;i<m;i++){
		dp[i][0].val=mt[i][0];
		dp[i][0].path+='0'+(i+1);
		if(n==1){
			if(dp[i][0].val<res){
				res=dp[i][0].val;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			int a1=j-1>=0?j-1:m-1;
			int a3=j+1<m?j+1:0;
			dp[j][i].val=dp[a1][i-1].val;
			if(dp[j][i].val<dp[j][i-1].val){
				//next[a1][i-1]=j;
				dp[j][i].path=dp[a1][i-1].path;
			}else if(dp[j][i].val==dp[j][i-1].val){
				//next[j][i]=a1<j?a1:j;
				dp[j][i].path=dp[j][i-1].path<dp[a1][i-1].path?dp[j][i-1].path:dp[a1][i-1].path;
			}else{
			//	next[j][i]=j;
				dp[j][i].val=dp[j][i-1].val;
				dp[j][i].path=dp[j][i-1].path;
			}
			if(dp[j][i].val==dp[a3][i-1].val){
			//	next[j][i]=a3<j?a3:j;
				dp[j][i].path=dp[j][i].path<dp[a3][i-1].path?dp[j][i].path:dp[a3][i-1].path;
			}else if(dp[j][i].val>dp[a3][i-1].val){
			//	next[j][i]=a3;
				dp[j][i].path=dp[a3][i-1].path;
				dp[j][i].val=dp[a3][i-1].val;
			}
			dp[j][i].val+=mt[j][i];
			dp[j][i].path+='0'+(j+1);
			if(i==n-1){
				if(dp[j][i].val<res){
					res=dp[j][i].val;
				}
			}
		}
	}
	string minans=""+(':'+1);
	for(int i=0;i<m;i++){
		if(dp[i][n-1].val==res){
			/**
			string ans=to_string(i+1);
			int ind=next[i][n-1];
			for(int j=n-1;j>0;j--){
				ans=to_string(next[ind][j]+1)+ans;
				ind=next[next[ind][j]][j-1];
				
			}
			**/	
			if(dp[i][n-1].path<minans){
				minans=dp[i][n-1].path;
			}
		}
	}
	if(minans[0]==':')
		cout<<"10";
	else
		cout<<minans[0];
	for(int i=1;i<minans.length();i++)
		if(minans[i]==':')
			cout<<" 10";
		else
			cout<<" "<<minans[i];
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
