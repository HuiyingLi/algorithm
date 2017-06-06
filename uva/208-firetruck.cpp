#include<iostream>
#include<sstream>
#include<string.h>
#include<set>
using namespace std;
int K;
int G[21][21];
int C;
int route[30];
int vis[21];

bool isconnected(){
	set<int> reachable;
	set<int> visited;
	reachable.insert(1);
	visited.insert(1);
	while(reachable.size()!=0){
		if(reachable.find(K)!=reachable.end())
			return true;
		set<int> t;
		for(set<int>::iterator it=reachable.begin();it!=reachable.end();it++){
			int s=*it;
			for(int i=0;i<21;i++){
				if(G[s][i]&&visited.find(i)==visited.end()){
					t.insert(i);
					visited.insert(i);
				}
			}
		}
		reachable=t;
	}
	return false;
}
void dfs(int s, int d){
	if(s==K){
		cout<<"1";
		for(int i=0;i<d;i++)
			cout<<" "<<route[i];
		C++;
		cout<<endl;
		return;
	}
	for(int i=1; i<21; i++){
		if(G[s][i]==1&&!vis[i]){
			route[d]=i;
			vis[i]=1;
			G[s][i]=-1;
			G[i][s]=-1;
			dfs(i,d+1);
			G[s][i]=1;
			G[i][s]=1;
			vis[i]=0;
		}
	}
}
int main(){
	string line;
	int i=0;
	int Case=0;
	while(getline(cin, line)){
		if(i==0){
			stringstream ss(line);
			ss>>K;
			i++;
		}else{
			int m, n;
			stringstream ss(line);
			ss>>m>>n;
			if(m==0&&n==0){
				Case++;
				cout<<"CASE "<<Case<<":"<<endl;
				i=0;
				if(!isconnected()){
					cout<<"There are 0 routes from the firestation to streetcorner "<< K<<".\n";
				}else{
					vis[1]=1;
					dfs(1,0);
					cout<<"There are "<<C<<" routes from the firestation to streetcorner "<< K<<".\n";
				}
				C=0;
				memset(G,0,sizeof(G));
				memset(vis,0,sizeof(vis));
				memset(route,0,sizeof(route));
				continue;	
			}
			G[m][n]=1;
			G[n][m]=1;
		}
	}
}
