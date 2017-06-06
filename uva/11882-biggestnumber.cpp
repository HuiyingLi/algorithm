#include<iostream>
#include<string.h>
#include<sstream>
#include<unordered_set>
#include<queue>
using namespace std;

char L[31];
unordered_set<int> G[31];
int vis[31];
char maze[15][15];
int coor[15][15];
int R,C;
int n;
int dr[4]={-1,0,0,1};
int dc[4]={0,-1,1,0};
string trace;
string ans;

int connect(int node){
	int mvis[31];
	memcpy(mvis,vis,sizeof(vis));
	queue<int> q;
	q.push(node);
	int cnt=0;
	while(!q.empty()){
		int nn=q.front();
		q.pop();
		for(unordered_set<int>::iterator it=G[nn].begin();it!=G[nn].end();it++){
			int t=*it;
			if(mvis[t])
				continue;
			q.push(t);
			mvis[t]=1;
			cnt++;	
		}
	}
	return cnt;
}

void dfs(int d,int node){
//	if(trace=="9678")
//		cout<<endl;
	int cl=connect(node);
	if(cl+trace.length()<ans.length())
		return;
	if(cl+trace.length()==ans.length()){
		if(trace<ans.substr(0,trace.length()))
			return;
	}
	bool found=false;
	for(unordered_set<int>::iterator it=G[node].begin();it!=G[node].end(); it++){
		int nn=*it;
		if(vis[nn])
			continue;
		found=true;
		vis[nn]=1;
		string ttr=trace;
		trace+=L[nn];
		dfs(d+1,nn);
		vis[nn]=0;
		trace=ttr;
	}
	if(!found){
//		cout<<trace<<endl;
//		if(trace=="791452384")
//			cout<<endl;
		if(trace.length()>ans.length()||(trace.length()==ans.length()&&trace>ans)){
			ans=trace;
		}
	}
}

void m2G(){
	int cnt=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(maze[i][j]!='#'){
				L[coor[i][j]]=maze[i][j];
//				cout<<coor[i][j]<<"("<<L[coor[i][j]]<<"):"<<endl;
				for(int k=0;k<4;k++){
					int nr=i+dr[k];
					int nc=j+dc[k];
					if(nr>=0&&nc>=0&&nr<R&&nc<C&&maze[nr][nc]!='#'){
//						cout<<"insert:"<<coor[nr][nc]<<endl;
						G[coor[i][j]].insert(coor[nr][nc]);
						G[coor[nr][nc]].insert(coor[i][j]);
					}
				}
			}
		}
	}
}
void printG(){
	for(int i=0;i<n;i++){
		for(unordered_set<int>::iterator it=G[i].begin(); it!=G[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
}
int main(){
	string line;
	while(true){
		getline(cin, line);
		stringstream ss(line);
		ss>>R;
		ss>>C;
		if(R==0&&C==0)
			break;
		int cnt=0;
		memset(maze,'\0',sizeof(maze));
		memset(coor,-1,sizeof(coor));
		for(int i=0;i<R;i++){
			getline(cin,line);
			for(int j=0;j<C;j++){
				maze[i][j]=line[j];
				if(line[j]!='#'){
					coor[i][j]=cnt;
					cnt++;
				}
			}
		}
		n=cnt+1;
		for(int i=0;i<31;i++)G[i].clear();
		m2G();
//		printG();
		ans="";
		for(int i=9;i>0;i--){
			for(int j=0;j<n;j++){
				if(L[j]=='0'+i){
					memset(vis,0,sizeof(vis));
					vis[j]=1;
					trace=L[j];
					dfs(0,j);
				}
			}
			if(ans.length()==n)
				break;
		}
		cout<<ans<<endl;
	}
}
