#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

struct point{
	int x;
	int y;
	point(int a, int b):x(a),y(b){}
};
class Solution {
public:
	int m,n;
	int vis[390][390];
	vector<vector<char> > b;
	/**
	void dfs(int x, int y){
		if(x>0&&!vis[x-1][y]&&b[x-1][y]=='O'){
			vis[x-1][y]=1;
			dfs(x-1,y);
		}
		if(y<m-1&&!vis[x][y+1]&&b[x][y+1]=='O'){
			vis[x][y+1]=1;
			dfs(x,y+1);
		}
		if(x<n-1&&!vis[x+1][y]&&b[x+1][y]=='O'){
			vis[x+1][y]=1;
			dfs(x+1,y);
		}
		if(y>0&&!vis[x][y-1]&&b[x][y-1]=='O'){
			vis[x][y-1]=1;
			dfs(x,y-1);
		}
		
	}
	*/
	void bfs(int a, int c){
		queue<point> q;
		q.push(point(a,c));
		while(!q.empty()){
			point p=q.front();
			q.pop();
			int x=p.x;
			int y=p.y;
			if(x>0&&!vis[x-1][y]&& b[x-1][y]=='O'){
				vis[x-1][y]=1;
				q.push(point(x-1,y));
			}
			if(y<m-1&&!vis[x][y+1]&& b[x][y+1]=='O'){
				vis[x][y+1]=1;
				q.push(point(x,y+1));
			}
			if(x<n-1&&!vis[x+1][y]&& b[x+1][y]=='O'){
				vis[x+1][y]=1;
				q.push(point(x+1,y));
			}
			if(y>0&&!vis[x][y-1]&& b[x][y-1]=='O'){
				vis[x][y-1]=1;
				q.push(point(x,y-1));
			}
		}
	}
    void solve(vector<vector<char> >& board) {
		if(board.size()<=2)
			return;
		b=board;
		memset(vis,0,sizeof(vis));
		m=board[0].size();
		n=board.size();

		for(int j=0;j<m;j++){
			if(board[0][j]=='O'&&!vis[0][j]){
				vis[0][j]=1;
				bfs(0,j);
			}
		}
		for(int j=0;j<m;j++){
			if(board[n-1][j]=='O'&&!vis[n-1][j]){
				vis[n-1][j]=1;
				bfs(n-1,j);
			}
		}
		for(int i=0;i<n;i++){
			if(board[i][0]=='O'&&!vis[i][0]){
				vis[i][0]=1;
				bfs(i,0);
			}
		}
		for(int i=0;i<n;i++){
			if(board[i][m-1]=='O'&&!vis[i][m-1]){
				vis[i][m-1]=1;
				bfs(i,m-1);
			}
		}
		for(int i=1;i<n-1;i++){
			for(int j=1;j<m-1;j++){
				if(board[i][j]=='O'&&!vis[i][j])
					board[i][j]='X';
			}
		}
		
    }

};

int main(){return 0;}
