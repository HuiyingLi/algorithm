#include<iostream>
#include<sstream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int mmin;
int nset;
int finished;
int sticks[2000];
int vis[2000];
int n;
int curstick;
int sum;
bool wayToSort(int i, int j){return i>j;}

bool dfs(int setsum, int cur){
	if(finished==nset)
		return true;
	for(int i=cur;i < n; i++){
		if(vis[i]||(i>0&&sticks[i]==sticks[i-1]&&!vis[i-1]))
			continue;
		if(curstick+sticks[i]==setsum){
			vis[i]=1;
			finished++;
			int tcur=curstick;
			curstick=0;
			if(dfs(setsum,0))
				return true;
			vis[i]=0;
			finished--;
			curstick=tcur;
			return false;
		}else if(curstick+sticks[i]<setsum){
			vis[i]=1;
			int tcur=curstick;
			curstick+=sticks[i];
			if(dfs(setsum, i+1))
				return true;
			vis[i]=0;
			curstick=tcur;
			if(curstick==0)
				return false;
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
		finished=0;
		if(dfs(maxd,0)){
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
		finished=0;
		memset(sticks,0,sizeof(sticks));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			int l;
			ss1>>l;
			sticks[i]=l;
			sum+=l;
			if(l>mmin)
				mmin=l;
		}
		sort(sticks, sticks+n,wayToSort);
		ida();
	}
	return 0;
}
