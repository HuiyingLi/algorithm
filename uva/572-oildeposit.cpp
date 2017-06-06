#include<iostream>
#include<sstream>
	
using namespace std;
char g[101][101];
int f[101][101];
int m,n;
void dfs(int r, int c){
	f[r][c]=1;
	if(r>0){//up
		if(f[r-1][c]!=1&&g[r-1][c]=='@') dfs(r-1, c);
	}
	if(r>0&&c<n-1){//upperright
		if(f[r-1][c+1]!=1&&g[r-1][c+1]=='@') dfs(r-1,c+1);
	}
	if(c<n-1){//right
		if(f[r][c+1]!=1&&g[r][c+1]=='@') dfs(r,c+1);
	}
	if(c<n-1&&r<m-1){//lowerright
		if(f[r+1][c+1]!=1&&g[r+1][c+1]=='@') dfs(r+1,c+1);
	}
	if(r<m-1){//down
		if(f[r+1][c]!=1&&g[r+1][c]=='@') dfs(r+1,c);
	}
	if(r<m-1&&c>0){//lower left
		if(f[r+1][c-1]!=1&&g[r+1][c-1]=='@') dfs(r+1, c-1);
	}
	if(c>0){//left
		if(f[r][c-1]!=1&&g[r][c-1]=='@')dfs(r,c-1);
	}
	if(c>0&&r>0){//upper left
		if(f[r-1][c-1]!=1&&g[r-1][c-1]=='@') dfs(r-1,c-1);
	}
}

int main(){
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		ss>>m;
		ss>>n;
		if(m==0){
			break;
		}
		int k,j;
		for(k=0;k<m;k++){
			getline(cin,line);
			for(j=0;j<line.length();j++){
				g[k][j]=line.at(j);
			}
		}
		//done reading.
		int total=0;
		for(k=0;k<m;k++){
			for(j=0;j<n;j++){
				if(f[k][j]!=1&&g[k][j]=='@'){
					dfs(k,j);
					total++;
				}
			}
		}
		cout<<total<<endl;
		for(k=0;k<101;k++){
			for(j=0;j<101;j++){
				g[k][j]=0;
				f[k][j]=0;
			}
		}
	}
}
