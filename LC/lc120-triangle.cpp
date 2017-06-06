#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& t) {
		if(t.size()==0) return 0;
		if(t.size()>1){
			for(int i=1;i<t.size();i++){
				for(int j=0;j<t[i].size();j++){
					if(j==0){
						t[i][j]+=t[i-1][j];
					}else if(j==t[i].size()-1){
						t[i][j]+=t[i-1][i-1];
					}else{
						t[i][j]+=t[i-1][j]<t[i-1][j-1]?t[i-1][j]:t[i-1][j-1];
					}
					
				}
			}
		}
		int ans=2147483647;
		for(int i=0;i<t[t.size()-1].size();i++){
			if(t[t.size()-1][i]<ans)
				ans=t[t.size()-1][i];
		}
		return ans;
    }

};
int main(){return 0;}
