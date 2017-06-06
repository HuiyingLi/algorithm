#include<iostream>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int W[3];
int vis[201][201];
int D;
int ans[201];

class Node{
	public:
	int w[3];
	int diff;
	int dist;
	Node(){
		dist=0;
		diff=0;
		for(int i=0;i<3;i++)w[i]=0;
	}
	void ts(){
		cout<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
	}
	bool operator < (const Node& n) const{
		return dist>n.dist;
	}
};

vector<Node> find_next_moves(Node n){
	vector<Node> moves;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=j&&n.w[i]!=0&&n.w[j]!=W[j]){
				Node k;
				//i->j empty i completely into j
				if(W[j]-n.w[j]>=n.w[i]){
					memcpy(k.w, n.w, sizeof(n.w));
					int diff=k.w[i];
					k.w[i]-=diff;
					k.w[j]+=diff;
					k.diff=diff;
					if(!vis[k.w[0]][k.w[1]])
						moves.push_back(k);
				}else{//i->j fill j
					Node kk;
					memcpy(kk.w, n.w, sizeof(n.w));
					int diff=W[j]-n.w[j]>n.w[i]?n.w[i]:W[j]-n.w[j];
					kk.w[j]+=diff;
					kk.w[i]-=diff;
					kk.diff=diff;
					if(!vis[kk.w[0]][kk.w[1]])
						moves.push_back(kk);
				}
				
			}
		}
	}
//	for(int i=0;i<moves.size();i++)
//		moves.at(i).ts();
	return moves;
}

/*
bool is_target(Node u){
	if(u.w[0]==D||u.w[1]==D||u.w[2]==D){
		return true;
	}
	return false;
}
*/

void update_ans(Node u){
	 
	for(int i=0;i<3;i++){
		int ind=u.w[i];
		if(ans[ind]<0||ans[ind]>u.dist){
			ans[ind]=u.dist;
		}
	}
}

void bfs(Node start){
	queue<Node> q;
	q.push(start);
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		update_ans(u);
		vector<Node> moves=find_next_moves(u);
		for(vector<Node>::iterator it1=moves.begin();it1!=moves.end();it1++){
			Node un=*it1;
			if(!vis[un.w[0]][un.w[1]]){
				un.dist=u.dist+un.diff;
				q.push(un);
				vis[un.w[0]][un.w[1]]=1;
			}
		}
	}
	while(D>=0){
		if(ans[D]>=0){
			cout<<ans[D]<<" "<<D<<endl;
			break;
		}
		D--;
	}
}

void init(){
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));

}
int main(){
	int T;
	string line;
	getline(cin,line);
	stringstream s0(line);
	s0>>T;
	for(int i=0;i<T;i++){
		getline(cin,line);
		stringstream ss(line);
		ss>>W[0];
		ss>>W[1];
		ss>>W[2];
		ss>>D;
		init();
		Node start;
		vis[0][0]=1;
		start.w[0]=0;
		start.w[1]=0;
		start.w[2]=W[2];
		bfs(start);
	}	
	return 0;
}
