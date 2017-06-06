#include<iostream>
#include<stdio.h>
#include<unordered_set>
using namespace std;

unordered_set<long> vis;
int T;
long N[1000000];
int main(){
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		long mmax=0;
		long n;
		long L=0,R=0;
		scanf("%ld",&n);
		for(long i=0;i<n;i++){
			scanf("%ld",&N[i]);
		}
		while(R<n&&L<n){
			if(vis.find(N[R])==vis.end()){
				vis.insert(N[R]);
				R++;
				if(R-L>mmax)
					mmax=R-L;
			}
			else{
				while(R<n&&L<n){
					vis.erase(N[L]);
					L++;
					if(vis.find(N[R])==vis.end()){
						vis.insert(N[R]);
						R++;
						if(R-L>mmax)
							mmax=R-L;
						break;
					}
				}
			}
		}
		cout<<mmax<<endl;
		vis.clear();
	}
	return 0;
}
