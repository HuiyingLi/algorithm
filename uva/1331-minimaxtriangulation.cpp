#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int T,m;
int x[60],y[60];
double dp[60][60];
double area[60][60];
double getarea(int i,int j,int k){
	return fabs(x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]))*1.0/2;
}

double cross(int x1, int y1, int x2,int y2){
	return x1*y2-y1*x2;
}
bool isLineIntersect(int A1x,int A1y, int A2x, int A2y, int B1x, int B1y, int B2x, int B2y){
	double c1=cross();
}
bool isDiag(int i,int j){
}

void solve(){
	for(int i=0;i<m;i++){
		int a=i,b=i+1;
		if(i==m-1){
			b=0;
		}
		maxa=0;
		for(int j=0;j<m;j++){
			if(j!=a&&j!=b){
				area[i][j]=getarea(i,j,k);
				if(area[i][j]>maxa)
					maxa=area[i][j];
			}
		}
		dp[i][i+1]=maxa;
	}
	for(int d=1;d<m;d++){
		for(int i=0;i<m;i++){
			if(i+d>=m)continue;
			
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		solve();
	}
	return 0;
}
