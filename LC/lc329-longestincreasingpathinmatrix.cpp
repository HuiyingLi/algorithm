#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
class Solution {
public:
    int dp[1000][1000];
    int l;
    int ml;
    vector<vector<int> >mm;
    int dir[8]={0,-1,-1,0,0,1,1,0};
    int dfs(int i, int j){
        if(dp[i][j]>0)
            return dp[i][j];
        int ret=1;
        for(int k=0;k<4;k++){
            int ni=i+dir[k*2];
            int nj=j+dir[k*2+1];
            if(ni>=mm.size()||nj>=mm[0].size()||ni<0||nj<0) continue;
            if(mm[ni][nj]>mm[i][j]){
                
                int v=dfs(ni,nj);
                ret=max(ret,v+1);
            }
        }
        dp[i][j]=ret;
        
        return ret;
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        this->mm=matrix;
		ml=0;
        if(matrix.size()==0) return 0;
        memset(dp,0,sizeof(dp));
        cout<<matrix[0].size()<<endl;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dp[i][j]==0){
                    int v=dfs(i,j);
                    //cout<<v<<endl;
                    if(v>ml)
                        ml=v;
                }
            }
        }/*
        for(int i=0;i<mm.size();i++){
            for(int j=0;j<mm[0].size();j++)
                cout<<mm[i][j]<<" ";
            cout<<endl;
        }*/
        return ml;
    }
};


int main(){
	int arr[7]={9,44,1,8,12,0,9};
	int arr2[3]={3,2,6};
	int arr3[3]={2,2,1};
	vector<int> v1(arr,arr+7);
	vector<int> v2(arr2,arr2+3);
	vector<int> v3(arr3,arr3+3);
	vector<vector<int> >in;
	in.push_back(v1);
//	in.push_back(v2);
//	in.push_back(v3);
	Solution s;
	cout<<s.longestIncreasingPath(in);
	return 0;
}
