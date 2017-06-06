#include<iostream>
#include<vector>
using namespace std;
class point{
	public:
	int x;
	int y;
	bool islegit(int deltax, int deltay){
		if(x+deltax>=0 && x+deltax<8 && y+deltay>=0 &&y+deltay<8)
			return true;
		return false;
	}
	point newmove(int deltax, int deltay){
		point p;
		p.x=this->x+deltax;
		p.y=this->y+deltay;
		return p;
	}
	bool eq(point p){
		if(this->x==p.x &&this->y==p.y)
			return true;
		return false;
	}
	void print(){
		cout<<this->x<<" "<<this->y<<endl;
	}
};

vector<point> getallmoves(point p){
	vector<point> res;
	if(p.islegit(1,2))
		res.push_back(p.newmove(1,2));
	if(p.islegit(1,-2))
	res.push_back(p.newmove(1,-2));
	if(p.islegit(-1,2))
		res.push_back(p.newmove(-1,2));
	if(p.islegit(-1,-2))
		res.push_back(p.newmove(-1,-2));
	if(p.islegit(2,1))
		res.push_back(p.newmove(2,1));
	if(p.islegit(2,-1))
		res.push_back(p.newmove(2,-1));
	if(p.islegit(-2,-1))
		res.push_back(p.newmove(-2,-1));
	if(p.islegit(-2,1))
		res.push_back(p.newmove(-2,1));
	return res;
}
int bfs(point s, point e){
	vector<point> q;
	q.push_back(s);
	int C=0;
	while(q.size()>0){
		vector<point> nq;
		for(int i=0;i<q.size();i++){
			if(e.eq(q[i])){
				return C;
			}
			vector<point> nexts=getallmoves(q[i]);
			nq.insert(nq.end(),nexts.begin(),nexts.end());
		}
		q=nq;
		C++;
	}
}

int main(){
	string line;
	while(getline(cin,line)){
		point s, e;
		s.x=line[0]-'a';
		s.y=line[1]-'1';
		e.x=line[3]-'a';
		e.y=line[4]-'1';
		cout<<"To get from "<<line.substr(0,2)<<" to "<<line.substr(3,2)<<" takes "<<bfs(s,e)<<" knight moves."<<endl;	
	}	
}
