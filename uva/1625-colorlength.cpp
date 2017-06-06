#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;
int T,m,n;
bool DBG=true;
string A,B;
int dp[5005][5005];
int inc[5005][5005];
int cc[5005][5005];
int pl[27][2][2];
int f[27];
void placeinfo(){
	for(int i=0;i<27;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++)
				pl[i][j][k]=-2;
		}
	}
	for(int i=0;i<m;i++){
		int ind=A[i]-'A';
		if(pl[ind][0][0]==-2){
			pl[ind][0][0]=i;
			pl[ind][0][1]=i;
		}else if(pl[ind][0][1]<i){
			pl[ind][0][1]=i;
		}
	}
	for(int i=0;i<n;i++){
		int ind=B[i]-'A';
		if(pl[ind][1][0]==-2){
			pl[ind][1][0]=i;
			pl[ind][1][1]=i;
		}else if(pl[ind][1][1]<i){
			pl[ind][1][1]=i;
		}
	}
}
void solve(){
	placeinfo();
//	for(int i=0;i<=m;i++)
//		for(int j=0;j<=n;j++)
//			inc[i][j]=0;
	dp[0][0]=0;
	cc[0][0]=0;
	memset(f,0,sizeof(f));
	for(int j=1;j<=n;j++){
		char c1=B[j-1];
		if(((pl[c1-'A'][0][0]==-2||0<pl[c1-'A'][0][0])&&(pl[c1-'A'][1][0]==-2||j<pl[c1-'A'][1][0]+1))||((pl[c1-'A'][0][0]==-2||0>=pl[c1-'A'][0][1]+1)&&(pl[c1-'A'][1][0]==-2||j>=pl[c1-'A'][1][1]+1))){
			if(f[c1-'A']!=0)
				cc[0][j]=cc[0][j-1]-1;
			else
				cc[0][j]=cc[0][j-1];
		}else if(!f[c1-'A']){
			cc[0][j]=cc[0][j-1]+1;
		}else if(f[c1-'A']){
			cc[0][j]=cc[0][j-1];
		}
		f[c1-'A']=1;
//		if(DBG) cout<<cc[0][j]<<" ";
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++){
		char c2=A[i-1];
		if(((pl[c2-'A'][0][0]==-2||i<pl[c2-'A'][0][0])&&(pl[c2-'A'][1][0]==-2||0<pl[c2-'A'][1][0]+1))||((pl[c2-'A'][0][0]==-2||i>=pl[c2-'A'][0][1]+1)&&(pl[c2-'A'][1][0]==-2||0>=pl[c2-'A'][1][1]+1))){
			if(f[c2-'A']!=0)
				cc[i][0]=cc[i-1][0]-1;
			else
				cc[i][0]=cc[i-1][0];
		}else if(!f[c2-'A']){
			cc[i][0]=cc[i-1][0]+1;
		}else if(f[c2-'A']){
			cc[i][0]=cc[i-1][0];
		}
		f[c2-'A']=1;
	}
//	if(DBG) cout<<endl;
	memset(f,0,sizeof(f));
	f[A[0]-'A']=1;
	for(int i=0;i<=m;i++){
		if(i>0)
			f[A[i-1]-'A']=1;
		int fo[27];
		memset(fo,0,sizeof(fo));
		for(int j=0;j<=n;j++){
			if(i!=0&&j!=0){
				char c2=B[j-1];
				if(((pl[c2-'A'][0][0]==-2||i<pl[c2-'A'][0][0])&&(pl[c2-'A'][1][0]==-2||j<pl[c2-'A'][1][0]+1))||((pl[c2-'A'][0][0]==-2||i>=pl[c2-'A'][0][1]+1)&&(pl[c2-'A'][1][0]==-2||j>=pl[c2-'A'][1][1]+1))){
					if(f[c2-'A']!=0||fo[c2-'A']!=0)
						cc[i][j]=cc[i][j-1]-1;
					else
						cc[i][j]=cc[i][j-1];
				}else if(!f[c2-'A']&&!fo[c2-'A']){
					cc[i][j]=cc[i][j-1]+1;
				}else if(f[c2-'A']||fo[c2-'A']){
					cc[i][j]=cc[i][j-1];
				}
				fo[c2-'A']=1;
			}
//			if(DBG) cout<<cc[i][j]<<" ";
	/**		for(int k=0;k<26;k++){
				if(!f[k]) continue;
				if(((pl[k][0][0]==-2||i<pl[k][0][0]+1)&&(j<pl[k][1][0]+1||pl[k][1][0]==-2))||((pl[k][0][0]==-2||i>=pl[k][0][1]+1)&&(pl[k][1][0]==-2||j>=pl[k][1][1]+1)))
					continue;
				inc[i][j]++;
		//		if(DBG)printf("%c",'A'+k);
			}
		//	if(DBG)	cout<<" ";
**/
		
			int a=2147483647,b=214748647;
			if(i>0){
				a=dp[i-1][j]+cc[i-1][j];
			}
			if(j>0){
				b=dp[i][j-1]+cc[i][j-1];
			}
			if(i!=0||j!=0)
				dp[i][j]=a<b?a:b;
		}
		
//		if(DBG)cout<<endl;
	}
/*
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<cc[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	cout<<dp[m][n]<<endl;
}
int main(){
	string tmp;
	getline(cin,tmp);
	stringstream ss(tmp);
	ss>>T;
	while(T--){
		getline(cin, A);
		getline(cin,B);
		m=A.length();
		n=B.length();
		solve();
	}
	return 0;
}
