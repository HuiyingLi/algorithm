#include<iostream>
#include<vector>
#include<string.h>
#include<limits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
		if(grid.size()==0)
			return 0;
		int m=grid.size();
		int n=grid[0].size();
		if(n==0)
			return 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(i==0&&j==0) continue;
				if(i==0){
					grid[i][j]=grid[i][j-1]+grid[i][j];
					continue;
				}
				if(j==0){
					grid[i][j]=grid[i-1][j]+grid[i][j];
					continue;
				}
				grid[i][j]=(grid[i-1][j]<grid[i][j-1]?grid[i-1][j]:grid[i][j-1])+grid[i][j];
			}
		}
		return grid[m-1][n-1];
    }
};
int main(){return 0;}
