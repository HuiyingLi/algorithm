#include<iostream>
#include<sstream>
#include<vector>
#include<string.h>
using namespace std;

class node{
	public:
	string board[4];
	string move;
	node *prev;
	node():move(""){}
	node(string in, char m, node* n){
		toboard(in);
		this->move=""+m;
		this->prev=n;	
	}
	void toboard(string in){
		board[2]=in.substr(4,7);
		board[3]=in.substr(13,7);
		string s0="";string s1="";
		s0+=in[22];
		s0+=in[20];
		s0+=in[15];
		s0+=in[11];
		s0+=in[6];
		s0+=in[2];
		s0+=in[0];
		s1+=in[23];
		s1+=in[21];
		s1+=in[17];
		s1+=in[12];
		s1+=in[8];	
		s1+=in[3];
		s1+=in[1];
		board[0]=s0;
		board[1]=s1;
	}
};

char tgt;
node ans;
bool is_goal(node p){
	char target=p.board[0][3];
	for(int i=0;i<4;i++)
		for(int j=2;j<=4;j++){
			if(p.board[i][j]!=target)
				return false;
			}
	ans.move=p.move;
	tgt=target;
	return true;
}
	
node onemove(node p,char m){	
	node np;
	for(int i=0;i<4;i++)np.board[i]=p.board[i];
	switch (m){
		case 'A':
		np.board[0]=p.board[0][6]+p.board[0].substr(0,6);
		np.board[2][2]=np.board[0][4];
		np.board[3][2]=np.board[0][2];
		break;
		case 'B':
		np.board[1]=p.board[1][6]+p.board[1].substr(0,6);
		np.board[2][4]=np.board[1][4];
		np.board[3][4]=np.board[1][2];
		break;
		case 'C':
		np.board[2]=p.board[2][6]+p.board[2].substr(0,6);
		np.board[0][4]=np.board[2][2];
		np.board[1][4]=np.board[2][4];
		break;
		case 'D':
		np.board[3]=p.board[3][6]+p.board[3].substr(0,6);
		np.board[0][2]=np.board[3][2];
		np.board[1][2]=np.board[3][4];
		break;
		case 'E':
		np.board[1]=p.board[1].substr(1,6)+p.board[1][0];
		np.board[2][4]=np.board[1][4];
		np.board[3][4]=np.board[1][2];
		break;
		case 'F':
		np.board[0]=p.board[0].substr(1,6)+p.board[0][0];
		np.board[2][2]=np.board[0][4];
		np.board[3][2]=np.board[0][2];
		break;
		case 'G':
		np.board[3]=p.board[3].substr(1,6)+p.board[3][0];
		np.board[0][2]=np.board[3][2];
		np.board[1][2]=np.board[3][4];
		break;
		case 'H':
		np.board[2]=p.board[2].substr(1,6)+p.board[2][0];
		np.board[0][4]=np.board[2][2];
		np.board[1][4]=np.board[2][4];
		break;
	}
	return np;
}
bool dfs(node p, int d, int maxd){
	if(d==maxd){
		return is_goal(p);
	}
	//prune
	int vote[3]={0,0,0};
	int maxv=0;
	for(int i=0;i<4;i++)
		for(int j=2;j<=4;j++){
			if(i>=2&&(j==2||j==4))
				continue;
			int t=p.board[i][j]-'1';
			vote[t]++;
			if(vote[t]>maxv)
				maxv=vote[t];
		}
	if(d+(8-maxv)>maxd)
		return false;
	//expand
	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			char m=i*4+j+'A';
			node np=onemove(p,m);
			np.move=p.move+m;
			if(dfs(np, d+1, maxd))
				return true;
		}
	}
	return false;
}

int ida(node start){
	int bound=0;
	while(true){
		if(dfs(start, 0, bound)){
			if(bound==0)
				cout<<"No moves needed"<<endl;
			else
				cout<<ans.move<<endl;
			cout<<tgt<<endl;
			return bound;
		}
		bound++;
	}
}

int main(){
	string line;
	while(true){
		getline(cin, line);
		if(line=="0")
			break;
		string in="";
		for(int i=0;i<line.length();i+=2){
			in+=line[i];
		}
		node start(in, '\0', NULL);
		ida(start);
	}
	return 0;
}
