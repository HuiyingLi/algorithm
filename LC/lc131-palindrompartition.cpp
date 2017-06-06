#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	string s;
	vector<vector<string> >res;
	vector<string> ans;
	bool isp(int b, int e){
		if(e==b+1) return true;
		if(b==e) return false;
		int l=(e-b)/2;
		for(int k=0;k<l;k++){
			if(s[b+k]!=s[e-k-1])
				return false;
		}
		return true;
	}
	void dfs(int b, int e){
		if(b==s.length()){
			res.push_back(ans);
			return;
		}
		for(int i=b+1;i<=e;i++){
			if(isp(b,i)){
				ans.push_back(s.substr(b,i-b));
				dfs(i,e);
				ans.pop_back();
			}
		}
	}
	vector<vector<string> > partition(string s){
		this->s=s;
		res.clear();
		ans.clear();
		if(s.length()==0) return res;
		dfs(0,s.length());
		return res;
	}
};
int main(){return 0;}
