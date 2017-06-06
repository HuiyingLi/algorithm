#include<iostream>
#include<queue>
#include<sstream>
#include<string.h>
#include<math.h>
using namespace std;

int maze[21][21];
//int vis[21][21];
int m,n,K;
int d[21][21][21];
class point{
public:
	int v[2];
	int dist;
	int turbo;
	point(int a, int b, int c, int d){v[0]=a;v[1]=b;dist=c;turbo=d;}
	point(){}
};
int bfs(){
	int S=0;
	queue<point> q;
	point start(1,1,0,0);
	q.push(start);
	//vis[1][1]=1;
	d[1][1][0]=0;
	while(!q.empty()){
		point p=q.front();
		if(p.v[0]==m&&p.v[1]==n)
			return p.dist;
		q.pop();
		for(int i=-1; i<2; i++){
			for(int j=-1;j<2;j++){
				if(fabs(i)==fabs(j)) continue;
				point np;
				memcpy(np.v, p.v, sizeof(p.v));
				np.v[0]+=i;
				np.v[1]+=j;
				if(np.v[0]<1||np.v[0]>m||np.v[1]<1||np.v[1]>n) continue;
				np.turbo=maze[np.v[0]][np.v[1]]==0?0:1+p.turbo;	
				if(np.turbo<=K){
					//vis[np.v[0]][np.v[1]]=1;
					np.dist=d[p.v[0]][p.v[1]][p.turbo]+1;
					if(d[np.v[0]][np.v[1]][np.turbo]==-1||np.dist<d[np.v[0]][np.v[1]][np.turbo]){
						d[np.v[0]][np.v[1]][np.turbo]=np.dist;
						q.push(np);
					}
				}	
			}
		}
	}
	return -1;
}

int main(){
	int C;
	string line;
	getline(cin, line);
	stringstream s(line);
	s>>C;
	for(int i=0;i<C;i++){
		getline(cin,line);
		stringstream ss(line);
		ss>>m;
		ss>>n;
		getline(cin,line);
		ss.str(std::string());
		ss.clear();
		ss<<line;
		ss>>K;
		for(int j=1;j<=m;j++){
			getline(cin,line);
			for(int k=0;k<n;k++){
				maze[j][k+1]=line[2*k]-'0';
			}
		}
		memset(d,-1,sizeof(d));
		cout<<bfs()<<endl;
	}
}
