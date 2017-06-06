#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
long M=400000;
int N[400000+1];
int step[400000+1];
void solve(int n){
	int s=M-n;
	int cnt=0;
	memset(step,0,sizeof(step));
	while(true){
		bool done=true;
		for(int i=0;i<n;i++){
			if(N[s+i]!=i+1){
				done=false;
				break;
			}
		}
		if(done)
				break;
		if(N[s]>N[s+1]&&(N[s+1]!=1||N[s]!=n)){
			int tmp=N[s+1];
			N[s+1]=N[s];
			N[s]=tmp;
			step[cnt++]=1;
		}else{
			N[--s]=N[s+n];
			step[cnt++]=2;
		}
	}
	for(int i=cnt-1;i>=0;i--)
		cout<<step[i];
	cout<<endl;
}
int main(){
	string line;
	while(true){
		getline(cin, line);
		stringstream ss(line);
		int n;
		ss>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++)
			ss>>N[M-n+i];
		solve(n);
	}
	return 0;
}
