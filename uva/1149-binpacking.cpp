#include<stdio.h>
#include<stdlib.h>
using namespace std;

int L[100010];
int compare(const void* a, const void* b){
	return (*(int*)b-*(int*)a);
}

void solve(int n, int m){
	qsort(L, n, sizeof(int), compare);
	int total=0;
	int ind=n-1;
	int i=0;
	while(i<=ind){
		if(i==ind){
			total++;
			break;
		}else{
			if(L[i]+L[ind]<=m){
				ind--;
			}
			i++;
			total++;
		}
	}
	printf("%d\n", total);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		if(t)
			printf("\n");
		int n;
		int m;
		scanf("%d",&n);
		scanf("%d",&m);
		for(int i=0;i<n;i++){
			scanf("%d",&L[i]);
		}
	//	qsort(L,n,sizeof(int),compare);
//		bi_search(61,n);
		solve(n,m);
	}
	return 0;
}
