#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {

public:
	vector<string> res;
	string s;
	string ans;
	void dfs(int p, int d){
		if(d==4){
			if(p==s.length()){
				res.push_back(ans.substr(0,ans.length()-1));
				return ;	
			}
		}
		for(int i=1;i<=3;i++){
			if(p+i>s.length())
				break;
			string ss=s.substr(p,i);
			if(atoi(ss.c_str())<256){
				if(i>1&&ss[0]=='0')
					continue;
				string t=ans;
				ans+=ss+'.';
				dfs(p+i,d+1);
				ans=t;
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
		ans="";
		res.clear();
		this->s=s;
		dfs(0,0);
		return res;
    }
};
int main(){
	string in="0000";
	Solution s;
	s.restoreIpAddresses(in);
	
	return 0;}
