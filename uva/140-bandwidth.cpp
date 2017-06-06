#include<string.h>
#include<iostream>

using namespace std;

int G[27][27];
int vis[27];
string A;
int f[27];
int maxb;
int B[27];
int Bt[27];
string ans;
int n;
void init(){
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	A="";
	memset(B,-1,sizeof(B));
	maxb=-1;
	n=0;
	ans="";
}

void buildgraph(string line){
	int i=0;
	bool isV=true;
	int V;
	while(1){	
		if(i==line.length())break;
		if(isV&&line[i]<='Z'&&line[i]>='A'){
			V=line[i]-'A';
			if(!f[V]){
				f[V]=1;
				n++;
			}
		}else if(line[i]<='Z'&&line[i]>='A'){
			G[V][line[i]-'A']=1;
			if(!f[line[i]-'A']){
				f[line[i]-'A']=1;
				n++;
			}
		}else if(line[i]==':'){
			isV=false;
		}else if(line[i]==';'){
			isV=true;
		}
		i++;	
	}
}

void calcb_suf(string a){
	int l=a.length();
	memcpy(Bt,B,sizeof(B));
	for(int i=0; i<a.length()-1; i++){
		int v=a[i]-'A';
		if(G[v][a[l-1]-'A']||G[a[l-1]-'A'][v]){//if it is someone else's neighbor
			if(l-1-i>Bt[v])
				Bt[v]=l-1-i;
			if(l-1-i>Bt[a[l-1]-'A'])
				Bt[a[l-1]-'A']=l-1-i;
				
		}
			
	}
}

bool prune(string t){
	int mb=-1;
	if(maxb==-1)
		return false;
	for(int i=0;i<26;i++)
		if(Bt[i]>mb)mb=Bt[i];
	if(mb>=maxb)
		return true;
	int m=0;
	int u=t[t.length()-1]-'A';
	for(int i=0; i<26;i++){
		if((G[u][i]||G[i][u])&&!vis[i])//neighbors whose position haven't been determined.
			m++;
	}
	if(m>=maxb)
		return true;
	
	return false;
}
void dfs(int cur){
	if(cur==n){
		int mb=-1;
		for(int i=0; i<26; i++)	if(B[i]>mb) mb=B[i];
		if(maxb==-1||mb<maxb){
			maxb=mb;
			ans=A;
		}
		return;
	}
	for(int i=0; i<26; i++){
		if(f[i]&&!vis[i]){
			char V='A'+i;
			string t=A;
			A+=V;
			calcb_suf(A);
			if(!prune(A)){
				vis[V-'A']=1;
				int Btt[27];
				memcpy(Btt, B,sizeof(B));
				memcpy(B, Bt,sizeof(B));
				dfs(cur+1);
				vis[V-'A']=0;
				memcpy(B, Btt, sizeof(B));
			}
			A=t;
		}
	}
}
int main(){
	string line;
	while(1){
		getline(cin, line);
		if(line=="#") break;
		init();
		buildgraph(line);
		dfs(0);
		for(int i=0; i<ans.length();i++)
			cout<<ans[i]<<" ";
		cout<<"-> "<<maxb<<endl;
	}
	return 0;
}
