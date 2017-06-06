#include<iostream>
#include<string.h>
#include<stdio.h>
#include<sstream>
using namespace std;
int T;
string in;
int isp[1010][1010];
int dp[1010];
int L;
void preproc(){
	for(int i=0;i<L;i++){
		for(int j=0;j<L;j++){
			if(i-j<0||i+j>=L)
				break;
			if(in[i-j]==in[i+j]){
				isp[i-j][i+j]=1;
			}else{
				break;
			}
		}
		for(int j=0;j<L;j++){
			if(i-j<0||i+j+1>=L)
				break;
			if(in[i-j]==in[i+j+1]){
				isp[i-j][i+j+1]=1;
			}else{
				break;
			}
		}
	}
}
void solve(){
	memset(dp,0,sizeof(dp));
	memset(isp,0,sizeof(isp));
	preproc();
	for(int i=0;i<L;i++){
		int minp=10000;
		for(int j=0;j<=i;j++){
			if(isp[j][i]){
				if(j==0)
					minp=1;
				else
					minp=(dp[j-1]+1<minp)?dp[j-1]+1:minp;
			}
		}
		dp[i]=minp;
	}
	cout<<dp[L-1]<<endl;	
}
int main(){
	getline(cin,in);
	stringstream ss(in);
	ss>>T;
	while(T--){
		getline(cin,in);
		L=in.length();
		solve();
	}
	return 0;
}
