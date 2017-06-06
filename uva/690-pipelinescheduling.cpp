#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

int occ[5][201];
int n;
int rx[100];
int ry[100];
int rl;
int longseq;
int done;
int trace[1000];
int layer[1000];
int ans;
bool dfs(int d, int maxd){
	layer[d]=1;
//	if(done>=9&&d>=25&&maxd>=25)
//		cout<<endl;
	if(d==maxd){
	//	if(done==10)
	//		return true;
		layer[d]=0;
		return false;
	}
	if(d+(10-done)>maxd||10*longseq>maxd){
		layer[d]=0;
		return false;
	}
	bool occupied=false;
	for(int i=0;i<rl;i++){
		if(occ[rx[i]][ry[i]+d]){
			occupied=true;
			break;
		}	
	}

	if(!occupied){//start the job, or
		for(int i=0;i<rl;i++){
			occ[rx[i]][ry[i]+d]=1;
		}
		done++;
		if(done==10){
			ans=d;
			return true;
		}
		trace[d]=1;
		if(dfs(d+longseq,maxd))
			return true;
		for(int i=0;i<rl;i++){
			occ[rx[i]][ry[i]+d]=0;
		}
		done--;
		trace[d]=0;
	}
	
	if(dfs(d+1,maxd))//not start the job, skip the slot
		return true;
	layer[d]=0;	
	return false;
}
	
void ida(){
	int maxd=10*longseq;
	while(true){
//		cout<<"layer:"<<maxd<<endl;
//		if(maxd==27)
//			cout<<endl;
		if(dfs(0,maxd))
			break;
		maxd++;	
	}
	cout<<ans+n<<endl;
}
int main(){
	while(true){
		string line;
		getline(cin,line);
		stringstream ss(line);
		ss>>n;
		if(n==0)break;
		for(int i=0;i<5;i++){
			getline(cin,line);
			int lseq=0;
			int maxlseq=-1;
			for(int j=0;j<n;j++){
				if(line[j]=='X'){
					rx[rl]=i;
					ry[rl]=j;
					rl++;
					lseq++;
				}else{
					if(lseq>maxlseq)
						maxlseq=lseq;
					lseq=0;
				}
			}
			if(lseq>maxlseq)
				maxlseq=lseq;
			if(maxlseq>longseq)
				longseq=maxlseq;
		}
//		cout<<"longest seq:"<<longseq<<endl;
		ida();
		int c=0;
//		for(int i=0;i<1000&&c<10;i++){
//			if(trace[i]){
//				c++;
//			}
//			cout<<trace[i];
//		}	
//		cout<<endl;
//		cout<<"visited layers:"<<endl;
//		c=0;
//		for(int i=0;i<1000&c<=200;i++){
//			if(layer[i]){
//				c++;
//				cout<<i<<" ";
//			}
//		}
//		cout<<endl;
		done=0;
		memset(occ,0,sizeof(occ));
		memset(rx, 0, sizeof(rx));
		memset(ry, 0,sizeof(ry));
		rl=0;
		longseq=0;
		memset(trace,0,sizeof(trace));		
	}
	return 0;
}
