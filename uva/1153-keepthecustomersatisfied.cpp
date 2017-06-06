#include<iostream>
#include<sstream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
class job{
	public:
	int q,d;
	job(){}
	job(int qq, int dd):q(qq),d(dd){}
	bool operator < (const job& j) const{
		return this->d<j.d;
	}
};
int T;
long n;
job jobs[800010];
//int vis[800010];

void solve(){
	long C=0;
//	memset(vis,0,sizeof(ac));
	sort(jobs, jobs+n);
	int start=0;
	int prevq=-1;
	for(int i=0;i<n;i++){
		if(jobs[i].q<prevq){
			start+=jobs[i].q;
			C++;
			continue;
		}
		//assume accept this one
		int tmp=start+jobs[i].q;
		if(tmp>jobs[i].d) continue;
		int ac=true;
		for(int j=i+1; j<n;j++){
			//previous accepted ones
			if(jobs[j].q<prevq){
				tmp+=jobs[j].q;
				if(tmp>jobs[j].d){
					ac=false;
					break;
				}
			}else{
				if(jobs[j].q<jobs[i].q){//have to accept
					tmp+=jobs[j].q;
					if(tmp>jobs[j].d){
						ac=false;
						break;
					}
				}
			}
		}
		if(ac){
			prevq=jobs[i].q;
			C++;
			start+=jobs[i].q;
		}
	}
	cout<<C;
}
int main(){
	scanf("%d",&T);
	int f=0;
	while(T--){
		if(!f){
			f=1;
		}else{
			cout<<endl;
		}
		scanf("%ld",&n);
		for(long i=0;i<n;i++){
			scanf("%d%d",&jobs[i].q,&jobs[i].d);
		}
		solve();
		if(T)
			cout<<endl;
	}
	return 0;
}
