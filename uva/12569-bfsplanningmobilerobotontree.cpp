#include<iostream>
#include<sstream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int T;
int n,m,s,t;
vector<int> Tree[16];
int vis[15][1<<15];

class point{
	public:
	int s;
	int obs;
	int d;
	string path;
	bool operator <(const point &a)const{
		return d>a.d;
	}
};
bool bfs(point start){
	priority_queue<point> q;
	if(start.s==t){
		cout<<"0"<<endl;
		return true;
	}
	q.push(start);
	vis[start.s][start.obs]=1;
	while(!q.empty()){
		point p=q.top();
		q.pop();
		if(p.s==t){
			cout<<p.d<<endl;
			for(int k=0;k<p.path.length();k+=2){
				int ff=p.path[k]-'A';
				int tt=p.path[k+1]-'A';
				cout<<ff+1<<" "<<tt+1<<endl;
			}
			return true;
		}
		for(int i=0;i<n;i++){
			if(!(p.obs&(1<<i))) continue;
			for(int k=0; k<Tree[i].size();k++){
				int ns=Tree[i][k];
				if(!(ns!=p.s&&!(p.obs&(1<<ns)))) continue;
				int nobs=p.obs^(1<<i);
				nobs|=(1<<ns);
				if(!vis[p.s][nobs]){
					vis[p.s][nobs]=1;
					point np;
					np.s=p.s;
					np.d=p.d+1;
					np.obs=nobs;
					np.path=p.path+(char)('A'+i)+(char)('A'+ns);
					q.push(np);
				}
			}
		}
		for(int k=0;k<Tree[p.s].size();k++){
			int ns=Tree[p.s][k];
			if(p.obs&(1<<ns)) continue;
			if(!vis[ns][p.obs]){
				point np;
				np.s=ns;
				np.d=p.d+1;
				np.obs=p.obs;
				np.path=p.path+(char)('A'+p.s)+(char)('A'+ns);
				q.push(np);
				vis[np.s][np.obs]=1;
			}
		}	
		
	}
	return false;
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
		s--;t--;
		getline(cin,line);
		stringstream ss1(line);
		point start;
		start.s=s;
		start.d=0;
		start.obs=0;
		for(int i=0;i<m;i++){
			int a;
			ss1>>a;
			start.obs|=(1<<(a-1));
		}
		for(int i=0;i<n-1;i++){
			getline(cin, line);
			stringstream ss2(line);
			int a,b;
			ss2>>a>>b;
			Tree[a-1].push_back(b-1);
			Tree[b-1].push_back(a-1);
		}
//		connect();
		cout<<"Case "<<C+1<<": ";
		if(!bfs(start))
			cout<<"-1"<<endl;
		cout<<endl;
		for(int i=0;i<16;i++)
			Tree[i].clear();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
