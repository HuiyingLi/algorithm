#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
class Solution {
public: 
    int vis[1000][1000];
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    vector<pair<int, int> > pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int> >ans;
        if(matrix.size()==0) return ans;
        memset(vis,0,sizeof(vis));
        int m=matrix.size(),n=matrix[0].size();
        queue<pair<int,int> >q;
        for(int i=0;i<n;i++)
            q.push(pair<int,int>(0,i)),vis[0][i]=1;
        for(int i=1;i<m;i++)
            q.push(pair<int,int>(i,0)),vis[i][0]=1;
        while(!q.empty()){
            pair<int,int> tp=q.front();
            q.pop();
            int x=tp.first, y=tp.second;
            //cout<<x<<" "<<y<<endl;
            for(int i=0;i<4;i++){
                pair<int,int> p(x+dir[i][0],y+dir[i][1]);
                if(p.first<0||p.second<0||p.first>=m||p.second>=n) continue;
                if(!vis[p.first][p.second] && matrix[p.first][p.second]>=matrix[x][y]){
                    q.push(p);
                    vis[p.first][p.second]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            pair<int,int> p(m-1,i);
            if(vis[m-1][i]==1)
                ans.push_back(p);
            q.push(p);
            vis[m-1][i]=3;
        }
        for(int i=0;i<m;i++){
            pair<int,int> p(i,n-1);
            if(vis[i][n-1]==1)
                ans.push_back(p);
            q.push(p);
            vis[i][n-1]=3;
        }
        while(!q.empty()){
            pair<int,int> tp=q.front();
            q.pop();
            int x=tp.first, y=tp.second;
            for(int i=0;i<4;i++){
                pair<int,int> p(x+dir[i][0],y+dir[i][1]);
                if(p.first<0||p.second<0||p.first>=m||p.second>=n) continue;
                if(matrix[p.first][p.second]>=matrix[x][y]){
                    int b=vis[p.first][p.second];
                    if(b==1){
                        ans.push_back(p);
                        vis[p.first][p.second]=3;
                        q.push(p);
                    }else if(b==0){
                        q.push(p);
                        vis[p.first][p.second]=2;
                    }
                }
            }
        }
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
	vector<vector<int> > m;
	int a1[5]={1,2,2,3,5};
	int a2[5]={3,2,3,4,4};
	int a3[5]={2,4,5,3,1};
	int a4[5]={6,7,1,4,5};
	int a5[5]={5,1,1,2,4};
	vector<int> v1(a1, a1+5);
	vector<int> v2(a2, a2+5);
	vector<int> v3(a3, a3+5);
	vector<int> v4(a4, a4+5);
	vector<int> v5(a5, a5+5);
	m.push_back(v1);
	m.push_back(v2);
	m.push_back(v3);
	m.push_back(v4);
	m.push_back(v5);
	Solution s;
	s.pacificAtlantic(m);
	return 0;
}
