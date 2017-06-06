#include<iostream>
#include<sstream>
#include<unordered_set>
#include<string.h>
#include<vector>
using namespace std;

int T;
int n,m,s,t;
unordered_set<int> Tree[16];
int obs[16];
int stones[16];
int src[30];
int dest[30];
int nmove;
int vis[16];
int conn[16];
void connect(){
	conn[t]=0;
	vector<int> q;
	vector<int> nq;
	q.push_back(t);
	int lvis[16];
	int l=0;
	memset(lvis,0,sizeof(lvis));
	lvis[t]=1;
	while(!q.empty()){
		l++;
		for(int i=0;i<q.size();i++){
			for(unordered_set<int>::iterator it=Tree[q[i]].begin();it!=Tree[q[i]].end();it++){
				if(lvis[*it]) continue;
				nq.push_back(*it);
				conn[*it]=l;
				lvis[*it]=1;
			}
		}
		q=nq;
		nq.clear();
	}
}
bool dfs(int d, int prev, int maxd){
	if(s==t)
		return true;
	if(d+conn[s]-1>=maxd)
		return false;
	int tvis[16];
	//move stone
	for(int i=0;i<m;i++){
		int stone=stones[i];//the stone being moved
		if(stone!=prev){
			memcpy(tvis,vis,sizeof(vis));
			memset(vis,0,sizeof(vis));
		}
		vis[stone]=1;
		for(unordered_set<int>::iterator it=Tree[stone].begin();it!=Tree[stone].end();it++){
			int ns=*it;
			if(!obs[ns]&&s!=ns&&!vis[ns]){
				stones[i]=ns;
				obs[stone]=0;
				obs[ns]=1;
				src[nmove]=stone;
				dest[nmove]=ns;
				nmove++;
				if(dfs(d+1,ns,maxd))
					return true;
				stones[i]=stone;
				obs[stone]=1;
				obs[ns]=0;
				nmove--;
			}
		}
		if(stone!=prev)	
			memcpy(vis,tvis,sizeof(vis));
	}
	//move robot
	if(s!=prev){
		memcpy(tvis,vis,sizeof(vis));
		memset(vis,0,sizeof(vis));
	}
	vis[s]=1;
	for(unordered_set<int>::iterator it=Tree[s].begin();it!=Tree[s].end();it++){
		int ns=*it;
		if(!obs[ns]&&!vis[ns]){
			src[nmove]=s;
			dest[nmove]=ns;
			nmove++;
			int ts=s;
			s=ns;
			if(dfs(d+1,ns,maxd))
				return true;
			nmove--;
			s=ts;
		}
	}
	if(s!=prev)
		memcpy(vis,tvis,sizeof(vis));
	return false;
}

void ida(){
	bool found=false;
	for(int maxd=0;	maxd<=30;maxd++){
//		cout<<"maxd:"<<maxd<<endl;
		memset(src,0,sizeof(src));
		memset(dest,0,sizeof(dest));
		nmove=0;
		memset(vis,0,sizeof(vis));
		if(dfs(0,0,maxd)){
			found=true;
			cout<<maxd<<endl;
			for(int i=0;i<nmove;i++){
				cout<<src[i]<<" "<<dest[i]<<endl;
			}
			break;
		}
	}
	if(!found)
		cout<<"-1"<<endl;
}
int main(){
	string line;
	getline(cin,line);
	stringstream ss0(line);
	ss0>>T;
	for(int C=0;C<T;C++){
		getline(cin,line);
		stringstream ss(line);
		ss>>n>>m>>s>>t;
		getline(cin,line);
		stringstream ss1(line);
		for(int i=0;i<m;i++){
			int a;
			ss1>>a;
			obs[a]=1;
			stones[i]=a;
		}
		for(int i=0;i<n-1;i++){
			getline(cin, line);
			stringstream ss2(line);
			int a,b;
			ss2>>a>>b;
			Tree[a].insert(b);
			Tree[b].insert(a);
		}
		connect();
		cout<<"Case "<<C+1<<": ";
		ida();
		cout<<endl;
		memset(obs,0,sizeof(obs));
		for(int i=0;i<16;i++)
			Tree[i].clear();
		memset(src,0,sizeof(src));
		memset(dest,0,sizeof(dest));
		memset(conn,0,sizeof(dest));
		nmove=0;		
	}
}
