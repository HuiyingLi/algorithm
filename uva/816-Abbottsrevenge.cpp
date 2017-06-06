#include<iostream>
#include<sstream>
#include<vector>
#include<stdlib.h>
using namespace std;

int f[11][11][4];

int ctoi(char dir){
	switch (dir){
		case 'N':
			return 0;
		case 'S':
			return 1;
		case 'E':
			return 2;
		case 'W':
			return 3;
	}
}
class Node{
	public:
	int r;
	int c;
	char enterthru;
	string direct[4];//for NSEW each
	Node():r(-1),c(-1),enterthru(0){}
};

Node dm[11][11];
Node parent[11][11][4];

int bfs(Node start, Node end){
	vector<Node> q;
	Node inter;
	switch(start.enterthru){
		case 'N':
			if(start.r>1){
				inter=dm[start.r-1][start.c];
			}
			break;
		case 'S':
			if(start.r<10) inter=dm[start.r+1][start.c];
			break;
		case 'E':
			if(start.c<10) inter=dm[start.r][start.c+1];
			break;
		case 'W':
			if(start.c>1) inter=dm[start.r][start.c-1];
			break;
	}
	if(inter.r==-1 ||inter.c==-1){//nowhere to go
		cout<<"  No Solution Possible"<<endl;	
		return 0;
	}
	inter.enterthru=start.enterthru;
	//parent[inter.r][inter.c][ctoi(inter.enterthru)]=start;
	
	q.push_back(inter);
	bool found=false;
	Node fin;
	while(q.size()>0){
		vector<Node>nq;
		for(vector<Node>::iterator iter=q.begin();iter!=q.end(); ++iter){
			Node n=*iter;
			if(n.r==end.r&&n.c==end.c){
				found=true;
				fin=n;
				break;
			}
			//mark as visited
			switch(n.enterthru){
				case 'N':
					f[n.r][n.c][0]=1;
					break;
				case 'S':
					f[n.r][n.c][1]=1;
					break;
				case 'E':
					f[n.r][n.c][2]=1;
					break;
				case 'W':
					f[n.r][n.c][3]=1;
					break;
			}
			
			//find the connections
			int i;
			string dir;
			switch (n.enterthru){
				case 'N': dir=dm[n.r][n.c].direct[0];
					break;
				case 'S': dir=dm[n.r][n.c].direct[1];
					break;
				case 'E': dir=dm[n.r][n.c].direct[2];
					break;
				case 'W': dir=dm[n.r][n.c].direct[3];
					break;
			}
			for(i=0;i<dir.length();i++){
				Node next;
				if(dir[i]=='L'){//left intersection
					switch(n.enterthru){
						case 'N'://going to west
							if(n.c>1&&f[n.r][n.c-1][3]!=1){
								next.r=n.r;
								next.c=n.c-1;
								next.enterthru='W';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'S'://going to east
							if(n.c<10 && f[n.r][n.c+1][2]!=1){
								next.r=n.r;
								next.c=n.c+1;
								next.enterthru='E';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
						}
							break;
						case 'E'://going to north
							if(n.r>1 && f[n.r-1][n.c][0]!=1){
								next.r=n.r-1;
								next.c=n.c;
								next.enterthru='N';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'W'://going to south
							if(n.r<10 && f[n.r+1][n.c][1]!=1){
								next.r=n.r+1;
								next.c=n.c;
								next.enterthru='S';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);

							} 
							break;
					}
				}else if(dir[i]=='F'){
					next.enterthru=n.enterthru;
					switch(n.enterthru){
						case 'N':
							if(n.r>1 && f[n.r-1][n.c][0]!=1){
								next.r=n.r-1;
								next.c=n.c;
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'S':
							if(n.r<10 && f[n.r+1][n.c][1]!=1){
								next.r=n.r+1;
								next.c=n.c;
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'E':
							if(n.c<10 && f[n.r][n.c+1][2]!=1){
								next.r=n.r;
								next.c=n.c+1;
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'W':
							if(n.c>1 && f[n.r][n.c-1][3]!=1){
								next.r=n.r;
								next.c=n.c-1;
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
					}
				}else if(dir[i]=='R'){
					switch(n.enterthru){
						case 'N'://going to east
							if(n.c<10 && f[n.r][n.c+1][2]!=1){
								next.r=n.r;
								next.c=n.c+1;
								next.enterthru='E';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'S'://going to west
							if(n.c>1 && f[n.r][n.c-1][3]!=1){
								next.r=n.r;
								next.c=n.c-1;
								next.enterthru='W';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'E'://going to south
							if(n.r<10 && f[n.r+1][n.c][1]!=1){
								next.r=n.r+1;
								next.c=n.c;
								next.enterthru='S';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
						case 'W'://going tp north
							if(n.r>1&&f[n.r-1][n.c][0]!=1){
								next.r=n.r-1;
								next.c=n.c;
								next.enterthru='N';
								parent[next.r][next.c][ctoi(next.enterthru)]=n;
								nq.push_back(next);
							}
							break;
					}
				}
			}
		}
		if(found)
		{
			Node p=fin;
			int c=1;
			vector<Node> res;
			while(p.r!=-1&&p.c!=-1){
				res.insert(res.begin(),p);
				p=parent[p.r][p.c][ctoi(p.enterthru)];
			}
			cout<<"  ("<<start.r<<","<<start.c<<")";
			for(vector<Node>::iterator iter=res.begin();iter!=res.end();iter++){
				Node q=*iter;
				if(c%10==0&&c!=0){
					cout<<endl;
					if(c!=res.size())
						cout<<" ";
				}
				cout<<" ("<<q.r<<","<<q.c<<")";
				c++;
			}
//			if(c%10!=0)
				cout<<endl;
			break;
		}
/**
		int t;
		for(t=0;t<nq.size();t++){
			cout<<nq[t].r<<" "<<nq[t].c<<"\t";
			if(nq[t].r==2&&nq[t].c==3){
				cout<<"FOUND"<<endl;
			}
		}	
		cout<<endl;
**/
		q=nq;	
	}
	if(!found)
		cout<<"  No Solution Possible"<<endl;
	return 0;
}

int main(){
	string mname;
	getline(cin,mname);
	string line;
	int sr, sc, er, ec;
	char sd;
	Node start, end;
	while(mname!="END"){
		getline(cin, line);
		sr=atoi(line.substr(0,1).c_str());
		sc=atoi(line.substr(2,1).c_str());
		sd=line[4];
		er=atoi(line.substr(6,1).c_str());
		ec=atoi(line.substr(8,1).c_str());
		start.r=sr;
		start.c=sc;
		start.enterthru=sd;
		end.r=er;
		end.c=ec;
		while(true){
			getline(cin,line);
			if(line=="0")
				break;
			Node n;
			n.r=atoi(line.substr(0,1).c_str());
			n.c=atoi(line.substr(2,1).c_str());
			line=line.substr(4,line.length()-5);
			int c;
			while((c=line.find(" "))!=-1){
				string s=line.substr(0,c);
				line=line.substr(c+1,line.length()-c);
				switch (s[0]){
					case 'N':
						n.direct[0]=s.substr(1,s.length()-1);
						break;
					case 'S':
						n.direct[1]=s.substr(1,s.length()-1);
						break;
					case 'E':
						n.direct[2]=s.substr(1,s.length()-1);
						break;
					case 'W':
						n.direct[3]=s.substr(1,s.length()-1);
						break;
				}
			}
			dm[n.r][n.c]=n;
		}
		cout<<mname<<endl;
		bfs(start, end);
		getline(cin,mname);
		//reinitialize maze and flag
		int i,j,k;
		for(i=0;i<11; i++){
			for(j=0;j<11;j++){
				dm[i][j].r=-1;
				dm[i][j].c=-1;
				
				for(k=0;k<4;k++){
					f[i][j][k]=0;
					parent[i][j][k].r=-1;
					parent[i][j][k].c=-1;
					parent[i][j][k].enterthru=0;
					dm[i][j].direct[k]="";
				}
			}
		}
	}
}
