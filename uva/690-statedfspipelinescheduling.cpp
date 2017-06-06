#include<iostream>
#include<sstream>
#include<string.h>
#include<unordered_map>

using namespace std;

int occ[5][201];
int n;
int rx[100];
int ry[100];
int rl;
int longseq;
int done;
string trace;
int layer[1000];
int ans;
unordered_map<string, int> states;
int legal[20];

void initjudge(){
	int vis[5][41];
	memset(vis,0,sizeof(vis));
	legal[0]=1;
	for(int i=0;i<rl;i++){
		vis[rx[i]][ry[i]]=1;
	}
	for(int i=1;i<n;i++){
		bool colli=false;
		for(int j=0;j<rl;j++){
			if(vis[rx[j]][ry[j]+i]){
				colli=true;
				break;
			}
				
		}
		if(colli)
			legal[i]=0;
		else
			legal[i]=1;
	}
}

bool judge(string trace){
	//find the last '1'
	if(trace.length()==0)
		return true;
	int i=trace.length()-1;
	while(i>0&&trace[i]!='1') i--;
	if(trace.length()-i>n)//larger than a cycle
		return false;
	if(trace.length()-i==n)//right after a full cycle
		return true;
	if(legal[trace.length()-i])
		return true;
	return false;
}
void dfs(int d,int maxd){
	layer[d]=1;
	if(done>=10)
		return;
//	if(done>=9&&d>=25&&maxd>=25)
//		cout<<endl;
//	if(d==maxd){
	//	if(done==10)
	//		return true;
//		layer[d]=0;
//		return false;
//	}
	if(d+(10-done)>ans||10*longseq>ans){
		layer[d]=0;
		return;
	}
	if(judge(trace)){
		bool occupied=false;
		//consult state map
	//	string ntrace=trace+"1";
	//	if(states.find(ntrace)!=states.end()){
	//		int res=(*states.find(ntrace)).second;
	//		if(res)
	//			occupied=true;
	//	}else{
		
		for(int i=0;i<rl;i++){
			if(occ[rx[i]][ry[i]+d]){
				occupied=true;
				break;
			}	
		}
	//		if(occupied){
	//			states.insert({ntrace,1});
	//		}else{
	//			states.insert({ntrace,0});
	//		}
	//	}

		if(!occupied){//start the job
			for(int i=0;i<rl;i++){
				occ[rx[i]][ry[i]+d]=1;
			}
			done++;
			if(done==10){
				if(d<ans)
					ans=d;
			}
			string tmpt=trace;
			trace+="1";
			for(int m=0;m<longseq-1;m++)
				trace+="0";
			dfs(d+longseq,maxd);
			for(int i=0;i<rl;i++){
				occ[rx[i]][ry[i]+d]=0;
			}
			done--;
			trace=tmpt;
		}
	}
	string tmpt=trace;
	trace+="0";
	dfs(d+1,maxd);//not start the job, skip the slot
	trace=tmpt;
	layer[d]=0;	
	return;
}
/*	
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
*/
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
//		ida();
		initjudge();
		ans=10000;
		dfs(0,10*n);
		cout<<ans+n<<endl;
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
	//	memset(trace,0,sizeof(trace));
		trace="";
		states.clear();
	}
	return 0;
}
