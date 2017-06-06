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
int Cnt=0;
int mx, my, minx,miny;

class block{
	public:
	int w;
	int h;
	int miny;
	int shape[10][10];
	block(int ww, int hh, int mminy){
		this->w=ww;
		this->h=hh;
		this->miny=mminy;
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

unordered_set<block, myHash> vis[11];

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
	block nb(ori.w,ori.h, ori.miny);
	for(int i=ori.h; i>=0;i--){
		for(int j=0;j<=ori.w;j++){
			nb.shape[ori.h-i][j]=ori.shape[i][j];
		}
	}
	return nb;
}
block makelr(block ori){
	block nb(ori.w,ori.h, ori.miny);
	for(int i=0;i<=ori.h;i++){
		for(int j=ori.w;j>=0;j--){
			nb.shape[i][ori.w-j]=ori.shape[i][j];
		}
	}
	return nb;
}

bool visit(block ori, int l){
	if(vis[l].find(ori)==vis[l].end()){
		//if it goes 90 degree
		if(ori.h<W&&ori.w<H){
			block bf(ori.h,ori.w, ori.miny);
			for(int i=0;i<=ori.h;i++){
				for(int j=0;j<=ori.w;j++){
					bf.shape[j][i]=ori.shape[i][j];	
				}
			}
			vis[l].insert(bf);
			block bf1=makelr(bf);
			vis[l].insert(bf1);
			vis[l].insert(makeud(bf));
			vis[l].insert(makeud(bf1));
		}
		block b1=makelr(ori);
		vis[l].insert(ori);
		vis[l].insert(b1);
		vis[l].insert(makeud(ori));
		vis[l].insert(makeud(b1));
		return false;
	}
	return true;
}

void generate(){
	for(int d=1;d<N;d++){
		for(unordered_set<block,myHash>::iterator it=vis[d].begin();it!=vis[d].end();it++){
			block b=*it;
			for(int i=0;i<=b.h;i++){
				for(int j=0;j<=b.w;j++){
					if(b.shape[i][j]){
						for(int k=0;k<4;k++){
							int nx=i+dir[k][0];
							int ny=j+dir[k][1];
							if(nx>=0&&ny>=0&&nx<H&&ny<W&&!b.shape[nx][ny]){
								block bn(b.w, b.h, b.miny);
								memcpy(bn.shape, b.shape, sizeof(b.shape));
								bn.shape[nx][ny]=1;
								if(nx>bn.h) bn.h=nx;
								if(ny>bn.w) bn.w=ny;
								if(ny<bn.miny) bn.miny=ny;
								if(d==N-1){
									if(bn.miny!=0) 
										continue;
									if(!visit(bn,d+1))
										C++;
								}else{
									vis[d+1].insert(bn);
								}
							}
						}
					}
				}
			}
		}
	}
}
/*
void dfs(int d, int x, int y){
	if(d==N){
//		if(map[0][1]&&map[1][0]==1&&map[1][1]&&map[1][2]==1&&map[2][1]==1)
//			cout<<" ";
		if(miny!=0)
			return;
		block b(my,mx);
		memcpy(b.shape, map, sizeof(map));
//		pblock(b);
//		if(map[0][0]==1&&map[1][0]==1&&map[2][0]==1&&map[2][1]==1&&map[3][1]==1)
//			cout<<" ";
		Cnt++;
		if(!visit(b, d)){
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
						block bn(my,mx);
						memcpy(bn.shape,map,sizeof(map));
//						if(!visit(bn,d)){
							dfs(d+1,nx,ny);
//							vis[d].erase(bn);
//						}
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
*/
int main(){
	string line;
	while(getline(cin, line)){
		stringstream ss(line);
		ss>>N>>W>>H;
		for(int i=0;i<11;i++)
			vis[i].clear();
		memset(map,0,sizeof(map));
		C=0;
		Cnt=0;
	//	map[0][0]=1;
		for(int i=0;i<W/2+1;i++){
//			if(i==1) 
//				cout<<endl;
			memset(map,0,sizeof(map));
			map[0][i]=1;
			miny=i;
			my=miny;
			block start(my,mx,i);
			memcpy(start.shape, map, sizeof(map));
			vis[1].insert(start);
			if(N<=1){
				C++;
				continue;
			}
	//		dfs(1,0,0);
			generate();
			vis[1].clear();
		}
		unordered_set<block,myHash>::iterator it;
//		for(it=vis[N].begin();it!=vis[N].end();it++){
//			block b=*it;
//			pblock(b);
//		}
		cout<<C<<endl;
	}
}
