#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_set>
#include<functional>
#include<math.h>
using namespace std;
int L;
int n;
int C;
int ox[51];
int oy[51];
char route[21];
char dir[4]={'e','n','s','w'};
int dirx[4]={1,0,0,-1};
int diry[4]={0,1,-1,0};

class point{
	public:
	int x;
	int y;
	point(int xx,int yy):x(xx),y(yy){}
	bool operator == (point const& p) const{
		if(x==p.x&&y==p.y)
			return true;
		return false;
	}
};

class myHash{
	public:
	size_t operator()(const point &p) const{
		int hs=100*p.x+p.y;
		return hs;
	}
};
unordered_set<point, myHash> vis;
/**
void print_route(int* r, int l){
	int x=0;
	int y=0;
	for(int i=0;i<l;i++){
		
	}
}
**/
bool isreachable(int px, int py, int x, int y, int dir){
	if(dir==1||dir==2){
		int xx=px;
		for(int i=0;i<n;i++){
			if(ox[i]==xx){
				if(!((py>y&&(oy[i]>py||oy[i]<y))||(y>py&&(oy[i]>y||oy[i]<py))))
					return false;
			}
		}
		return true;
	}
	if(dir==0||dir==3){
		int yy=py;
		for(int i=0;i<n;i++){
			if(oy[i]==yy){
				if(!((px>x&&(ox[i]>px||ox[i]<x))||(x>px&&(ox[i]>x||ox[i]<px))))
					return false;
			}
		}
		return true;
	}
}

bool prune(int l, int x, int y){
	int cx=0;
	int cy=0;
	int k=0;
	for(int i=L;i>l;i--){
		if(k==0){
			cx+=i;
			k=1;
		}else{
			cy+=i;
			k=0;
		}
	}
	if((fabs(x)<=cx&&fabs(y)<=cy)||(fabs(y)<=cx&&fabs(x)<=cy))
		return false;
	else
		return true;
}
void dfs(int l, int prevdir, int px, int py){
	if(l==L+1){
		if(px==0&&py==0){
			for(int i=1;i<l;i++)
				cout<<route[i];
			cout<<endl;
			C++;
		}
		return;
	}
	vector<int> pd;
	if(prevdir==0||prevdir==3){
		pd.push_back(1);
		pd.push_back(2);
	}
	if(prevdir==2||prevdir==1){
		pd.push_back(0);
		pd.push_back(3);
	}
	if(prevdir==-1){
		pd.push_back(0);
		pd.push_back(1);
		pd.push_back(2);
		pd.push_back(3);
	}
	for(vector<int>::iterator it=pd.begin();it!=pd.end();it++){
		int d=*it;
		int x=px+l*dirx[d];
		int y=py+l*diry[d];
		point p(x,y);
		if(isreachable(px,py,x,y,d)&&!prune(l,x,y)&&vis.find(p)==vis.end()){
			route[l]=dir[d];
			vis.insert(p);
			dfs(l+1,d,x,y);
			vis.erase(p);
		}
	}
}

int main(){
	int N;
	string line;
	getline(cin,line);
	stringstream ss(line);
	ss>>N;
	for(int c=0;c<N;c++){
		getline(cin, line);
		stringstream ss0(line);
		ss0>>L;
		getline(cin,line);
		stringstream ss1(line);
		ss1>>n;
		for(int i=0;i<n;i++){
			getline(cin,line);
			stringstream ss2(line);
			int x,y;
			ss2>>ox[i]>>oy[i];
		}
		if(L>16){
			cout<<"Found 0 golygon(s).\n\n";
			continue;
		}
		dfs(1,-1, 0,0);
		cout<<"Found "<<C<<" golygon(s).\n";
		cout<<endl;
		C=0;
	}
	return 0;
}
