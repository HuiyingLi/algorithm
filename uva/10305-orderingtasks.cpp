#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int G[101][101];
int f[101];
int m,n;
vector<int> order;

bool dfs(int k){
	f[k]=1;
	for(int i=1; i<n+1; i++){//find all outgoing edges
		if(G[k][i]!=0&&f[i]==0){
			if(!dfs(i))return false;
		}
	}
	order.push_back(k);
	return true;
}
bool topsort(){
	for(int i=1; i<n+1; i++){
		if(f[i]==0){
			dfs(i);
		}
	}
}

void print(){
	cout<<order[order.size()-1];
	for(int i=1; i< order.size();i++)
		cout<<" "<<order[order.size()-1-i];
	cout<<endl;
}
void init(){
	order.clear();
	for(int i=0;i<101;i++){
		f[i]=0;
		for(int j=0;j<101;j++)
			G[i][j]=0;
	}
}
int main(){
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		ss>>n;
		ss>>m;
		if(n==0&&m==0) break;
		for(int t=0;t<m;t++){
			getline(cin,line);
			stringstream sss(line);
			int i,j;
			sss>>i;
			sss>>j;
			G[i][j]=1;
		}
		topsort();
		print();
		init();
	}
	return 0;
}
