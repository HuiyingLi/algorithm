#include<iostream>
#include<sstream>
#include<queue>
#include<string.h>
#include<math.h>
using namespace std;

int w,h,n,maze[17][17],free[17][17];
int V[25000000];

class point{
	public:
	int v[3][2];
	int dist;
	point(){
		memset(v,-1,sizeof(v));
	}
	void print(){
		for(int i=0;i<3;i++)
			cout<<"("<<v[i][0]<<","<<v[i][1]<<")";
		cout<<endl;
	}
	bool operator == (const point & p) const{
		bool flag=true;
		for(int i=0;i<3;i++){
			if(v[i][0]!=p.v[i][0]||v[i][1]!=p.v[i][1])
				return false;
		}
		return true;
	}	
};

void print_maze(){
	for(int i=0; i<h; i++){
		for(int j=0;j<w;j++){
			if(free[i][j]==-1)
				cout<<"#";
			else if(free[i][j]==0)
				cout<<" ";
			else{
				char c='a'+free[i][j]-1;
				cout<<c;
			}
			
		}
		cout<<endl;
	}
}
vector<point> moves;
int f[17][17];
int m[5][2]={-1,0,0,0,1,0,0,-1,0,1};


bool isVisited(point p){
	long coor=0;
	for(int i=0;i<3;i++){
		if(p.v[i][0]==-1||p.v[i][1]==-1)
			continue;
		coor+=pow(17,n*2-1-2*i)*(p.v[i][0]);
		coor+=pow(17,n*2-2-2*i)*(p.v[i][1]);
	}
	if(coor==-1){
		cout<<"found the point!";
		p.print();
	}
	return V[coor];
}
void visit(point p){
	long coor=0;
	for(int i=0;i<3;i++){
		if(p.v[i][0]==-1||p.v[i][1]==-1)
			continue;
		coor+=pow(17,n*2-1-2*i)*(p.v[i][0]);
		coor+=pow(17,n*2-2-2*i)*(p.v[i][1]);
	}
	if(coor==-1){
		cout<<"found the point!";
		p.print();
	}
	V[coor]=1;
}
void expand(int vis[3], point p, int c){
	if(c==3){
		if(!isVisited(p)){
			moves.push_back(p);
			visit(p);
		}
		return;
	}
	for(int i=0; i<3; i++){
		if(!vis[i]){
			if(p.v[i][0]==-1&&p.v[i][1]==-1)
				expand(vis, p, c+1);
			for(int j=0;j<5;j++){
				point np;
				memcpy(np.v,p.v, sizeof(p.v));
				np.v[i][0]+=m[j][0];
				np.v[i][1]+=m[j][1];
				if(np.v[i][0]>=0&&np.v[i][0]<h&&np.v[i][1]>=0&&np.v[i][1]<w)
					if(free[np.v[i][0]][np.v[i][1]]==0||free[np.v[i][0]][np.v[i][1]]==i+1){//in map and available
					int tfp=free[p.v[i][0]][p.v[i][1]];
					int tfnp=free[np.v[i][0]][np.v[i][1]];
					free[p.v[i][0]][p.v[i][1]]=0;//move away
					free[np.v[i][0]][np.v[i][1]]=i+1;//set new position
					vis[i]=1;
					expand(vis,np,c+1);
					free[np.v[i][0]][np.v[i][1]]=tfnp;
					free[p.v[i][0]][p.v[i][1]]=tfp;
					vis[i]=0;
				}
			}
		}
	}
} 

int bfs(point start, point end){
	queue<point> q;
	q.push(start);
	visit(start);
	while(!q.empty()){
		point p=q.front();
		if(p==end)
			return p.dist;	
		q.pop();
		//set the points on the map
//		memcpy(free,maze,sizeof(maze));
		for(int i=0;i<3;i++)free[p.v[i][0]][p.v[i][1]]=i+1;
		//cout<<"distance:"<<p.dist<<endl;
		//print_maze();
		moves.clear();
		int vis[3];
		memset(vis,0,sizeof(vis));
		if(p.v[0][0]==2&&p.v[0][1]==12&&p.v[1][0]==2&&p.v[1][1]==13&&p.v[2][0]==2&&p.v[2][1]==2)
			cout<<"";
		expand(vis,p,0);
//		cout<<"From:";
//		p.print();
//		cout<<"Get:";
//		if(moves.size()==0)cout<<"None\n";
		for(int i=0;i<3;i++)free[p.v[i][0]][p.v[i][1]]=0;
		for(vector<point>::iterator it=moves.begin();it!=moves.end();it++){
			point np=*it;
			//np.print();
			np.dist=p.dist+1;
			q.push(np);
//			memcpy(free,maze,sizeof(maze));
//			for(int i=0;i<3;i++)free[np.v[i][0]][np.v[i][1]]=i+1;
			//print_maze();

		}
	}
	return -1;
}

int main(){
	while(1){
		string l;
		getline(cin, l);
		stringstream ss(l);
		ss>>w;ss>>h;ss>>n;
		if(w==0&&h==0&&n==0) break;
		point start, end;
		start.dist=0;
		for(int i=0;i<h;i++){
			string line;
			getline(cin,line);
			for(int j=0;j<w;j++){
				if(line[j]=='#'){
					maze[i][j]=-1;
					free[i][j]=-1;
				}
				else{ 
					maze[i][j]=0;
					free[i][j]=0;
				}
				if(line[j]>='a'&&line[j]<='z'){//init position
					start.v[line[j]-'a'][0]=i;
					start.v[line[j]-'a'][1]=j;
				}
				if(line[j]>='A'&&line[j]<='Z'){
					end.v[line[j]-'A'][0]=i;
					end.v[line[j]-'A'][1]=j;
				}
			}
		}
		
		memset(V,0,sizeof(V));
	/*	start.v[0][0]=2;				
		start.v[0][1]=12;
		start.v[1][0]=1;
		start.v[1][1]=13;
		start.v[2][0]=1;
		start.v[2][1]=2;
		isVisited(start);	
		*/
/*
		expand(vis,start,0);
		for(vector<point>::iterator it=moves.begin(); it!=moves.end();it++){
			point p=*it;
			p.print();
		}
*/
		cout<<bfs(start, end)<<endl;
	}
}
