#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& m) {
		vector<int> dp;
		int max=0;
		if(m.size()==0) return 0;
		if(m[0].size()==0) return 0;
		int limit=m.size()>m[0].size()?m.size():m[0].size();
		for(int i=0;i<m.size();i++){
			vector<int> v;
			for(int j=0;j<m[0].size();j++){
				if(i==0||j==0){
					if(m[i][j]=='0')
						v.push_back(0);
					else{
						v.push_back(1);
						if(max<1)
							max=1;
					}
					continue;
				}
				if(m[i][j]=='0'){
					v.push_back(0);
					continue;
				}
				int min=dp[j];
				if(v[j-1]<min)
					min=v[j-1];
				if(dp[j-1]<min)
					min=dp[j-1];
				v.push_back(min+1);
				if(min+1>max){
					max=min+1;
					if(max==limit)
					    return max*max;
				}
			}
			dp=v;
		}
		return max*max;
    }
};

int main(){return 0;}
