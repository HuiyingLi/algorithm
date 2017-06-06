#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;

class Solution{
public:
	vector<vector<int> > mt;
	int m,n;
	int ans;
	int dp[110][110];
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
		m=obstacleGrid[0].size();
		n=obstacleGrid.size();
		mt=obstacleGrid;
		if(mt[n-1][m-1]==1)
			return 0;
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==0&&j==0){
					if(!obstacleGrid[i][j])
						dp[i+1][j+1]=1;
				}
				else if(!obstacleGrid[i][j]){
					dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j];
				}
			}
		}
		return dp[n][m];
	}
};

int main(){
	Solution s;
	string line;
	ifstream in;
	in.open("testgen_lc63.in");
	while(getline(in,line)){
		vector<vector<int> >grid;
		vector<int> r;
		line=line.substr(1,line.length()-2);
		for(int i=0;i<line.length();i++){
			if(line[i]==']'){
				grid.push_back(r);
				r.clear();
			}else if(line[i]=='0'||line[i]=='1'){
				r.push_back(line[i]-'0');
			}
		}
		cout<<s.uniquePathsWithObstacles(grid)<<endl;
	}
	return 0;
}
