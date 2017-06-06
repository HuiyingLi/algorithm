#include<iostream>
#include<sstream>
#include<string.h>
#include<vector>
using namespace std;
int G[26][26];
int f[26];
int d[26][2];
void init(){
	memset(G, 0, sizeof(G));
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
}

void dfs(int k){
	f[k]=0;
	for(int i=0; i<26; i++){
		if(G[k][i]!=0&&f[i]!=0){
			dfs(i);
		}
	}
}

int main(){
	int m,n;
	string line;
	getline(cin,line);
	stringstream ss(line);
	ss>>m;
	for(int i=0; i<m; i++){
		bool res=true;
		getline(cin, line);
		stringstream sss(line);
		sss>>n;
		//build the graph
		for(int j=0;j<n;j++){
			getline(cin, line);
			G[line[0]-'a'][line[line.length()-1]-'a']=G[line[line.length()-1]-'a'][line[0]-'a']=1;
			f[line[0]-'a']=1;
			f[line[line.length()-1]-'a']=1;
			d[line[0]-'a'][0]++;
			d[line[line.length()-1]-'a'][1]++;
		}
		//dfs: if the graph is connected
		for(int k=0;k<26;k++){
			if(f[k]!=0){
				dfs(k);
				break;
			}
		}
		for(int k=0;k<26;k++){
			if(f[k]!=0)
				res=false;
		}
		//check degrees of a graph
/**
		int starts=0;
		int ends=0;
		for(int k=0;k<26;k++){
			if(d[k][0]!=d[k][1]){
				if(d[k][0]==d[k][1]+1)starts++;
				else if(d[k][0]==d[k][1]-1)ends++;
				else r
			}
		}
**/
		bool res2=true;
		vector<int> sin;
		for(int k=0;k<26;k++){
			if(d[k][0]!=d[k][1])
				sin.push_back(k);
		}
		if(sin.size()>2)
			res2=false;
		else if(sin.size()<2)
			res2=true;
		else{
			if(!((d[sin[0]][1]-d[sin[0]][0]==1 && d[sin[1]][1]-d[sin[1]][0]==-1)||(d[sin[0]][1]-d[sin[0]][0]==-1&&d[sin[1]][1]-d[sin[1]][0]==1)))
				res2=false;
			else res2=true;
			
		}
		if(res&&res2)
			cout<<"Ordering is possible."<<endl;
		else
			cout<<"The door cannot be opened."<<endl;
		init();
	}
}
