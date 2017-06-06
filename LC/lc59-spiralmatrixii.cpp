#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > res;
		if(n==0) return res;
		if(n==1){
			vector<int> v={1};
			res.push_back(v);
			return res;
		}
		for(int i=0;i<n;i++){
			vector<int>v;
			for(int j=0;j<n;j++)
				v.push_back(0);
			res.push_back(v);
		}
		int k=1;
		int d=0;
		while(d<n/2){
			for(int i=d;i<=n-2-d;i++){
				res[d][i]=k;
				k++;
			}
			if(k==n*n)
				break;
			for(int i=d;i<=n-2-d;i++){
				res[i][n-d-1]=k;
				k++;
			}
			if(k==n*n)
				break;
			for(int i=n-d-1; i>=d+1; i--){
				res[n-1-d][i]=k;
				k++;
			}
			if(k==n*n)
				break;
			for(int i=n-1-d; i>=d+1;i--){
				res[i][d]=k;
				k++;
			}
			if(k==n*n)
				break;
			d++;
		}
		if(n%2==1){
			res[d+1][d+1]=n*n;
		}else{
			res[d+1][d]=n*n;
		}
		return res;
    }
};
int main(){return 0;}
