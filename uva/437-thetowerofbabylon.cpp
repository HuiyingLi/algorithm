#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

class block{
	public:
	int id;
	int a,b,h;
	block(int iid, int aa, int bb, int hh){
		this->id=iid;
		this->a=aa; this->b=bb; this->h=hh;
	}
	block(){}
};

bool comp(const block &b1, const block &b2){
	if((b1.a>b2.a&&b1.b>b2.b)||(b1.a>b2.b&&b1.b>b2.a))
		return true;
	return false;
}
int N;
block bs[300];
int dp[300];
int ans;
void search(int ind){
	for(int i=0;i<3*N+1;i++){
		if(comp(bs[i], bs[ind])){
			if(dp[i]==-1){
				search(i);
			}
			if(bs[ind].h+dp[i]>dp[ind]){
				dp[ind]=bs[ind].h+dp[i];
			}
		}
	}
	if(dp[ind]>ans)
		ans=dp[ind];
}
void solve(){
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	ans=0;
	for(int i=1;i<=3*N;i++){
		if(dp[i]==-1)
			search(i);
	}
	cout<<ans<<endl;
}
/**
void solve(){
	sort(bs, bs+3*N+1, comp);
	memset(dp,-1,sizeof(dp));
	int ans=0;
	dp[0]=0;
	for(int i=1;i<3*N+1;i++){
		int maxh=0;
		for(int j=0;j<3*N+1;j++){
			block b1=bs[j];
			block b2=bs[i];
			if(comp(b1,b2)){
				if(dp[j]<0)
					cout<<"ERROR"<<endl;
				if(dp[j]+b2.h>maxh){
					maxh=dp[j]+b2.h;
					if(maxh>ans)
						ans=maxh;
				}
			}
		}
		dp[i]=maxh;
	}
	cout<<ans<<endl;
}
**/
int main(){
	scanf("%d",&N);
	int ds[3];
	int Case=0;
	block inf(0, 2147483647,2147483647,0);
	bs[0]=inf;
	while(N){
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++)
				scanf("%d",&ds[j]);
			block b1(i*3+1, ds[0],ds[1],ds[2]);
			bs[b1.id]=b1;
			block b2(i*3+2, ds[1],ds[2],ds[0]);
			bs[b2.id]=b2;
			block b3(i*3+3, ds[2],ds[0],ds[1]);
			bs[b3.id]=b3;
		}
		cout<<"Case "<<++Case<<": maximum height = ";
		solve();
		scanf("%d",&N);
	}
	return 0;
}
