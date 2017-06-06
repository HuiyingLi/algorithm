#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

int ans[100];
int vis[100];
int n;
/**
bool is_prime(int n){
	bool flag=true;
	if(n==2)return true;
	if(n==1)return false;
	for(int i=2;i<=n/2;i++)
		if(n%i==0)
			flag=false;
	return flag;
}
**/
int isp[50] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
				0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 
				0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
				0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 
				0, 1, 0, 1, 0, 0, 0, 1, 0, 0 };

void search(int cur){
	if(cur==n&&isp[ans[0]+ans[n-1]]){
		cout<<ans[0];
		for(int i=1;i<n;i++)cout<<" "<<ans[i];
		cout<<endl;
		return;
	}
	for(int i=2;i<=n;i++){
		if(vis[i]==0&&isp[ans[cur-1]+i]){
			ans[cur]=i;
			vis[i]=1;
			search(cur+1);
			vis[i]=0;
		}
	}
}

int main(){
	int C=0;
	string line;
	while(cin>>n){
		if(C)
			cout<<endl;
		cout<<"Case "<<++C<<":\n";
		memset(vis,0,sizeof(vis));
		ans[0]=1;
		search(1);
	}
	return 0;
}
