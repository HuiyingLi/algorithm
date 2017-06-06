#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
		int d=0;
		int c=0;
		vector<int> res;
		if(matrix.size()==0)
			return res;
		int m=matrix.size();
		int n=matrix[0].size();
		int l=m<n?m:n;
		while(d<l/2){
			for(int i=d;i<=n-2-d;i++){
				res.push_back(matrix[d][i]);
			}
			if(res.size()==m*n)
				break;
			for(int i=d;i<=m-2-d;i++){
				res.push_back(matrix[i][n-d-1]);
			}
			if(res.size()==m*n)
				break;
			for(int i=n-d-1; i>=d+1; i--){
				res.push_back(matrix[m-1-d][i]);
			}
			if(res.size()==m*n)
				break;
			for(int i=m-1-d; i>=d+1;i--){
				res.push_back(matrix[i][d]);
			}
			if(res.size()==m*n)
				break;
			d++;
		}
		if(res.size()!=m*n){
			int diff=m*n-res.size();
			if(m<=n){
				for(int i=0;i<diff;i++)
					res.push_back(matrix[d][d+i]);
			}else{
				for(int i=0;i<diff;i++)
					res.push_back(matrix[d+i][d]);
			}
		}
		return res;
    }
};
int main(){
return 0;}
