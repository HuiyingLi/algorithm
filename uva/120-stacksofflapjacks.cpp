#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int N[30];
int pos[101];
int n;

void flip(int ind){
	int tmp[30];
	for(int i=0;i<=ind;i++){
		tmp[i]=N[i];
	}
	for(int i=0;i<=ind;i++){
		N[i]=tmp[ind-i];
		pos[tmp[ind-i]]=i;
	}
}

int compare(const void* a, const void* b){
	return (*(int*)a-*(int*)b);
}
void solve(){
	int sorted[30];
	memcpy(sorted, N, sizeof(N));
	qsort(sorted, n, sizeof(int),compare);
	for(int i=n-1;i>=0; i--){
		if(sorted[i]==N[i])
			continue;
		int curtgt=sorted[i];
		int curp=pos[curtgt];
		//flip to the top
		if(curp!=0){
			flip(curp);
			cout<<n-curp<<" ";
		}
		//flip to right position
		flip(i);
		cout<<n-i<<" ";
	}
}

int main(){
	string line;
	while(getline(cin, line)){
		int i=0, cnt=0;
		stringstream ss(line);
		while(i<line.length()){
			if(line[i]==' '){
				ss>>N[cnt];
				pos[N[cnt]]=cnt;
				cnt++;
			}
			i++;
		}
		ss>>N[cnt];
		pos[N[cnt]]=cnt;
		n=cnt+1;
		cout<<N[0];
		for(int k=1;k<n;k++)
			cout<<" "<<N[k];
		cout<<endl;
		solve();
		cout<<"0\n";
	}
	return 0;
}
