#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;
long obj[138];
int cnt[(1<<11)+10][(1<<11)+10];
int m,n;

void count(){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<m);j++){
			long a=obj[i] & j;
			cnt[j][a]++;
		}
	}
}
void solve(){
}

int main(){
	string line;
	getline(cin, line);
	stringstream s(line);
	s>>m>>n;
	while(m!=0&&n!=0){
		for(int i=0;i<n;i++){
			getline(cin,line);
			long o=0;
			for(int j=0;j<m;j++){
				if(line[j]==1){
					o+=(1<<m-j-1);
				}
			}
			obj[i]=o;	
		}
		solve();
		getline(cin,line);
		stringstream ss(line);
		ss>>m>>n;
	}
	return 0;
}
