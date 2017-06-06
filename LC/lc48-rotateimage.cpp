#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
		int len=matrix.size();
		int l=len;
		while(l>1){
			int d=len-l;
			for(int i=d;i<d+l;i++){
				int t=matrix[d][i];
				matrix[d][i]=matrix[l-i-1][d];
			}
		}
    }
};
int main(){
	
	return 0;}
