#include<iostream>
#include<sstream>
#include<string.h>
#include<set>
#include<unordered_set>
//#include<string>
#include<functional>
using namespace std;

int N,W,H;
int map[10][10];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int C=0;
int mx, my, minx,miny;

class block{
	public:
	int w;
	int h;
	int shape[10][10];
	block(int ww, int hh){
		this->w=ww;
		this->h=hh;
		memset(shape, 0, sizeof(shape));
	}
	bool operator == (block const& b) const{
		if(h!=b.h) return false;
		if(w!=b.w) return false;
		for(int i=0;i<=h;i++){
			for(int j=0;j<=w;j++){
				if(shape[i][j]!=b.shape[i][j])
					return false;
			}
		}
		return true;
	
	}
/**
	bool operator < (const block& b) const{
		if(h!=b.h) return h<b.h;
		if(w!=b.w) return w<b.w;
		for(int i=0;i<=h;i++){
			for(int j=0;j<=w;j++){
				if(shape[i][j]!=b.shape[i][j])
					return shape[i][j]<b.shape[i][j];
			}
		}
		return false;
	}
**/
};
class myHash{
	public:
	size_t operator()(const block &b) const{
		string hs;
		hs+=('0'+b.h)+('0'+b.w);
		for(int i=0;i<=b.h;i++){
			for(int j=0;j<=b.w;j++){
				hs+=('0'+b.shape[i][j]);
			}
		}
		std::hash<string> hsfn;
		return hsfn(hs);
	}
};

unordered_set<block, myHash> vis;
void pblock(block b){
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(b.shape[i][j]==1)
				cout<<"@";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<"-----"<<endl;
}

block makeud(block ori){
	block nb(ori.w,ori.h);
	for(int i=ori.h; i>=0;i--){
		for(int j=0;j<=ori.w;j++){
			nb.shape[ori.h-i][j]=ori.shape[i][j];
		}
	}
	return nb;
}
block makelr(block ori){
	block nb(ori.w,ori.h);
	for(int i=0;i<=ori.h;i++){
		for(int j=ori.w;j>=0;j--){
			nb.shape[i][ori.w-j]=ori.shape[i][j];
		}
	}
	return nb;
}

bool visit(block ori){
	if(vis.find(ori)==vis.end()){
		//if it goes 90 degree
		if(mx<W&&my<H){
			block bf(mx,my);
			for(int i=0;i<=ori.h;i++){
				for(int j=0;j<=ori.w;j++){
					bf.shape[j][i]=ori.shape[i][j];	
				}
			}
			vis.insert(bf);
			block bf1=makelr(bf);
			vis.insert(bf1);
			vis.insert(makeud(bf));
			vis.insert(makeud(bf1));
		}
		block b1=makelr(ori);
		vis.insert(ori);
		vis.insert(b1);
		vis.insert(makeud(ori));
		vis.insert(makeud(b1));
		return false;
	}
	return true;
}

void dfs(int d, int x, int y){
	if(d==N-1){
//		if(map[0][1]&&map[1][0]==1&&map[1][1]&&map[1][2]==1&&map[2][1]==1)
//			cout<<" ";
		if(miny!=0)
			return;
		block b(my,mx);
		memcpy(b.shape, map, sizeof(map));
//		pblock(b);
//		if(map[0][0]==1&&map[1][0]==1&&map[2][0]==1&&map[2][1]==1&&map[3][1]==1)
//			cout<<" ";
		if(!visit(b)){
			C++;
		}
		return;
	}
	for(int j=0;j<=mx; j++){
		for(int k=0;k<=my;k++){
			if(map[j][k]==1){
				x=j;y=k;
				for(int i=0;i<4;i++){
					int nx=x+dir[i][0];
					int ny=y+dir[i][1];
					if(nx>=0&&ny>=0&&nx<H&&ny<W&&map[nx][ny]==0){
						map[nx][ny]=1;
						int tx=mx;
						int ty=my;
						int tminy=miny;
						if(nx>mx) mx=nx;
						if(ny>my) my=ny;
						if(ny<miny) miny=ny;
						dfs(d+1,nx,ny);
						map[nx][ny]=0;
						mx=tx;
						my=ty;
						miny=tminy;
					}
				}
			}
		}
	}
}

int main(){
	string line;
	while(getline(cin, line)){
		stringstream ss(line);
		ss>>N>>W>>H;
		memset(map,0,sizeof(map));
		vis.clear();
		C=0;
	//	map[0][0]=1;
		for(int i=0;i<W/2+1;i++){
			memset(map,0,sizeof(map));
			map[0][i]=1;
			miny=i;
			my=miny;
			dfs(0,0,0);
		}
		cout<<C<<endl;
		unordered_set<block,myHash>::iterator it;
		for(it=vis.begin();it!=vis.end();it++){
			block b=*it;
//			pblock(b);
		}
	}
}
