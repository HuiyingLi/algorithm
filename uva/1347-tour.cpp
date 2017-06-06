#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 1000

int n;
int px[maxn];
int py[maxn];
double dp[maxn][maxn];
//double dist[maxn];

double dist(int i, int j){
	int d1=px[i]-px[j];
	int d2=py[i]-py[j];
	return sqrt(d1*d1+d2*d2);
}

double search(int i, int j){
	//i-1, j, i jumpped
	if(dp[i][j]!=0)
		return dp[i][j];
	dp[i][j]=search(i+1,i)+dist(i+1,j);//j-->i+1
	dp[i][j]=min(dp[i][j],search(i+1,j)+dist(i+1,i));//i-->i+1
	return dp[i][j];
}
void solve(){
	if(n==1){
		printf("%.2f\n",0.0);
		return;
	}
	if(n==2){
		printf("%.2f\n",2*dist(0,1));
		return;
	}
	memset(dp,0,sizeof(dp));
	double df=dist(n-2,n-1);
	for(int i=0;i<n-2;i++){
		dp[n-2][i]=df+dist(i,n-1);
	}
	double ans = search(1,0);
	ans+=dist(0,1);
	printf("%.2f\n",ans);
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&px[i],&py[i]);
		}
		solve();
	}
	return 0;
}
