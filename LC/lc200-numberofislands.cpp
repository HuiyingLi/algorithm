#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct coor{
	int x;
	int y;
	coor():x(-1),y(-1){}
	coor(int a, int b):x(a),y(b){}
};

class Solution {
public:
	vector<coor> G[500][500];
	int vis[500][500];
	int m,n;
	int ans;
	int dfs(int x, int y){
		int sum=1;
		for(int i=0; i<G[x][y].size(); i++){
			coor p=G[x][y][i];
			if(!vis[p.x][p.y]){
				vis[p.x][p.y]=1;
				sum+=dfs(p.x, p.y);
			}
		}
		return sum;
	}
    int numIslands(vector<vector<char> > & grid) {
		if(grid.size()==0)
			return 0;
		memset(vis,0, sizeof(vis));
		m=grid[0].size();
		n=grid.size();
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(grid[i][j]=='0')//if water, do nothing
					continue;
				//if land, find adjacent land;
				if(i>0&&grid[i-1][j]=='1')//up
						G[i][j].push_back(coor(i-1,j));
				if(j+1<m&&grid[i][j+1]=='1')//right
						G[i][j].push_back(coor(i,j+1));
				if(i+1<n&&grid[i+1][j]=='1')//down
					G[i][j].push_back(coor(i+1,j));
				if(j>0&&grid[i][j-1]=='1')//left
					G[i][j].push_back(coor(i,j-1));
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(grid[i][j]=='1'&&vis[i][j]==0){
					vis[i][j]=1;
					if(dfs(i,j)>0)
						ans++;
				}
			}
		}
		return ans;
    }
};

int main(){
	vector<vector<char> >g;
	vector<char> a;
	a.push_back('1');
	g.push_back(a);
	/*
	char arr[]={'1','0','0','0','0'};
	vector<char> a(arr, arr+sizeof(arr)/sizeof(arr[0]));
	char arr1[]={'0','1','0','0','0'}; 
	vector<char> a1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
	char arr2[]={'1','1','1','0','0'};
	vector<char> a2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
	char arr3[]={'0','0','0','1','1'};
	vector<char> a3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
	g.push_back(a);
	g.push_back(a1);
	g.push_back(a2);
	g.push_back(a3);
	*/
	Solution s;
	cout<<s.numIslands(g);
	return 0;
}

