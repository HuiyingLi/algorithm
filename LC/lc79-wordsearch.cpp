#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<fstream>
using namespace std;

class Solution {
public:
	int m, n;
	string tgt;
	int vis[1000][1000];
	vector<vector<char> >board;
	bool dfs(int x, int y, int d){
		if(d>=tgt.length()-1)
			return true;
		if(x>0&&!vis[x-1][y]&&board[x-1][y]==tgt.at(d+1)){
			vis[x-1][y]=1;
			if(dfs(x-1,y, d+1))
				return true;
			vis[x-1][y]=0;
		}
		if(y<m-1&&board[x][y+1]==tgt.at(d+1)&&!vis[x][y+1]){
			vis[x][y+1]=1;
			if(dfs(x,y+1,d+1))
				return true;
			vis[x][y+1]=0;
		}
		if(x<n-1&&board[x+1][y]==tgt.at(d+1)&&!vis[x+1][y]){
			vis[x+1][y]=1;
			if(dfs(x+1,y, d+1))
				return true;
			vis[x+1][y]=0;
		}
		if(y>0&&board[x][y-1]==tgt.at(d+1)&&!vis[x][y-1]){
			vis[x][y-1]=1;
			if(dfs(x,y-1,d+1))
				return true;
			vis[x][y-1]=0;
		}
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
		if(board.size()==0)
			return false;
		if(word.length()==0)
			return false;
		this->board=board;
		n=board.size();
		m=board[0].size();
		if(word.length()>m*n)
			return false;
		tgt=word;
		memset(vis,0,sizeof(vis));
		bool ans=false;
		for(int i=0; i<n;i++){
			for(int j=0;j<m;j++){
				if(!vis[i][j]&&board[i][j]==word.at(0)){
					vis[i][j]=1;
					if(dfs(i,j,0))
						return true;
					//memset(vis,0,sizeof(vis));
					for(int g=0;g<n;g++)
						for(int h=0;h<m;h++)
							vis[g][h]=0;
				}
			}
		}
		return false;
    }
};

int main(){
	vector<char> a;
	a.push_back('A');
	a.push_back('B');
	a.push_back('C');
	a.push_back('E');
	vector<char> a2;
	a2.push_back('S');
	a2.push_back('F');
	a2.push_back('E');
	a2.push_back('S');
	vector<char> a3;
	a3.push_back('A');
	a3.push_back('D');
	a3.push_back('E');
	a3.push_back('E');
	vector<vector<char> > b;
	b.push_back(a);
	b.push_back(a2);
	b.push_back(a3);
	fstream f;
	f.open("testgen_lc79.in");
	string line;
	int i=0;
	Solution s;
	vector<vector<char> >inp;
	while(getline(f,line)){
		string inps;
		if(i%2==0){
			vector<char> cv;
			for(int k=0;k<line.length();k++){
				if(line.at(k)<='9'&&line.at(k)>='0')
					cv.push_back(line.at(k));
				if(line.at(k)==','){
					inp.push_back(cv);
					cv.clear();
				}
			}
		}else{
			inps=line.substr(1,line.length()-2);
			cout<<s.exist(inp, inps)<<endl;
			inp.clear();
		}
		i++;
	}
//	Solution s;
//	cout<<s.exist(b,"ABCESEEEFS");

	return 0;}
