#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
int T;
string in;
int n;
int dp[110][110];
int sol[110][110];
bool match(int i, int j){
	if((in[i]=='('&&in[j]==')')||(in[i]=='['&&in[j]==']'))
		return true;
	return false;
}

void print(int i, int j){
	if(i>j)
		return;
	if(i==j){
		if(in[i]=='('||in[i]==')')
			cout<<"()";
		else 
			cout<<"[]";
		return;
	}
	if(sol[i][j]==-1){
		cout<<in[i];
		print(i+1,j-1);	
		cout<<in[j];
	}else{
		int k=sol[i][j];
		print(i,k);
		print(k+1,j);
	}
}
void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n+10&&i<110;i++){
		for(int j=0;j<n+1&&j<110;j++){
			sol[i][j]=-2;
		}
	}
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int d=1;d<n;d++){
		for(int i=0;i<n-1;i++){
			if(i+d>=n)continue;
			dp[i][i+d]=n;
			if(match(i,i+d)){
				dp[i][i+d]=min(dp[i][i+d],dp[i+1][i+d-1]);
				sol[i][i+d]=-1;
			}
			for(int k=i;k<i+d;k++){
				if(dp[i][k]+dp[k+1][i+d]<=dp[i][i+d]){
					dp[i][i+d]=dp[i][k]+dp[k+1][i+d];
					sol[i][i+d]=k;
				}
			}
		}
	}
	print(0,n-1);
	cout<<endl;
}
int main(){
	string line;
	getline(cin,line);
	stringstream ss(line);
	ss>>T;
	while(T--){
		getline(cin,line);
		getline(cin,in);
		n=in.length();
		solve();
		if(T!=0)
			cout<<endl;
	}
	return 0;
}
