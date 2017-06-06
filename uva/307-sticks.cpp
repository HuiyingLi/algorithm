#include<iostream>
#include<sstream>
#include<string.h>
#include<string>
using namespace std;

//int sticks[10000];
long sticks[51];
int n;
long sum;
int mmin;
int nset;
long ssum[10000];
int finished;
bool dfs(int setsum){
	if(n==0){
		if(finished=nset)
			return true;
	}
	int cmax=-1;
	for(int i=mmin;i>0;i--){
		for(int k=0;k<sticks[i];k++){
			if(cmax==-1){
				cmax=i;
			}
			bool selected=false;
			for(int j=0;j<nset;j++){
				if(ssum[j]+i<=setsum){
					selected=true;
					ssum[j]+=i;
					int tf=finished;
					bool doneone=false;
					if(ssum[j]==setsum){
						doneone=true;
						finished++;
					}
					sticks[i]--;
					n--;
					if(dfs(setsum))
						return true;
					ssum[j]-=i;
					sticks[i]++;
					n++;
					finished=tf;
					if((ssum[j]==0&&i==cmax)||doneone) return false;
				}
			}
			if(!selected)break;
		}
	}
	return false;
}
void ida(){
	int maxd=mmin-1;
	bool found=false;
	while(maxd<=sum/2){
		maxd++;
		if(sum%maxd!=0)
			continue;
		nset=sum/maxd;
		memset(ssum,0,sizeof(ssum));
		finished=0;
		if(dfs(maxd)){
			cout<<maxd<<endl;
			found=true;
			break;
		}
	}
	if(!found)
		cout<<sum<<endl;
}


int main(){
	string line;
	while(true){
		getline(cin, line);
		if(line=="0")
			break;
		stringstream ss(line);
		ss>>n;
		getline(cin,line);
		stringstream ss1(line);
		sum=0;
		mmin=-1;
		memset(sticks,0,sizeof(sticks));
		for(int i=0;i<n;i++){
			int l;
			ss1>>l;
			sticks[l]++;
			sum+=l;
			if(l>mmin)
				mmin=l;
		}
		ida();
	}
	return 0;
}
