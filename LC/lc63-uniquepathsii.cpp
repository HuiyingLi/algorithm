#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Solution {

public:
	vector<vector<int> > mt;
	int m, n;
	int ans;
	void dfs(int x, int y){
		if(x==m-1&&y==n-1&&!mt[y][x]){
			ans++;
			return;
		}
		if(!mt[y][x]){
			if(x+1<m)
				dfs(x+1,y);
			if(y+1<n)
				dfs(x,y+1);
		}
	}
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		mt=obstacleGrid;
		ans=0;
		m=mt[0].size();
		n=mt.size();
		if(mt[n-1][m-1]==1)
			return 0;
		dfs(0,0);
		return ans;
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
