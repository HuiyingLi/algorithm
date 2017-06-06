#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<sstream>
using namespace std;
int n;
vector<int> tree[210];
int val[210];
int f[210];
map<string, int> ids;
bool multi;

int dfs(int u){
	if(tree[u].empty()){
		f[u]=0;
		return 1;
	}
	int res=0,sons=0,gss=0;
	int fs=0, fgs=0;
	for(int i=0;i<tree[u].size();i++){
		int son=tree[u][i];
		if(val[son]==-1){
			val[son]=dfs(son);
		}
		sons+=val[son];
		if(f[son])
			fs=1;
		for(int j=0;j<tree[son].size();j++){
			int gs=tree[son][j];
			if(val[gs]==-1)
				val[gs]=dfs(gs);
			if(f[gs])
				fgs=1;
			gss+=val[gs];
		}
	}
	if(sons==gss+1){
		f[u]=1;
		res=sons;
	}else if(sons>gss+1){
		res=sons;
		f[u]=fs;
	}else{
		res=gss+1;
		f[u]=fgs;
	}
	return res;
}
int main(){
	string l;
	getline(cin,l);
	stringstream ss(l);
	ss>>n;
	while(n){
		string line;
		getline(cin,line);
		ids[line]=0;
		vector<string> n1s;
		vector<string> n2s;
		for(int i=0;i<n-1;i++){
			getline(cin,line);
			int k;
			for(k=0;k<line.length()&&line[k]!=' ';k++){}
			string n1=line.substr(0,k);
			string n2=line.substr(k+1,line.length()-k-1);
			ids[n1]=i+1;
			n1s.push_back(n1);
			n2s.push_back(n2);
		}
		for(int i=0;i<n1s.size();i++){
			int sid=ids.find(n1s[i])->second;
			int pid=ids.find(n2s[i])->second;
			tree[pid].push_back(sid);
		}
		memset(val,-1,sizeof(val));
		memset(f,0,sizeof(f));
		cout<<dfs(0)<<" ";
		if(f[0])cout<<"No\n";else cout<<"Yes\n";
		for(int i=0;i<n+1;i++)
			tree[i].clear();
		ids.clear();
		getline(cin,l);
		stringstream sss(l);
		sss>>n;
	}
	return 0;
}
