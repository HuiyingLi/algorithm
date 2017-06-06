#include<iostream>
#include<sstream>
#include<unordered_set>
#include<string.h>
#include<stdio.h>
using namespace std;

int G[7][8];
int M[7][8];
int vis[7][8];
int C=0;
int mx;
int my;
class pip{
	public:
	int a;
	int b;
	int id;
	pip(int aa,int bb, int iid){
		if(aa<bb){
			a=aa;
			b=bb;
		}else{
			a=bb;
			b=aa;
		}
		id=iid;
	}
	pip(int aa,int bb){
		if(aa<bb){
			a=aa;
			b=bb;
		}else{
			a=bb;
			b=aa;
		}
	}
	bool operator == (pip const& p) const{
		if(a==p.a&&b==p.b)
			return	true;
		return false;
	}
};

class myHash{
	public:
	size_t operator()(const pip &p) const{
		return 10*p.a+p.b;
	}
};

unordered_set<pip, myHash> bones;

void init(){
	int id=1;
	for(int i=0;i<=6;i++){
		for(int j=i;j<=6;j++){
			pip p(i,j,id);
			id++;
			bones.insert(p);
		}
	}
}

void print(int M[7][8]){
	for(int i=0;i<7;i++){
		for(int j=0;j<8;j++){
			printf("%4d",M[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}

void dfs(int d){
	if(d==28){
		if(bones.empty()){
			print(M);
			C++;	
		}
		return;
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<8;j++){
			if(!vis[i][j]){
				//first horizontal
				if(j+1<8&&!vis[i][j+1]){
					pip p(G[i][j],G[i][j+1]);
					unordered_set<pip,myHash>::iterator it=bones.find(p);
					if(it!=bones.end()){
						p.id=(*it).id;
						bones.erase(p);
						vis[i][j]=1;
						vis[i][j+1]=1;
						M[i][j]=p.id;
						M[i][j+1]=p.id;
						dfs(d+1);
						vis[i][j]=0;
						vis[i][j+1]=0;
						bones.insert(p);
					}
				}
				//then vertical
				if(i+1<7&&!vis[i+1][j]){
					pip p(G[i][j],G[i+1][j]);
					unordered_set<pip,myHash>::iterator it=bones.find(p);
					if(it!=bones.end()){
						p.id=(*it).id;
						bones.erase(p);
						vis[i][j]=1;
						vis[i+1][j]=1;
						M[i][j]=p.id;
						M[i+1][j]=p.id;
						dfs(d+1);
						vis[i][j]=0;
						vis[i+1][j]=0;
						bones.insert(p);
					}
				}
				return;
			}
		}
	}	
}
int main(){
	string line;
	int i=0;
	while(getline(cin, line)){
		stringstream ss(line);
		for(int j=0;j<8;j++){
			ss>>G[i%7][j];
		}
		if(i%7==6){
			C=0;
			memset(M,0,sizeof(M));
			memset(vis,0,sizeof(vis));
			bones.clear();
			init();
			if(i/7!=0)
				cout<<"\n\n\n";
			cout<<"Layout #"<<i/7+1<<":\n\n";
			print(G);
			cout<<"Maps resulting from layout #"<<i/7+1<<" are:\n\n";
			dfs(0);
			cout<<"There are "<<C<<" solution(s) for layout #"<<i/7+1<<".\n";
		}
		i++;
	}
}
